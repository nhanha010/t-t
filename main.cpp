#include <string>
#include <iostream>
#include "req.hpp"
#include "read.hpp"
#include <thread>
#include "randomline.hpp"
// #include "aipath.hpp"

int main()
{
    Request req;
    std::string chanelid = "1034527571880189983";
    std::string token = "token";
    req.seturl("https://discord.com/api/v9/channels/" + chanelid + "/messages?limit=1");
    req.setheader("Content-Type: application/json");
    req.setheader("Keep-Alive: timeout=5, max=10");
    req.setheader("Authorization:" + token);
    req.setheader("User-agent: Mozilla/5.0 (Windows NT 6.3; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/45.0.2454.85 Safari/537.36");
    /*
        std::string a = req.get();
        std::cout << read(a);
        req.setpdata("hmmm");
        std::string c = req.post();
        //std::cout << extractUsername(c);
        //req.keepalive();
        std::vector<getdata> messages = mesdata(a);

        // Print the extracted messages
        for (const auto& msg : messages) {
            std::cout << "ID: " << msg.id << ", Message: " << msg.msg << ", User: " << msg.user << std::endl;
        };
    */
    while (true)
    {
        // std::cout << "wait" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::string data1 = req.get();

        // std::cout << read(data);
        std::vector<getdata> messages = mesdata(data1);
        for (const auto &msg : messages)
        {
            if (msg.id == "892950464788856862" && msg.msg == "test")
            {
                req.setpdata(ranl("/home/xix19/Nbot/nynhan.txt"));
                req.post();
                break;
            }
            else if (msg.id == "892950464788856862" && msg.msg == "congbang")
            {
                std::string congbang = "https://media.discordapp.net/attachments/1109752359011225670/1326970499334537277/image.png?ex=67815d14&is=67800b94&hm=4502706028e3b03542037a2d58cc087d9fc4d7419c3af6dc4da680061ac529b5&=&format=webp&quality=lossless";
                req.setpdata(congbang);
                req.post();
                break;
            }
            else
            {
                continue;
            }
        }
    }
    return 0;
}
