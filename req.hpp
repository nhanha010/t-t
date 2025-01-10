#ifndef re_q
#define re_q
#include <string>
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <sstream>



class Request{
private:
    std::string url;
    std::string token;
    std::string pdata;
    std::list<std::string> headers;
public:
    void seturl(const std::string& url);
    void setheader(const std::string& header);
    std::string get();
    void setpdata(const std::string& pdata);
    void keepalive();
    std::string post();
    
};  

#endif