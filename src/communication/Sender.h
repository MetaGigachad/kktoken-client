//
// Created by inqognitoo on 7/24/22.
//

#ifndef KKTOKEN_CLIENT_KKTOKEN_CLIENT_COMMUNICATION_SENDER_H_
#define KKTOKEN_CLIENT_KKTOKEN_CLIENT_COMMUNICATION_SENDER_H_

#include <boost/asio.hpp>

//todo: make implementation

class Sender
{
  public:
    virtual std::size_t send(boost::asio::mutable_buffer& buffer, boost::system::error_code& ec) = 0;
    virtual std::size_t send(boost::asio::mutable_buffer& buffer, boost::system::error_code& ec, std::chrono::duration<double>& timeout) = 0;
};

#endif//KKTOKEN_CLIENT_KKTOKEN_CLIENT_COMMUNICATION_SENDER_H_
