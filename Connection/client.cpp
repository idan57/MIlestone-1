#include <cstring>
#include <sstream>
#include "client.h"

int client::CreateClient(const char * destAddr, int port) {
    //create socket
    this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->client_socket == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        return -1; // failed to open socket
    }
    // Creating the address of the server we wish to connect to.
    this->CreateDestAddress(destAddr, port);
    return 1; // opened socket and established connection with server
}
int client::ConnectToServer() {
    int is_connect = connect(this->client_socket,
                             (struct sockaddr *) &this->destAddress,
                             sizeof(this->destAddress));
    return 1;
}
void client::CreateDestAddress(const char *addr, int port) {
    this->destAddress.sin_family = AF_INET;
    this->destAddress.sin_addr.s_addr = inet_addr(addr);
    this->destAddress.sin_port = htons(port);
}

int client::SendData(string* data) {
    int is_sent = write(this->client_socket , data->c_str(), data->size());
    if (is_sent == -1) {
        std::cout<<"Error sending message"<<std::endl;
        return -1;
    }
    return 1;
}

int client::readFromServer() {
    char buffer[1024] = {0};
    int valread = read( client_socket , buffer, 1024);
    int i = 0;
    return valread;
}