//
// Created by idan on 12/12/2019.
//

#include "Command.h"
vector<std::__cxx11::string>* Command::parse(int n) {
    vector<string>* parsed = new vector<string>;
    int i = 1;
    for(auto curr = (*this->interperted).begin(); i <= n; i++, curr++) {
        parsed->push_back((*curr));
    }
    return parsed;
}