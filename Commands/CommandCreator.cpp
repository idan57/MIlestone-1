//
// Created by idan on 17/12/2019.
//

#include "CommandCreator.h"


CommandCreator::CommandCreator() {
    this->creator = new map<string, Command*>;
    vector<string>* defaultInterperted = new vector<string>;

    // openDataServer
    this->creator->insert({"openDataServer",
                           new OpenDataServer(defaultInterperted)});

    // connectControlClient
    this->creator->insert({"connectControlClient",
                           new ConnectCommand(defaultInterperted)});

    // DefineVarCommand
    this->creator->insert({"var",
                           new DefineVarCommand(defaultInterperted)});

    // Print
    this->creator->insert({"Print",
                           new PrintCommand(defaultInterperted)});

    // Sleep
    this->creator->insert({"connectControlClient",
                           new Sleep(defaultInterperted)});

    // while
    this->creator->insert({"while",
                           new WhileCommand(defaultInterperted)});

    // IfComamnd
    this->creator->insert({"if",
                           new IfCommand(defaultInterperted)});

    // ElseCommand
    this->creator->insert({"else",
                           new IfCommand(defaultInterperted)});
}

void CommandCreator::Execution(vector<string>* inter) {

    // Iteration index
    int index = 0;

    // Number of elements to iterate over
    int numberOfInterated = inter->size();

    // Temporary Command variable
    Command* c;
    map<string, Command*>* variables_commands = new map<string, Command*>;

    // Iteration and creation of all commands in the program.
    while (index < numberOfInterated) {
        c = this->creator->find(inter->at(index))->second->copy(inter);
        if (c != nullptr) {
            if (inter->at(index).compare("var")) {
                variables_commands->insert({inter->at(index + 1), c});
            }
            index += c->execute();
        }

        // It is an existing variable
        else {
            c = variables_commands->find(inter->at(index))->second;
            index += c->execute();
        }
    }

}