//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_COMMAND_H
#define MILESTONE_1_COMMAND_H

#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Command {
private:
    vector<string*>* interperted; // the vector of data after interpretation
    map<int,string*>* directories;
    vector<double>* dataFromSim;
public:
    Command(vector<string*>* inter) {
        this->interperted = inter;
    }
    virtual int execute() = 0; // method for all commands to override
    vector<string>* parse(int n);
    vector<double>* splitNums(char* data, char delimeter);
};


#endif //MILESTONE_1_COMMAND_H
