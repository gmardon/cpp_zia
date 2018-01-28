#include "Zia.hpp"
#include "ZiaServer.hpp"
#include "ZiaClient.hpp"

const std::string ASCII_HEADER = " ______     __     ______    \n/\\___  \\   /\\ \\   /\\  __ \\   \n\\/_/  /__  \\ \\ \\  \\ \\  __ \\  \n  /\\_____\\  \\ \\_\\  \\ \\_\\ \\_\\ \n  \\/_____/   \\/_/   \\/_/\\/_/ \n";

int main(int argc, char** argv)
{
    printf("%s\n", ASCII_HEADER.c_str());
    // TODO: create configuration object, and give-it to zia serer
    //ZiaServer *s = new ZiaServer();
    try
    {
        if (argc != 2) {
            std::cerr << "Usage: ./server <port>\n";
            return 1;
        }
        boost::asio::io_service io_service;
        ZiaServer s(io_service, 2323);
        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}