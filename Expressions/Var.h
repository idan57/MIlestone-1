//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_VAR_H
#define MILESTONE_1_VAR_H

#include <iostream>
#include <mutex>
#include <map>
#include "Expression.h"
#include "ex1.h"

using namespace std;
class Var {
private:
    string path;
    double value = 888888888888;
    bool isUpdated = false;
    mutex locker;
public:
    bool updated = false;
    Var(string p, double val):path(p),value(val){}
    void SetPath(string p) {this->path = p;}
    string GetPath() {
        return this->path;
    }

    // Set the value of the variable
    void SetValue(double val) {
        locker.lock();
        if (!isUpdated) {
            this->value = val;
            updated = true;
            isUpdated = true;
        }
        // Change the value only if it doesn't exceed 10
        else if ((this->value - val) < 10  && this->value != val) {
            this->value = val;
            updated = true;
        } else {
            updated = false;
        }
        locker.unlock();
    }

    // Get the value of the variable
    double GetValue() {
        bool succeededLocking = false;
        double val = 0;

        // Try to lock with the mutex
        while(!(succeededLocking)) {
            succeededLocking = locker.try_lock();
        }

        // Get the value.
        val = this->value;
        locker.unlock();
        return val;
    }
};


#endif //MILESTONE_1_VAR_H
