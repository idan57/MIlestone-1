//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_SERVER_H
#define MILESTONE_1_SERVER_H
#include <iostream>
#include <sys/socket.h>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;
#define MAXLISTEN 20

class server {
private:
    int server_socket;
    int client_socket;
    int port;
    sockaddr_in serverAddress;
public:
    server(int p):port(p){}
    void CreateDestAddress();
    int CreateServer();
    int GetServerSocket() { return  this->server_socket;}
    int GetClientSocket() { return  this->client_socket;}
    void CreateConnection();
    void close();
    sockaddr_in* GetServerAddress() { return  &this->serverAddress;}
};


#endif //MILESTONE_1_SERVER_H
