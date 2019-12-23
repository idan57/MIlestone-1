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
    WhileCommand(vector<string*>* inter):Command(inter){}
    WhileCommand* copy(vector<string*>* inter) {
        return new WhileCommand(inter);
    }
    int execute();
    void addVariablesToIter(Var* var);
};


#endif //MILESTONE_1_WHILECOMMAND_H
