//
// Created by idan on 17/12/2019.
//

#ifndef MILESTONE_1_IFCOMMAND_H
#define MILESTONE_1_IFCOMMAND_H


#include "Command.h"
#include "../Expressions/Expression.h"
#include "../Expressions/ex1.h"

class IfCommand: public Command{
public:
    IfCommand(vector<string>* inter, SymbolTable* symT):Command(inter, symT){}
    IfCommand* copy(vector<string>* inter, SymbolTable* symT) {
        return new IfCommand(inter, symT);
    }
    int execute();
};


#endif //MILESTONE_1_IFCOMMAND_H
