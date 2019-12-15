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
using namespace std;

class OpenDataServer: public Command {
private:
    server* serverConnection;
    map<string*, Var*>* VarsToUpdate;
public:
    OpenDataServer(vector<string>* inter):Command(inter){
        this->VarsToUpdate = new map<string*, Var*>;
    }
    int execute();
    void readData();
    void OpenServerConnection(int port);
    void ReadingMode(int client_connected);
    void StartReading();
};


#endif //MILESTONE_1_OPENDATASERVER_H
