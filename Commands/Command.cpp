// Parses the text we lexered beforehand until the index n.
#include "Command.h"

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
    int i = 0;
    stringstream number;
    vector<double>* splitted = new vector<double>;
    while(data[i] != '\0') {

        // Parsing data until we reach ','
        while(data[i] != delimeter) {

            // Appending data to stream
            number << data[i];
            i++;
        }

        // Get the double value of the string in the stream
        splitted->push_back(stod(number.str()));
        i++;
    }
    return splitted;
}

void Command::UpdateVariables(vector<double>* updatedVars, char SerOrCli) {
    locker.lock();
    // Update Server
    if (SerOrCli == 's') {
        int serverLen = symbolTable->ServerUpdate->size();
        for (int i = 0; i < serverLen; i++) {
            string dirToUpdate = (*symbolTable->ServerUpdate)[i];
            int locationOfNewVal = (*symbolTable->directories)[dirToUpdate];
            (*symbolTable->variables)[dirToUpdate]->SetValue
                    ((*updatedVars)[locationOfNewVal]);
        }
    }
    locker.unlock();
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

Interpreter* Command::setVar() {

    Interpreter *i = new Interpreter();
    string tempVar = nullptr;
    string setVar = "";
    auto itr = symbolTable->variables->begin();
    while (itr != symbolTable->variables->end()) {
        tempVar = itr->second->GetPath() + "=" + to_string((itr->second->GetValue())) + ";";
        setVar += tempVar;
        itr++;
    }
    i->setVariables(setVar);
    return i;
}
