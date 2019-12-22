//
// Created by idan on 17/12/2019.
//

#ifndef MILESTONE_1_IFCOMMAND_H
#define MILESTONE_1_IFCOMMAND_H


#include "Command.h"
#include "Expression.h"
#include "ex1.h"

class IfCommand: public Command{
public:
    IfCommand(vector<string>* inter):Command(inter){}
    IfCommand* copy(vector<string>* inter) {
        return new IfCommand(inter);
    }
    int execute();
};


#endif //MILESTONE_1_IFCOMMAND_H
