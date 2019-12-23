//
// Created by liad on 23/12/2019.
//

#include "Sleep.h"

int Sleep::execute() {

    vector<string>* parsed = this->parse(1);
    std::this_thread::sleep_for(std::chrono::milliseconds(stoi(parsed->at(1))));

}