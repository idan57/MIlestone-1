//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_COMMAND_H
#define MILESTONE_1_COMMAND_H

#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "../Expressions/Var.h"
#include "Expression.h"
#include "ex1.h"

using namespace std;
static bool initializedVars = false;

// Mutex to lock the code in UpdateVariables method

class Command {
private:
    mutex locker;
    vector<string>* interperted; // the vector of data after interpretation
protected:
    map<string*,Var*>* variables;

    // Map of directories - static so any instance will be able to get the
    // same field
     map<string*,int>* directories;

    // All vars that need to be updated via my server - static so any
    // instance will be able to get the same field
     map<int, string*>* ServerUpdate;

    // All vars that need to be updated via my client - static so any
    // instance will be able to get the same field
     map<int, string*>* ClientUpdate;

public:
    Command(vector<string>* inter) {
        this->interperted = inter;
        IntializeVarsServ();
    }
    void IntializeVarsServ() {
        if (!(initializedVars)) {
            this->ServerUpdate = new map<int, string *>;
            this->ClientUpdate = new map<int, string *>;
            initializedVars = true;
        }
    }
    virtual int execute() = 0; // method for all commands to override
    virtual Command* copy(vector<string>* inter) = 0; // method for all
    // commands to
    // override
    vector<string*>* parse(int n);
    vector<double>* splitNums(char* data, char delimeter);


    // Set the variables the commands should update
    void AddToVariablesField (pair<string*,Var*>* var){
        this->variables->insert({var->first, var->second});
    }

    void UpdateVariables(vector<double>* updatedVars, char SerOrCli);

    // Should be set in main via the method Extra::initializeDirectories()
    void SetDirectories(map<string*,int>* dirs) {this->directories = dirs;}
    
    bool Condition (double var, double val, string op);
    Interpreter* setVar();
};


#endif //MILESTONE_1_COMMAND_H
