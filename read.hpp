#ifndef read_q
#define read_q
#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
std::string read(const std::string& jsonData);
std::string extractUsername(const std::string& jsonData);
struct getdata
{
    std::string user;
    std::string msg;
    std::string id;
};
std::vector<getdata> mesdata(const std::string data);
#endif