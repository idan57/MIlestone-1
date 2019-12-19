//
// Created by idan on 12/12/2019.
//

#include "ConnectCommand.h"
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int ConnectCommand::execute() {

    // Open client socket
    this->OpenClientConnection();

    // Open Updatign Mode as thread
    thread openClient(&ConnectCommand::UpdatingMode, this,
            this->clientConnection->GetDestAddress());

    // Make the thread run in the background even we end method
    openClient.detach();
    return 2;
}
void ConnectCommand::OpenClientConnection() {
    sockaddr_in address; //in means IP4

    // Get ("Address", port) parsed data
    vector<string*>* clientInfo = this->parse(2);
    string* IP = clientInfo->at(0);
    int PORT = stod(*clientInfo->at(1));

    // Create Client
    this->clientConnection = new client();
    int success = this->clientConnection->CreateClient(IP->c_str(), PORT);
    if (success != 1) {
        throw "Failed To Open Client\n";
    }
}

void ConnectCommand::UpdatingMode(sockaddr_in server_address) {
    // Connect to simulator
    int success = this->clientConnection->ConnectToServer(server_address);
    if (success == -2) {
        throw "Failed To Connect To Server\n";
    }

    // Check if connection is still up
    int valread = this->clientConnection->readFromServer();

    // An infinite loop that gets data from server until there is no connection
    while (valread) {

        // Generate new data to send to
        for (auto dir = this->ClientUpdate->begin();
             dir != this->ClientUpdate->end(); dir++) {
            stringstream newVals;

            // We generate a string in the generic server_small.xml format
            newVals << "set " << dir->second << " " <<
            this->variables->at(dir->second)->GetValue() << "\n";

            // Get the generated string
            string dataToUpdate = newVals.str();

            // Cut the last ',' from the end
            dataToUpdate = dataToUpdate.substr(0, (dataToUpdate.size() - 1));

        }

        // Send data
        valread = this->clientConnection->readFromServer();

    }
}

