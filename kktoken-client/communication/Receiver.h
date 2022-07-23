//
// Created by inqognitoo on 7/24/22.
//

#ifndef KKTOKEN_CLIENT_KKTOKEN_CLIENT_COMMUNICATION_RECEIVER_H_
#define KKTOKEN_CLIENT_KKTOKEN_CLIENT_COMMUNICATION_RECEIVER_H_

#include <boost/asio.hpp>

//todo: make implementation

class Receiver
{
  public:
    virtual std::size_t receive(boost::asio::mutable_buffer& buffer, boost::system::error_code& ec) = 0;
    virtual std::size_t receive(boost::asio::mutable_buffer& buffer, boost::system::error_code& ec, std::chrono::duration<double>& timeout) = 0;
};

#endif//KKTOKEN_CLIENT_KKTOKEN_CLIENT_COMMUNICATION_RECEIVER_H_
