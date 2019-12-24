//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_COMMAND_H
#define MILESTONE_1_COMMAND_H

#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "../Expressions/Var.h"
#include "../Expressions/Expression.h"
#include "../Expressions/ex1.h"
#include "../Extra Methods/Extra.h"
#include "../SymbolTable/SymbolTable.h"

using namespace std;
static bool initializedVars = false;

#define NUM_OF_VALS_FROM_SERVER 36
// Mutex to lock the code in UpdateVariables method

class Command {
private:
    mutex locker;
protected:
    bool* there_are_commands;
    vector<string>* interperted; // the vector of data after interpretation
    SymbolTable* symbolTable;

public:
    Command(vector<string>* inter, SymbolTable* symT) {
        this->interperted = inter;
        this->symbolTable = symT;
    }
    virtual int execute() = 0; // method for all commands to override
    virtual Command* copy(vector<string>* inter, SymbolTable* symT) = 0;
    vector<string>* parse(int n);
    vector<double>* splitNums(char* data, char delimeter);
    void UpdateVariables(vector<double>* updatedVars, char SerOrCli);
    bool Condition (double var, double val, string op);
    Expression* setVar(string s);
};


#endif //MILESTONE_1_COMMAND_H
