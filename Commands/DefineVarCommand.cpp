//
// Created by liad on 16/12/2019.
//

#include "DefineVarCommand.h"
#include "../Expressions/ex1.h"
#include <thread>
#include <string>


int DefineVarCommand::execute() {

    double num = 0;
    int flag = 0;
    vector<string> *parsed = this->parse(0);


    if (parsed->at(0) == "var") {

        parsed = this->parse(2);
        cout << "0 "<< parsed->size() << endl;
        if (parsed->at(1) == "=") {
            string var = parsed->at(0);
            string val = parsed->at(2);
            auto iter = this->variables->begin();
            while (iter != this->variables->end()) {
                if ((iter->second->GetPath()) == val) {
                    num = iter->second->GetValue();

                    break;
                }
                iter++;
            }
            string str = string("localVar");
            Var *v = new Var(var,num);
            this->variables->insert({str,v});

        } else {

            vector<string> *sim = this->parse(0);
            Var *v = new Var(parsed->at(0), 0);
            string path = string((sim->at(0)));
            this->variables->insert({path, v});
            if (parsed->at(1) == "->") {
                this->ClientUpdate->insert({clientVar, path});
                clientVar++;
            } else {
                this->ServerUpdate->insert({serverVar, path});
                serverVar++;
            }
        }

    } else {

        parsed = this->parse(1);
        string val = parsed->at(1);
        string nameOfVar = parsed->at(0);
        auto it = this->variables->begin();
        while (it != this->variables->end()) {
            if ((it->second->GetPath()) == nameOfVar) {
                auto varToUpdate = it->second;
                thread update(&Var::InterpretVar, varToUpdate ,nameOfVar,
                        val, this->variables);
                break;
            }
            it++;
        }
    }
}
