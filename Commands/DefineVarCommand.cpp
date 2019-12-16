//
// Created by liad on 16/12/2019.
//

#include "DefineVarCommand.h"
#include "Expression.h"
#include "ex1.h"
int DefineVarCommand::execute() {

    Interpreter* i = new Interpreter();
    Expression* e = nullptr;
    vector<string>* firstParsed = this->parse(0);
    if (firstParsed->at(0) == "var") {

        vector<string> *parsed = this->parse(2);

        if (parsed->at(1) == "=") {
            string var = parsed->at(0);
            string val = parsed->at(2);

            // need check if number before
            i->setVariables(var+"="+val);


        } else {

            vector<string>* sim = this->parse(0);
            Var *v = new Var(&(sim->at(0)), 0);
            this->variables->insert({&(firstParsed->at(0)), v});
            if (parsed->at(1) == "->") {
                this->ClientUpdate->insert({clientVar, &(sim->at(0))});
                clientVar++;
            } else {
                this->ServerUpdate->insert({serverVar, &(sim->at(0))});
                serverVar++;
            }
        }

    }
    else {

        vector<string> *parsed = this->parse(1);

        // need set variables for all the variables
        i->setVariables();
        e = i->interpret(parsed->at(1));
        this->variables->at(&(firstParsed->at(0)))->SetValue(e->calculate());
        }
    }
