//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_SERVER_H
#define MILESTONE_1_SERVER_H
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXLISTEN 20

class server {
private:
    int server_socket;
    int client_socket;
    int port;
    const char* address;
    sockaddr_in serverAddress;
public:
    server(int p, const char* addr):port(p), address(addr){}
    void CreateDestAddress();
    int CreateServer();
    int GetServerSocket() { return  this->server_socket;}
    int GetClientSocket() { return  this->client_socket;}
    void CreateConnection();
    void close();
    sockaddr_in* GetServerAddress() { return  &this->serverAddress;}
};


#endif //MILESTONE_1_SERVER_H
