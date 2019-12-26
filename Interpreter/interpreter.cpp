//
// Created by liad on 12/12/2019.
//

#include "interpreter.h"
using namespace std;
interpreter::interpreter(string name) {
    this->filename = name;
    this->tokens = new vector<string>;

}

void interpreter::lexer() {
    ifstream input(this->filename);
    string line, token;
    size_t pos = 0;


    while (getline(input, line)) {

        line = regex_replace(line, std::regex("^ +"), "");
        int j = 0;
        while(line[j] != '\0') {

            if (line[j] != ' ' && line[j + 1] == '-' && line[j + 2] == '>' && line[j + 3] != ' ') {

                string s = line.substr(0, j + 1) + ' ' + line[j + 1] + line[j + 2] + ' ' +
                           line.substr(j + 3, line.length() - j - 3);
                line = s;
                break;
            }
            if (line[j] != ' ' && line[j + 1] == '<' && line[j + 2] == '-' && line[j + 3] != ' ') {

                string s = line.substr(0, j + 1) + ' ' + line[j + 1] + line[j + 2] + ' ' +
                           line.substr(j + 3, line.length() - j - 3);
                line = s;
                break;
            }

            if (line[j] != ' ' && (line[j + 1] == '<' || line[j + 1] == '>' || line[j + 1] == '=' || line[j + 1] == '!')
                && line[j + 2] == '=' && line[j + 3] != ' ') {

                string s = line.substr(0, j + 1) + ' ' + line[j + 1] + line[j + 2] + ' ' +
                           line.substr(j + 3, line.length() - j - 3);
                line = s;
                break;
            }
            if (line[j] != ' ' && (line[j + 1] == '=' || line[j + 1] == '>' || line[j + 1] == '<') &&
                line[j + 2] != ' ') {

                string s = line.substr(0, j + 1) + ' ' + line[j + 1] + ' ' + line.substr(j + 2, line.length() - j - 2);
                line = s;
                break;
            }


            j++;
        }

        if (line.substr(0, 5) == "Print" || line.substr(0, 5) == "print") {
            token = line.substr(6, line.length()-7);
            token.erase(
                    remove( token.begin(), token.end(), '\"' ),
                    token.end());
            tokens->push_back(line.substr(0, 5));
            tokens->push_back(token);
            line.erase(0, line.length());
        }

        int i = 0;
        while(line[i] != '\0') {

            if (line[i] == '(' || line[i] == ' ' || line[i] == ')' || line[i] == ',' ||
                    line[i] == '{' || line[i] == '}') {



                if (  line[i] == '{' || line[i] == '}') {
                    token = line[i];
                }
                else {
                    token = line.substr(0, i);
                }
                token.erase(remove(token.begin(), token.end(), '\t'), token.end());
                this->tokens->push_back(token);
                if (token == "=" || token == ">" || token == "<" || token == ">=" || token == "<=" ||
                token == "!=" || token == "==") {
                    token = line.substr(i + 1, line.length() - i - 1);
                    token.erase(remove(token.begin(), token.end(), '\t'), token.end());
                    if (token.find('{') != string::npos) {
                        token.erase(remove(token.begin(), token.end(), '{'), token.end());
                        tokens->push_back(token);
                        string st = "{";
                        tokens->push_back(st);
                    }
                    else {
                        tokens->push_back(token);
                    }
                    line.erase(0, line.length());
                    break;
                } else {
                    line.erase(0, i + 1);
                    i = -1;
                }

            }
            i++;
        }

    }
}

vector<string> *interpreter::getTokens() {
    return tokens;
}
