//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_CONNECTCOMMAND_H
#define MILESTONE_1_CONNECTCOMMAND_H


#include "Command.h"
#include "../Expressions/Var.h"
#include "../Connection/server.h"
#include "../Connection/client.h"

class ConnectCommand: public Command{
private:

    // The socket created for our program for connection
    client* clientConnection;


public:
    ConnectCommand(vector<string*>* inter):Command(inter){}
    int execute();
    void readData();
    void OpenClientConnection(int port);
    void UpdatingMode(int server_connected);
};


#endif //MILESTONE_1_CONNECTCOMMAND_H
