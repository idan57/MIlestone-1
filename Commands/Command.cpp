// Parses the text we lexered beforehand until the index n.
#include "Command.h"
using namespace std;

    vector<string>* Command::parse(int n) {
    // The parsed data in a vector.
    vector<string>* parsed = new vector<string>;
    int i = 0;
    for(auto curr = (*this->interperted).begin(); i <= n; i++) {
        parsed->push_back(*curr);
        (*this->interperted).erase(this->interperted->begin());
    }
    return parsed;
}

vector<double> * Command::splitNums(char* data, char delimeter) {
    int numOfVals = 0, i = 0;

    vector<double>* splitted = new vector<double>;
    while(numOfVals < NUM_OF_VALS_FROM_SERVER) {

        stringstream number;
        // Parsing data until we reach ','
        while(data[i] != delimeter && data[i] != '\n') {

            // Appending data to stream
            number << data[i];
            i++;
        }
        string s = number.str();
        // Get the double value of the string in the stream
        if (s != "") {
            splitted->push_back(stod(s));
            numOfVals++;
        }
        i++;
    }
    return splitted;
}

void Command::UpdateVariables(vector<double>* updatedVars, char SerOrCli) {
    stringstream data;
    std::this_thread::sleep_for(std::chrono::milliseconds(1100));
    // Update Server
    if (SerOrCli == 's') {
        int serverLen = symbolTable->ServerUpdate->size();
        for (int i = 0; i < serverLen; i++) {

           string dirToUpdate = (*symbolTable->ServerUpdate)[i];
            int locationOfNewVal = symbolTable->directories->find(dirToUpdate)->second;
            symbolTable->variables->find(dirToUpdate)->second->SetValue
                    ((*updatedVars).at(locationOfNewVal));
        }
    }
}


bool Command::Condition(double var, double val, string op) {
    if (op == "==") {
        return var == val;
    }
    else if (op == "!=") {
        return var != val;
    }
    else if (op == ">=") {
        return var >= val;
    }
    else if (op == "<=") {
        return var <= val;
    }
    else if (op == "<") {
        return var < val;
    }
    else if (op == ">") {
        return var > val;
    }

}

Expression* Command::setVar(string s) {

    Interpreter *i = new Interpreter();
    string ss = string(s);
    stringstream setVar;
    if (symbolTable->variables->size() > 0) {
        stringstream st;
        auto itr = symbolTable->variables->begin();
        while (itr != symbolTable->variables->end()) {
            double d = itr->second->GetValue();
            stringstream num;
            num << d;
            st << itr->second->GetPath() << "=" << (num.str()) << ";";
            itr++;
        }
        i->setVariables(st.str());
    }
    return i->interpret(ss);

}
