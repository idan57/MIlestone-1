//
// Created by idan on 15/12/2019.
//

#ifndef MILESTONE_1_WHILECOMMAND_H
#define MILESTONE_1_WHILECOMMAND_H


#include "Command.h"
#include "../Expressions/Var.h"

class WhileCommand: public Command {
private:
    map<int,Var*>* variablesToIter;
public:
    WhileCommand(vector<string>* inter, SymbolTable* symT):Command(inter,
            symT){}
    WhileCommand* copy(vector<string>* inter, SymbolTable* symT) {
        return new WhileCommand(inter, symT);
    }
    int execute();
    void addVariablesToIter(Var* var);
};


#endif //MILESTONE_1_WHILECOMMAND_H