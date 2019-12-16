//
// Created by liad on 16/12/2019.
//

#include "PrintCommand.h"

int PrintCommand::execute() {

    vector<string>* parsed = this->parse(1);
    cout << parsed->at(1) << "\n";
}
