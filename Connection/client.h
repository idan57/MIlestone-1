#ifndef MILESTONE_1_CLIENT_H
#define MILESTONE_1_CLIENT_H
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define LOCAL_HOST "127.0.0.1"

class client {
private:
    int client_socket;
    sockaddr_in destAddress;
public:
    client(){}
    void CreateDestAddress(const char *addr, int port);
    int CreateClient(const char * destAddr, int port);
    int ConnectToServer(struct sockaddr_in server_address);
    int SendData(const char* data);
    int GetClientSocket() { return  this->client_socket;}
    sockaddr_in GetDestAddress() { return  this->destAddress;}
    void close() {::close(this->client_socket);}
    int readFromServer();
};


#endif //MILESTONE_1_CLIENT_H
