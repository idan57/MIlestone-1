#include <cstring>
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

    // Create connection with server.
    int connection = connect(this->client_socket,
            (struct sockaddr *)&this->destAddress,
            sizeof(this->destAddress));
    if (connection == -1) {
        std::cerr << "Could not connect to host server"<<std::endl;
        return -2; // failed to connect to server
    } else {
        std::cout<<"Client is now connected to server" <<std::endl;
    }
    return 1; // opened socket and established connection with server
}

void client::CreateDestAddress(const char *addr, int port) {
    this->destAddress.sin_family = AF_INET;
    this->destAddress.sin_addr.s_addr = inet_addr(addr);
    this->destAddress.sin_port = htons(port);
}

int client::ConnectToServer(struct sockaddr_in server_address) {
    int is_connect = connect(this->client_socket,
                             (struct sockaddr *)&server_address,
                             sizeof(server_address));
    if (is_connect == -1) {
        std::cerr << "Could not connect to host server" << std::endl;
        return -2;
    }
    return 1;
}

int client::SendData(const char * data) {
    int is_sent = send(this->client_socket , data, strlen(data), 0);
    if (is_sent == -1) {
        std::cout<<"Error sending message"<<std::endl;
        return -1;
    }
    return 1;
}