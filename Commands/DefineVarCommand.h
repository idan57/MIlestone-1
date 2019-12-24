//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_DEFINEVARCOMMAND_H
#define MILESTONE_1_DEFINEVARCOMMAND_H


#include "Command.h"

class DefineVarCommand : public Command{
    int clientVar = 0;
    int serverVar = 0;
public:
    DefineVarCommand(vector<string>* inter, SymbolTable* symT):Command(inter,
     symT) {}
    DefineVarCommand* copy(vector<string>* inter,SymbolTable* symT) {
        return new DefineVarCommand(inter, symT);
    }
    int execute();
};

#endif //MILESTONE_1_DEFINEVARCOMMAND_H
