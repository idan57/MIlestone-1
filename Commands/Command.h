//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_COMMAND_H
#define MILESTONE_1_COMMAND_H

#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include "../Expressions/Var.h"

using namespace std;

class Command {
private:
    vector<string*>* interperted; // the vector of data after interpretation
    map<int,string*>* directories;
    vector<double>* dataFromSim;
    map<string*,Var*>* variables;
    map<int, string*>* ServerUpdate;
    // All vars that need to be updated via my client.
    map<int, string*>* ClientUpdate;
public:
    Command(vector<string*>* inter) {
        this->interperted = inter;
        this->ServerUpdate = new map<int, string*>;
        this->ClientUpdate = new map<int, string*>;
    }
    virtual int execute() = 0; // method for all commands to override
    vector<string>* parse(int n);
    vector<double>* splitNums(char* data, char delimeter);
    void UpdateVariables(map<string*,int> updatedVars);
};


#endif //MILESTONE_1_COMMAND_H
