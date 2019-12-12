//
// Created by idan on 12/12/2019.
//

#include "OpenDataServer.h"


int OpenDataServer::execute() {
    vector<string>* parsed = this->parse(1);
    int port = stoi(*parsed->begin());
    thread serverOpen(&OpenDataServer::OpenServerConnection, this, port);

    // Wait until server is open and in reading mode
    serverOpen.join();
}

void OpenDataServer::OpenServerConnection(int port) {
    this->serverConnection = new server(port, "127.0.0.1");
    int server_socket = this->serverConnection->CreateServer();
    this->StartReading();
}

void OpenDataServer::StartReading(){
    int client_connected = accept(this->serverConnection->GetServerSocket(),
                                  (struct sockaddr*)this->serverConnection->GetServerAddress(),
                                  (socklen_t*) this->serverConnection->GetServerAddress());
    if (client_connected == -1) {
        std::cerr<<"Error accepting client"<<std::endl;
        return;
    }
    thread serverReading(&OpenDataServer::ReadingMode, this, client_connected);
}
void OpenDataServer::ReadingMode(int client_connected) {
    char buffer[1024] = {0};
    int bytesRead = read(client_connected , buffer, 1024);
    while (bytesRead > 0) {
        if(this->VarsToUpdate->find())
        bytesRead = read(client_connected , buffer, 1024);
    }
}

