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
    double value;
    mutex locker;
    Interpreter *i = new Interpreter();
    Expression *e = nullptr;
    // Will have the expression that we will have to evaluate
    //Expression expression;
public:
    Var(string p, double val):path(p),value(val){}
    void SetPath(string p) {this->path = p;}
    string GetPath() {
        return this->path;
    }
    void SetValue(double val) {
        locker.lock();
        if ((this->value - val) < 10) {
            this->value = val;
        }
        locker.unlock();
    }
    double GetValue() {
        bool succeededLocking = false;
        double val = 0;
        while(!(succeededLocking)) {
            succeededLocking = locker.try_lock();
        }
        if (this->value < 0.01 && this->value != 0) {
            val = this->value * 10;
        }
        else {
            val = this->value;
        }
        locker.unlock();
        return val;
    }
    void InterpretVar(string var, string valToInter, map<string,Var*>*
            variables) {
        locker.lock();
        string tempVar = nullptr;
        string setVar = "";
        auto itr = variables->begin();
        while (itr != variables->end()) {
            ostringstream num;
            num << std::setprecision(30);
            num << std::fixed;
            num << itr->second->GetValue();
            tempVar = itr->second->GetPath() + "=" + num.str() + ";";
            setVar += tempVar;
            itr++;
        }
        i->setVariables(setVar);
        e = i->interpret(valToInter);
        auto it = variables->begin();
        while (it != variables->end()) {
            if ((it->second->GetPath()) == var) {
                it->second->SetValue(e->calculate());
                break;
            }
            it++;
        }
        locker.unlock();
    }
};


#endif //MILESTONE_1_VAR_H
