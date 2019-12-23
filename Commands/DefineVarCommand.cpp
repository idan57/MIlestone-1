//
// Created by liad on 16/12/2019.
//

#include "DefineVarCommand.h"
#include "ex1.h"
#include <thread>
#include <string>


int DefineVarCommand::execute() {

    double num = 0;
    int flag = 0;

    vector<string> *firstParsed = this->parse(0);
    if (firstParsed->at(0) == "var") {

        vector<string> *parsed = this->parse(2);

        if (parsed->at(1) == "=") {
            string var = parsed->at(0);
            string val = parsed->at(2);
            auto iter = this->variables->begin();
            while (iter != this->variables->end()) {
                if (*(iter->second->GetPath()) == val) {
                   num = iter->second->GetValue();

                    break;
                }
                iter++;
            }
            string str = "localVar";
            Var *v = new Var(&var,num);
            this->variables->insert({&str,v});

        } else {

            vector<string> *sim = this->parse(0);
            Var *v = new Var((&parsed->at(0)), 0);
            this->variables->insert({(&sim->at(0)), v});
            if (parsed->at(1) == "->") {
                this->ClientUpdate->insert({clientVar, (&sim->at(0))});
                clientVar++;
            } else {
                this->ServerUpdate->insert({serverVar, (&sim->at(0))});
                serverVar++;
            }
        }

    } else {

        vector<string> *parsed = this->parse(1);
        string val = parsed->at(1);
        string nameOfVar = firstParsed->at(0);
        auto it = this->variables->begin();
        while (it != this->variables->end()) {
            if (*(it->second->GetPath()) == nameOfVar) {
                auto varToUpdate = it->second;
                thread update(&Var::InterpretVar,varToUpdate ,nameOfVar, val, this->variables);
                break;
            }
            it++;
        }
    }
}







