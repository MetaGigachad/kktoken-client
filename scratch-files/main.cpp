#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/write.hpp>
#include <ctime>
#include <iostream>
#include <list>
#include <string>
using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioservice;
tcp::endpoint tcp_endpoint{tcp::v4(), 2014};
tcp::acceptor tcp_acceptor{ioservice, tcp_endpoint};
std::list<tcp::socket> tcp_sockets;

void do_write(tcp::socket& tcp_socket, yield_context yield) {
    std::cout << "= Entered do_write" << std::endl;
    std::time_t now = std::time(nullptr);
    std::string data = std::ctime(&now);
    std::cout << "== Starting async write" << std::endl;
    async_write(tcp_socket, buffer(data), yield);
    tcp_socket.shutdown(tcp::socket::shutdown_send);
    std::cout << "= Left do_write" << std::endl;
}

void do_accept(yield_context yield) {
    std::cout << "- Entered do_accept" << std::endl;
    for (int i = 0; i < 2; ++i) {
        tcp_sockets.emplace_back(ioservice);
        std::cout << "-- Starting async accept" << std::endl;
        tcp_acceptor.async_accept(tcp_sockets.back(), yield);
        std::cout << "-- Spawning do write" << std::endl;
        spawn(ioservice, [](yield_context yield) { do_write(tcp_sockets.back(), yield); });
    }
    std::cout << "- Left do_accept" << std::endl;
}

int main(int argc, char** argv) {
    std::string port_str = argv[1];
    boost::asio::ip::port_type d(std::stoi(port_str));
    tcp::endpoint new_tcp_endpoint{tcp::v4(), d};
    tcp_acceptor = tcp::acceptor(ioservice, new_tcp_endpoint);

    std::cout << "tcp_acceptor.listen()" << std::endl;
    tcp_acceptor.listen();
    std::cout << "Spawning do accept" << std::endl;
    spawn(ioservice, do_accept);
    std::cout << "Running IOService" << std::endl;
    ioservice.run();
    std::cout << "End of program" << std::endl;
}
