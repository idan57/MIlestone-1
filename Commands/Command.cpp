
#include "Command.h"

// Parses the text we lexered beforehand until the index n.
vector<string*>* Command::parse(int n) {

    // The parsed data in a vector.
    vector<string*>* parsed = new vector<string*>;
    int i = 1;

    // Iterating
    for(auto curr = (*this->interperted).begin(); i <= n; i++, curr++) {
        parsed->push_back(*curr);
    }
    return parsed;
}

// Splitting data by a delimeter
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
        int serverLen = this->ServerUpdate->size();
        for(int i = 0; i < serverLen; i++) {
            // Dir to update
            string* dirToUpdate = (*this->ServerUpdate)[i];

            // Get the location in the vector that is needed to be updated
            int locationOfNewVal = (*this->directories)[dirToUpdate];

            // Update Variable
            (*this->variables)[dirToUpdate]->SetValue
            ((*updatedVars)[locationOfNewVal]);
        }
    }

    // Update Client
    if (SerOrCli == 'c') {
        int serverLen = this->ClientUpdate->size();
        for(int i = 0; i < serverLen; i++) {
            string* dirToUpdate = (*this->ClientUpdate)[i];
            int locationOfNewVal = (*this->directories)[dirToUpdate];
            (*this->variables)[dirToUpdate]->SetValue
                    ((*updatedVars)[locationOfNewVal]);
        }
    }
    locker.unlock();
}