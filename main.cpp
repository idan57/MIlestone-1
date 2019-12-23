#include <iostream>
#include "Interpreter/interpreter.h"
#include "Commands/CommandCreator.h"
#include "Extra Methods/Extra.h"
using namespace std;
#define NUM_OF_THREADS 2

int main(int argc, char* argv[]) {
    interpreter* interpreter_flight = new interpreter(argv[1]);
    vector<string>* interpeted;
    bool there_are_more_commands = true;
    interpreter_flight->lexer();
    interpeted = interpreter_flight->getTokens();
    // Iteration index
    int index = 0;

    // Number of elements to iterate over
    CommandCreator* cr = new CommandCreator();
    map<string, Command*>* creator = cr->getCreator();
    thread t[NUM_OF_THREADS];

    // Temporary Command variable
    Command* c;
    vector<Command*>* all_commands = new vector<Command*>;
    map<string, Command*>* variables_commands = new map<string, Command*>;

    // Iteration and creation of all commands in the program.
    while (interpeted->size() > 0) {
        c = creator->find(interpeted->at(index))->second->copy(interpeted);
        if (interpeted->at(index).compare("openDataServer")) {
            c->execute();
            t[0] = thread(&OpenDataServer::ReadingMode, ((OpenDataServer*)c),
                          ((OpenDataServer*)c)->getServerConnection()
                          ->GetClientSocket(), &there_are_more_commands);
            all_commands->push_back(c);
        }
        else if (interpeted->at(index).compare("connectControlClient")) {
            c->execute();
            t[1] = thread(&ConnectCommand::UpdatingMode, ((ConnectCommand*)c),
                          ((ConnectCommand*)c)->getClientConnection()
                          ->GetDestAddress(), &there_are_more_commands);
            all_commands->push_back(c);
        }
        else if (c != nullptr) {
            if (interpeted->at(index).compare("var")) {
                variables_commands->insert({interpeted->at(index + 1), c});
            }
            all_commands->push_back(c);
            c->execute();
        }
        // It is an existing variable
        else {
            c = variables_commands->find(interpeted->at(index))->second;
            c->execute();
        }
    }
    there_are_more_commands = false;
    t[0].join();
    t[1].join();
    return 0;
}

