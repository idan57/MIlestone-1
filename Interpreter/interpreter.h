//
// Created by liad on 15/12/2019.
//

#ifndef MILESTONE_1_INTERPRETER_H
#define MILESTONE_1_INTERPRETER_H
#include <bits/stdc++.h>
using namespace std;

class interpreter {
    vector <string>* tokens;
    string filename;

public:

    interpreter(string name);
    void lexer();
    vector<string> *getTokens() const;
};


#endif //MILESTONE_1_INTERPRETER_H

