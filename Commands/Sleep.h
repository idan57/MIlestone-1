//
// Created by idan on 17/12/2019.
//

#ifndef MILESTONE_1_SLEEP_H
#define MILESTONE_1_SLEEP_H


#include "Command.h"

class Sleep: public Command {
public:
    Sleep(vector<string>* inter, SymbolTable* symT):Command(inter, symT){}
    Sleep* copy(vector<string>* inter, SymbolTable* symT) {
        return new Sleep(inter, symT);
    }
    int execute();
};


#endif //MILESTONE_1_SLEEP_H
