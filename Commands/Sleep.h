//
// Created by idan on 17/12/2019.
//

#ifndef MILESTONE_1_SLEEP_H
#define MILESTONE_1_SLEEP_H


#include "Command.h"

class Sleep: public Command {
public:
    Sleep(vector<string>* inter):Command(inter){}
    Sleep* copy(vector<string>* inter) {
        return new Sleep(inter);
    }
};


#endif //MILESTONE_1_SLEEP_H
