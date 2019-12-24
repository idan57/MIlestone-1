//
// Created by idan on 24/12/2019.
//

#ifndef MILESTONE_1_SYMBOLTABLE_H
#define MILESTONE_1_SYMBOLTABLE_H

#include <iostream>
#include <string>
#include "../Expressions/Var.h"
#include "../Extra Methods/Extra.h"

using namespace std;

class SymbolTable {
public:
    int clientVar;
    int serverVar;
    map<string,Var*>* variables;

    // Map of directories - static so any instance will be able to get the
    // same field
    map<string, int>* directories;

    // All vars that need to be updated via my server - static so any
    // instance will be able to get the same field
    map<int, string>* ServerUpdate;

    // All vars that need to be updated via my client - static so any
    // instance will be able to get the same field
    map<int, string>* ClientUpdate;

    SymbolTable() {
        Extra *ex = new Extra();
        this->variables = new map<string,Var*>;
        this->directories = ex->initializeDirectories();
        this->ServerUpdate = new map<int, string>;
        this->ClientUpdate = new map<int, string>;
        clientVar = 0;
        serverVar = 0;
    }
};


#endif //MILESTONE_1_SYMBOLTABLE_H
