//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_VAR_H
#define MILESTONE_1_VAR_H

#include <iostream>
#include <mutex>

using namespace std;

class Var {
private:
    string* path;
    double value;
    mutex locker;
    // Will have the expression that we will have to evaluate
    //Expression expression;
public:
    Var(string* p, double val):path(p),value(val){}
    void SetPath(string* p) {this->path = p;}
    string* GetPath() { return this->path;}
    void SetValue(double val) {
        locker.lock();
        this->value = val;
        locker.unlock();

    }
    int GetValue() {
        bool succeededLocking = false;
        while(!(succeededLocking)) {
            succeededLocking = locker.try_lock();
        }
        double val = this->value;
        locker.unlock();
        return val;
    }
};


#endif //MILESTONE_1_VAR_H
