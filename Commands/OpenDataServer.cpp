//
// Created by idan on 12/12/2019.
//

#include "OpenDataServer.h"


int OpenDataServer::execute() {

    // Parse the vector of parsed data
    vector<string>* parsed = this->parse(1);
    cout << parsed->at(1) << endl;
    // Get The port's value
    int port = stoi(parsed->at(1));

    // Open server as a thread
    thread serverOpen(&OpenDataServer::OpenServerConnection, this, port);

    // Wait until server is open and in reading mode
    serverOpen.join();
    return 1;
}

void OpenDataServer::OpenServerConnection(int port) {

    // Create server instance
    this->serverConnection = new server(port, "127.0.0.1");

    // Create server connection
    int server_socket = this->serverConnection->CreateServer();

    // Start getting info
    this->StartReading();
}

void OpenDataServer::StartReading() {

    // Waiting for a client connection
    int client_connected = accept(this->serverConnection->GetServerSocket(),
                                  (struct sockaddr*)this->serverConnection->GetServerAddress(),
                                  (socklen_t*) this->serverConnection->GetServerAddress());
    if (client_connected == -1) {
        std::cerr<<"Error accepting client"<<std::endl;
        return;
    }

    // Created connection, now getting data from the simulator in a thread
    // and dealing with the data
    thread serverReading(&OpenDataServer::ReadingMode, this, client_connected);

    // Start reading in background after the method ended
    serverReading.detach();
}

void OpenDataServer::ReadingMode(int client_connected) {

    // Data we get from the simulator
    char dataFromSim[1024] = {0};
    int bytesRead = read(client_connected , dataFromSim, 1024);

    // Getting data until there is no data to receive (simulator closed)
    while (bytesRead > 0) {
        ChangeMap(dataFromSim);
        bytesRead = read(client_connected , dataFromSim, 1024);
    }
}
void OpenDataServer::ChangeMap(char* dataFromSim) {

    // Split data by ','
    vector<double>* dataToUpdate = splitNums(dataFromSim, ',');


    // Update the variables accordingly
    this->UpdateVariables(dataToUpdate, 's');
}


