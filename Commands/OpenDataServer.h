//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_OPENDATASERVER_H
#define MILESTONE_1_OPENDATASERVER_H

#include <iostream>
#include <map>
#include "Command.h"
#include "../Connection/server.h"
#include <thread>
#include <pthread.h>
#include <chrono>
#include "../Expressions/Var.h"
#include "../Extra Methods/Extra.h"

using namespace std;

class OpenDataServer: public Command {
private:
    server* serverConnection;
public:
    OpenDataServer(vector<string>* inter):Command(inter){ }
    OpenDataServer* copy(vector<string>* inter) {
        return new OpenDataServer(inter);
    }
    int execute();
    void OpenServerConnection(int port);
    void ReadingMode(int client_connected ,bool* there_are_more_commands);
    void ChangeMap(char* dataFromSim);
    server* getServerConnection() {return serverConnection;}
    ~OpenDataServer();
};


#endif //MILESTONE_1_OPENDATASERVER_H
