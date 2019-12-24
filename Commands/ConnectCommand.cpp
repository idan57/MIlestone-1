//
// Created by idan on 12/12/2019.
//

#include "ConnectCommand.h"
#include "../Extra Methods/Extra.h"
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int ConnectCommand::execute() {

    // Open client socket
    this->OpenClientConnection();
    return 2;
}
void ConnectCommand::OpenClientConnection() {
    sockaddr_in address; //in means IP4

    // Get ("Address", port) parsed data
    vector<string>* clientInfo = this->parse(2);
    string IP = clientInfo->at(1);
    int PORT = stoi(clientInfo->at(2));

    // Create Client
    this->clientConnection = new client();
    int success = this->clientConnection->CreateClient(IP.c_str(), PORT);
    if (success != 1) {
        throw "Failed To Open Client\n";
    }
}

void ConnectCommand::UpdatingMode(sockaddr_in server_address, bool
*there_are_more_commands) {

    // Connect to simulator
    int success = this->clientConnection->ConnectToServer(server_address);

    // Check if connection is still up
    int valread = this->clientConnection->readFromServer();

    // An infinite loop that gets data from server until there is no connection
    while (there_are_more_commands) {

        // Generate new data to send to
        for (auto dir = symbolTable->ClientUpdate->begin();
             dir != symbolTable->ClientUpdate->end(); dir++) {
            stringstream newVals;

            // We generate a string in the generic server_small.xml format
            newVals << "set " << dir->second << " " <<
            symbolTable->variables->at(dir->second)->GetValue() << "\n";

            // Get the generated string
            string dataToUpdate = newVals.str();

            // Cut the last ',' from the end
            dataToUpdate = dataToUpdate.substr(0, (dataToUpdate.size() - 1));

        }

        // Send data
        valread = this->clientConnection->readFromServer();
    }
}

