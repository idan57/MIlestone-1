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
mutex locker;
class Command {
private:
    vector<string*>* interperted; // the vector of data after interpretation
    vector<double>* dataFromSim;
protected:
    map<string*,Var*>* variables;
    map<string*,int>* directories;
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
    void UpdateVariables(map<string*,double>* updatedVars, char SerOrCli);
    void setDirectories(map<string*,int>* dirs) {this->directories = dirs;}
};


#endif //MILESTONE_1_COMMAND_H