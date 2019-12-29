//
// Created by idan on 17/12/2019.
//

#include "CommandCreator.h"

// Function that creates a map of Command objects that later will create
// instances of those Commands.
CommandCreator::CommandCreator() {
    this->creator = new map<string, Command*>;
    vector<string>* defaultInterperted = new vector<string>;
    SymbolTable* symTable = new SymbolTable();

    // openDataServer
    this->creator->insert({"openDataServer",
                           new OpenDataServer(defaultInterperted, symTable)});

    // connectControlClient
    this->creator->insert({"connectControlClient",
                           new ConnectCommand(defaultInterperted, symTable)});

    // DefineVarCommand
    this->creator->insert({"var",
                           new DefineVarCommand(defaultInterperted, symTable)});

    // Print
    this->creator->insert({"Print",
                           new PrintCommand(defaultInterperted, symTable)});

    // Sleep
    this->creator->insert({"Sleep",
                           new Sleep(defaultInterperted, symTable)});

    // while
    this->creator->insert({"while",
                           new WhileCommand(defaultInterperted, symTable)});

    // IfComamnd
    this->creator->insert({"if",
                           new IfCommand(defaultInterperted, symTable)});

    // ElseCommand
    this->creator->insert({"else",
                           new IfCommand(defaultInterperted, symTable)});
}

