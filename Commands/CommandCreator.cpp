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

