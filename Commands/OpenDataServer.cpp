//
// Created by idan on 12/12/2019.
//

#include "OpenDataServer.h"
#include "../Extra Methods/Extra.h"

int OpenDataServer::execute() {

    // Parse the vector of parsed data
    vector<string>* parsed = this->parse(1);
    // Get The port's value
    int port = this->setVar(parsed->at(1))->calculate();

    // Open server as a thread
    thread serverOpen(&OpenDataServer::OpenServerConnection, this, port);

    // Wait until server is open and in reading mode
    serverOpen.join();
    return 1;
}

void OpenDataServer::OpenServerConnection(int port) {

    // Create server instance
    this->serverConnection = new server(port);

    // Create server connection
    int server_socket = this->serverConnection->CreateServer();

    this->serverConnection->CreateConnection();
}

void OpenDataServer::ReadingMode(int client_connected ,bool*
there_are_more_commands) {
    while(*there_are_more_commands) {
        char dataFromSim[1024] = {0};
        int bytesRead = read(client_connected , dataFromSim, 1024);
        //cout << dataFromSim << endl;
        ChangeMap(dataFromSim);
        std::this_thread::sleep_for(std::chrono::milliseconds(19));
    }
    this->serverConnection->close();
}
void OpenDataServer::ChangeMap(char* dataFromSim) {

    // Split data by ','
    vector<double>* dataToUpdate = splitNums(dataFromSim, ',');

    // Update the variables accordingly
    this->UpdateVariables(dataToUpdate, 's');
}


