//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_VAR_H
#define MILESTONE_1_VAR_H

#include <iostream>
using namespace std;

class Var {
private:
    string* path;
    double value;
public:
    Var(string* p, double val):path(p),value(val){}
    void SetPath(string* p) {this->path = p;}
    string* GetPath() { return this->path;}
    void SetValue(double val) {this->value = val;}
    int GetValue() {return this->value;}
};


#endif //MILESTONE_1_VAR_H
