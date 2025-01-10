#include "req.hpp"
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>

#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include <list>

void Request::seturl(const std::string& url) {
    this->url = url;
}

void Request::setpdata(const std::string& pdata) {
    this->pdata = pdata;
}

void Request::setheader(const std::string& header) {
    headers.push_back(header);
}

std::string Request::post() {
    std::string respon;
    if (pdata.empty()) {
        std::cerr << "Payload data cannot be empty." << std::endl;
        return 0;
    }
    try {
        curlpp::Easy req;
        std::stringstream respon;
        std::string datas = R"({"content": ")" + pdata + R"("})";

        
        std::cout << "Sending: " << datas << std::endl;

        std::list<std::string> headerList(headers.begin(), headers.end());
        req.setOpt(curlpp::options::HttpHeader(headerList));
        req.setOpt(curlpp::options::PostFields(datas));
        req.setOpt(curlpp::options::PostFieldSize(datas.size()));
        req.setOpt(curlpp::options::WriteStream(&respon));
        //req.setOpt(curlpp::options::TcpKeepAlive(true));
        req.setOpt(curlpp::options::Url(url));
        req.perform();
        return respon.str();
    } catch (curlpp::RuntimeError& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    } catch (curlpp::LogicError& e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }
    return "";
}

std::string Request::get() {
    std::string respon;
    try {
        curlpp::Easy get;
        std::stringstream respon;

        get.setOpt(curlpp::options::Url(url));
        std::list<std::string> headerList(headers.begin(), headers.end());
        get.setOpt(curlpp::options::HttpHeader(headerList));
        get.setOpt(curlpp::options::WriteStream(&respon));
        get.perform();

        return respon.str();
    } catch (curlpp::RuntimeError& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    } catch (curlpp::LogicError& e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }
    return "";
}


void Request::keepalive(){
    CURL *curl = curl_easy_init();
    CURLcode res;
    if(curl) {
        std::list<std::string> headerList(headers.begin(), headers.end());
        curl_easy_setopt(curl, CURLOPT_URL,"https://discordcom");
        curl_easy_setopt(curl, CURLOPT_TCP_FASTOPEN, 1L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
  }
}

