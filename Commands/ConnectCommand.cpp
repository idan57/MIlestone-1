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
    this->OpenClientConnection();
    // Open client socket
    return 2;
}
void ConnectCommand::OpenClientConnection() {
    sockaddr_in address; //in means IP4
    vector<string>* clientInfo = new vector<string>();

    // Get ("Address", port) parsed data
    clientInfo = this->parse(2);
    int PORT = this->setVar(clientInfo->at(2))->calculate();
    string IP = clientInfo->at(1);
    stringstream final_ip;
    int i = 0;
    while (IP[i] != '\0') {
        if (IP[i] != '"') {
            final_ip << IP[i];
        }
        i++;
    }
    // Create Client
    this->clientConnection = new client();
    int success = this->clientConnection->CreateClient(final_ip.str().c_str(), PORT);
    if (success != 1) {
        throw "Failed To Open Client\n";
    }
}

void ConnectCommand::UpdatingMode(bool *there_are_more_commands) {
    // Check if connection is still up
    this->clientConnection->ConnectToServer();
    // An infinite loop that gets data from server until there is no connection
    while (*there_are_more_commands) {
        for (auto dir = symbolTable->ClientUpdate->begin();
             dir != symbolTable->ClientUpdate->end(); dir++) {
            Var* var =  symbolTable->variables->at(dir->second);
            if (var->updated) {
                var->updated = false;
                ostringstream newVals;
                double d = var->GetValue();
                if (dir->second == "/sim/model/c172p/brake-parking") {
                    cout << d << endl;
                }
                newVals << std::setprecision(10);
                newVals << std::fixed;
                // We generate a string in the generic server_small.xml format
                newVals << "set " << dir->second << " " << d << "\r\n";

                // Get the generated string
                string dataToUpdate = newVals.str();

                // Cut the last ',' from the end
                dataToUpdate = dataToUpdate.substr(0, dataToUpdate.size());
                this->clientConnection->SendData(&dataToUpdate);
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
                int valread = this->clientConnection->readFromServer();
            }
        }
    }
    this->clientConnection->close();
}