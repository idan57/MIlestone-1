//
// Created by idan on 12/12/2019.
//

#include "OpenDataServer.h"


int OpenDataServer::execute() {

    // Parse the vector of parsed data
    vector<string*>* parsed = this->parse(1);

    // Get The port's value
    int port = stoi(**parsed->begin());

    // Open server as a thread
    thread serverOpen(&OpenDataServer::OpenServerConnection, this, port);

    // Wait until server is open and in reading mode
    serverOpen.join();
    return 2;
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
    char dataFromSim[1024] = {0};
    int bytesRead = read(client_connected , dataFromSim, 1024);
    while (bytesRead > 0) {
        ChangeMap(dataFromSim);
        bytesRead = read(client_connected , dataFromSim, 1024);
    }
}
void OpenDataServer::ChangeMap(char* dataFromSim) {

    // Split data by ','
    vector<double>* dataToUpdate = splitNums(dataFromSim, ',');
    int i = 0;

    // Update the variables accordingly
    this->UpdateVariables(dataToUpdate, 's');
}


