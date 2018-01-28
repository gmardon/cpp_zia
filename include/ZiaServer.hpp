#ifndef _ZIA_SERVER_HPP_
#define _ZIA_SERVER_HPP_
#include "ZiaClient.hpp"

class ZiaServer
{
public:
    ZiaServer(boost::asio::io_service& io_service, short port)
      : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
        socket_(io_service)
    {
      do_accept();
    }
  
  private:
    void do_accept()
    {
      acceptor_.async_accept(socket_, [this](boost::system::error_code ec)
        {
          if (!ec) {
            std::make_shared<ZiaClient>(std::move(socket_))->start();
          }
          do_accept();
        });
    }
  
    tcp::acceptor acceptor_;
    tcp::socket socket_;
};
#endif