#include <iostream>
#include <string>
#include "read.hpp"
#include <nlohmann/json.hpp> // Include the nlohmann/json library

using json = nlohmann::json;

std::string read(const std::string& jsonData) {
    std::string result; // To store the output string

    try {
        // Parse the JSON data
        json parsedData = json::parse(jsonData);

        // Iterate through the array and extract id and author name
        for (const auto& item : parsedData) {
            std::string messageId = item["author"]["id"];
            std::string authorName = item["author"]["username"]; // Access username from author
            std::string content = item["content"];

            // Construct the result string
            result += "ID: " + messageId + ", User: " + authorName + ", Message: " + content + "\n";
        }
    } catch (const json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return ""; // Return an empty string on error
    } catch (const json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
        return ""; // Return an empty string on error
    }

    return result; // Return the constructed result string
}
std::string extractUsername(const std::string& jsonData) {
    // Check if the input string is empty
    if (jsonData.empty()) {
        std::cerr << "Input JSON string is empty." << std::endl;
        return ""; // Return an empty string on error
    }

    try {
        // Parse the JSON data
        json parsedData = json::parse(jsonData);

        // Extract the username
        std::string username = parsedData["author"]["username"];
        return username; // Return the extracted username
    } catch (const json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return ""; // Return an empty string on error
    } catch (const json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
        return ""; // Return an empty string on error
    }
}

std::vector<getdata> mesdata(const std::string data) {
    std::vector<getdata> datas;
    try {
        json dulieu = json::parse(data);
        for (const auto& item : dulieu) {
            getdata get;
            get.id = item["author"]["id"]; // Use value with default
            get.msg = item["content"]; // Use value with default
            get.user = item["author"]["username"]; // Use value with default
            datas.push_back(get);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing JSON: " << e.what() << '\n';
    }
    return datas;
}
