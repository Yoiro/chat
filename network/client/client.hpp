#include <string>
#include <boost/asio.hpp>

using boost::asio::io_service;
using boost::asio::ip::tcp;

class Client {
    public:
        Client(const std::string);
        Client(const Client&);
        Client& operator=(const Client&);
        ~Client();

        void setHost(const std::string);
        std::string getHost();
        int getPort();
        bool isOpen();

        void openConnection();
        void openSocket();
        void send(const std::string);
        std::string readInput();
        void closeConnection();
    private:
        std::string host;
        int port;
        bool open;

        io_service ioService;
        tcp::socket* socket;
};

