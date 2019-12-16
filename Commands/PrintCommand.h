//
// Created by idan on 15/12/2019.
//

#ifndef MILESTONE_1_PRINTCOMMAND_H
#define MILESTONE_1_PRINTCOMMAND_H

#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "../Expressions/Var.h"
#include "Command.h"

class PrintCommand: public Command {
private:
    Var* variable;
public:
    PrintCommand(vector<string*>* inter):Command(inter){}
    int execute();
};


#endif //MILESTONE_1_PRINTCOMMAND_H
