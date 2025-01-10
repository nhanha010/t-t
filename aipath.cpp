#include "aipath.hpp"

std::string aipath(const std::string pdata){
    std::string data;
    try
    {
        Request req;
        std::string vtoken = "rk8SG+fV8QXuB5sHXgxlKxIdizLmZ29Yle0NedpeZnbr9OA/QhW5g0+mgReX6CWD1VZY0rPmg+LD4LHcvL0UF/U3L9mJBjGNwgBXnDuLQ7EDNDtCRGSSRdoHv82EjHv4gFFCypZrSEGFONT2GyIi+8d6bYOh+Q6poKsGzui/kpU=";
        req.setheader("Content-type: application/json");
        req.setheader("Origin: https://www.aichatting.net");
        req.setheader("");
        req.setheader("Vtoken:" + vtoken);
        req.seturl("https://aga-api.aichatting.net/aigc/chat/v2/stream");
        req.setpdata(pdata);
        req.post();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return data;
}