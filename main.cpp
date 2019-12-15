#include <iostream>
#include "Connection/server.h"
using namespace std;

int main() {
    server* s = new server(5400,"127.0.0.1");
    int i = s->CreateServer();
    if (i != 1 ) {
        return 1;
    }
    int client_connected = accept(s->GetServerSocket(),
                                  (struct sockaddr*)s->GetServerAddress(),
                                  (socklen_t*) s->GetServerAddress());
    if (client_connected == -1) {
        std::cerr<<"Error accepting client " << s->GetServerSocket() <<std::endl;
        return 1;
    }
    close(s->GetServerSocket());
    char buffer[1024] = {0};
    int bytesRead = read(client_connected , buffer, 1024);
    while (bytesRead > 0) {
        cout << buffer << endl;
        bytesRead = read(client_connected , buffer, 1024);
    }
    return 0;
}
