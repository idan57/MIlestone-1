//
// Created by idan on 17/12/2019.
//

#ifndef MILESTONE_1_COMMANDCREATOR_H
#define MILESTONE_1_COMMANDCREATOR_H
#include <iostream>
#include <string>
#include "Command.h"
#include "OpenDataServer.h"
#include "PrintCommand.h"
#include "WhileCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "Sleep.h"
#include "IfCommand.h"

using namespace std;

class CommandCreator {
private:
    map<string, Command*>* creator;
public:
    CommandCreator();
    Command* Create();
    map<string, Command*>* getCreator(){return creator;}
};


#endif //MILESTONE_1_COMMANDCREATOR_H
