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
    vector<string>* interperted;
public:
    Command(vector<string>* inter){ this->interperted = inter; }
    virtual int execute();
    vector<string>* parse(int n);
};


#endif //MILESTONE_1_COMMAND_H
