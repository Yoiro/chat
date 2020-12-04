#include <string>
#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#ifndef elif
#define elif else if
#endif

#include "client.hpp"

using boost::asio::io_service;
using boost::asio::ip::tcp;

Client::Client(const std::string host) {
    this->port = 4444;
    this->host = host;
}

Client& Client::operator=(const Client& other) {
    if (open) {
        closeConnection();
    }
    this->port = other.port;
    this->host = other.host;
}

Client::Client(const Client& origin) {
    this->port = origin.port;
    this->host = origin.port;
}

Client::~Client() {
    if (open) {
        closeConnection();
    }
}

void Client::openConnection() {
    tcp::resolver resolver(this->ioService);
    tcp::resolver::query query(this->host, std::to_string(this->port));
    tcp::resolver::iterator endpointIterator = resolver.resolve(query);
    this->socket = new tcp::socket(ioService);
    boost::asio::connect(*this->socket, endpointIterator);
    this->open = true;
}

void Client::send(const std::string message) {
        boost::array<char, 128> buffer;
        boost::system::error_code ignoredError;
        boost::asio::write(*this->socket, boost::asio::buffer(message), ignoredError);
}

std::string Client::readInput() {
    //TODO: read input
    return "";
}

void Client::closeConnection() {
    //TODO close connection
    this->open = false;
}

void Client::openSocket() {
    //TODO open socket
}

