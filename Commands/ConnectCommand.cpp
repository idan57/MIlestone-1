//
// Created by idan on 12/12/2019.
//

#include "ConnectCommand.h"

int ConnectCommand::execute() {

    // Open client socket
    this->OpenClientConnection();

    // Open Updatign Mode as thread
    thread openClient(&ConnectCommand::UpdatingMode, this,
            this->clientConnection->GetDestAddress());

    return 3;
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
    while (TRUE) {

        // Generate new data to send to
        stringstream newVals;
        for (auto dir = this->directories->begin();
             dir != this->directories->end(); dir++) {

            // We generate a string in the generic server_small.xml format
            newVals << this->variables->at(dir->first)->GetValue() << ",";
        }

        // Get the generated string
        string dataToUpdate = newVals.str();

        // Cut the last ',' from the end
        dataToUpdate = dataToUpdate.substr(0, (dataToUpdate.size() - 1));

        // Send data
        int is_sent = this->clientConnection->SendData(dataToUpdate.c_str());
    }
}

