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
                           new ElseCommand(defaultInterperted)});
}

void CommandCreator::Execution(vector<string> * inter) {

    // Iteration index
    int index = 0;

    // Number of elements to iterate over
    int numberOfInterated = inter->size();

    // Temporary Command variable
    Command* c;
    auto iterToCreate = this->creator->begin();
    int continueToNext = 0;

    // Iteration and creation of all commands in the program.
    while (index < numberOfInterated) {
        c = this->creator->find(inter->at(index))->second;
        if (c != nullptr) {
            continueToNext += c->execute();
        }

        // It is an existing variable
        else {
            // Update Variable from the map of variables
        }
        // Need to deal with a case where it is not a command
        // Go to the next command to execute
        while(continueToNext > 0) {
            iterToCreate++;
            continueToNext--;
        }

        continueToNext = 0;
    }
}