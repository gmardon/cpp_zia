#include "Zia.hpp"
#include "ZiaServer.hpp"
#include "ZiaClient.hpp"

int main(int argc, char** argv)
{
    // TODO: create configuration object, and give-it to zia serer
    //ZiaServer *s = new ZiaServer();
    try
    {
        if (argc != 2) {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
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