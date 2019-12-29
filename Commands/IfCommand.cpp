//
// Created by liad on 21/12/2019.
//

#include "IfCommand.h"

int IfCommand::execute() {

    int numOfTokens = 0;
    int i = 1;
    string var;
    string val;

    vector<string>::iterator it;

    for (it = this->interperted->begin(); it != this->interperted->end(); it++) {

        if (*it == "{") {
            break;
        }
        numOfTokens++;
    }

    vector<string> *ifParsed = this->parse(numOfTokens);

    while ((ifParsed->at(i) != "==") && (ifParsed->at(i) != "!=") && (ifParsed->at(i) != ">=")
           && (ifParsed->at(i) != "<=") && (ifParsed->at(i) != ">") && (ifParsed->at(i) != "<")) {
        var += ifParsed->at(i);
        i++;
    }
    string op = ifParsed->at(i);

    while (ifParsed->at(i+1) != "{") {
        val = ifParsed->at(i+1);
        i++;
    }

    int numToExecute = 0;
    for (it = this->interperted->begin(); it != this->interperted->end(); it++) {

        if (*it == "}") {
            this->interperted->erase(it);
            break;
        }
        numToExecute++;
    }



    Expression *exVar = nullptr;
    Expression *exVal = nullptr;
    var.erase(std::remove_if(var.begin(), var.end(), ::isspace), var.end());
    exVar = this->setVar(var);
    val.erase(std::remove_if(val.begin(), val.end(), ::isspace), val.end());
    exVal = this->setVar(val);
 
    if (!Condition(exVar->calculate(),exVal->calculate(),op)) {
        vector<string > *deleteParsed  = this->parse(numToExecute - 1);
    }

}
