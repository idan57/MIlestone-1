#include "server.h"

//
int server::CreateServer() {
    this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server_socket == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        return -1; // failed to create connection with socket
    }

    // Creating the address of to give the socket IP, Port and Protocol for
    // future connections.
    this->CreateDestAddress();

    // Bind server with the given
    if (bind(this->server_socket,
            (struct sockaddr *) &this->serverAddress,
                    sizeof(this->serverAddress)) == -1) {
        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
        return -2; // failed to bind
    }

    // Establish listening
    if (listen(this->server_socket, MAXLISTEN) == -1) { //can also set to SOMAXCON
        // (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        return -3; // failed to listen to this amount of connections
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    return 1;
}

void server::CreateDestAddress() {
    this->serverAddress.sin_family = AF_INET;
    this->serverAddress.sin_addr.s_addr = inet_addr(this->address);
    this->serverAddress.sin_port = htons(this->port);
}