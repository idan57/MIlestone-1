//
// Created by liad on 16/12/2019.
//

#include "PrintCommand.h"

int PrintCommand::execute() {

    vector<string>* parsed = this->parse(1);
    for (auto it = this->symbolTable->variables->begin(); it != this->symbolTable->variables->end(); it++) {
        if (it->second->GetPath() == parsed->at(1)) {
            cout << it->second->GetValue() << endl;
            return 1;
        }

    }
    cout << parsed->at(1) << "\n";
}