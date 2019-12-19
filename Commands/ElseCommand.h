//
// Created by idan on 17/12/2019.
//

#ifndef MILESTONE_1_ELSECOMMAND_H
#define MILESTONE_1_ELSECOMMAND_H


#include "Command.h"

class ElseCommand: public Command {
public:
    ElseCommand(vector<string>* inter):Command(inter){}
    ElseCommand* copy(vector<string>* inter) {
        return new ElseCommand(inter);
    }
};


#endif //MILESTONE_1_ELSECOMMAND_H
