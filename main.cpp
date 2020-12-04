#include <string>
#include "network/client/client.hpp"

int main(int argc, char* argv[]) {
    std::string host = argv[1];
    Client* client = new Client(host);
    client->openConnection();
    client->send("hello \n"); 
    client->send("hello ");
    return 0;
}
