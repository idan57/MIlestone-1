//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_CONNECTCOMMAND_H
#define MILESTONE_1_CONNECTCOMMAND_H


#include "Command.h"
#include "../Expressions/Var.h"
#include "../Connection/server.h"
#include "../Connection/client.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <pthread.h>

#define TRUE 1 // A const for True value

class ConnectCommand: public Command{
private:

    // The socket created for our program for connection
    client* clientConnection;
public:
    ConnectCommand(vector<string>* inter, SymbolTable* symT):Command(inter,
            symT){}
    ConnectCommand* copy(vector<string>* inter,SymbolTable* symT) {
        return new ConnectCommand(inter, symT);
    }
    int execute();
    void OpenClientConnection();
    void UpdatingMode(sockaddr_in server_address,
            bool* there_are_more_commands);
    client* getClientConnection() { return clientConnection; }
    ~ConnectCommand();
};


#endif //MILESTONE_1_CONNECTCOMMAND_H
