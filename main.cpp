#include <iostream>
#include "Interpreter/interpreter.h"
#include "Commands/CommandCreator.h"
#include "Extra Methods/Extra.h"
using namespace std;
#define NUM_OF_THREADS 2

int main(int argc, char* argv[]) {
    thread t1;
    thread t2;
    bool catched = false;
    try {
        interpreter *interpreter_flight = new interpreter(argv[1]);
        vector<string> *interpeted = new vector<string>;
        bool there_are_more_commands = true;
        interpreter_flight->lexer();

        // Adding variable for straight flight
        interpeted->push_back("var");
        interpeted->push_back("br");
        interpeted->push_back("->");
        interpeted->push_back("sim");
        interpeted->push_back("/controls/gear/brake-right");

        // Getting all the tokens
        interpeted = interpreter_flight->getTokens();

        // Number of elements to iterate over
        CommandCreator *cr = new CommandCreator();
        map<string, Command *> *creator = cr->getCreator();


        // Temporary Command variable
        Command *c;
        vector<Command *> *all_commands = new vector<Command *>;
        map<string, Command *> *variables_commands = new map<string, Command *>;
        SymbolTable *symTable = new SymbolTable();

        // Iteration and creation of all commands in the program.
        while (interpeted->size() > 0) {

            // We create a copy of the Command
            if (creator->find(interpeted->at(0)) != creator->end()) {
                c = creator->find(interpeted->at(0))->second->copy(interpeted,
                                                                   symTable);
                all_commands->push_back(c);
            }
            if (interpeted->at(0) == "openDataServer") { // server
                c->execute();
                t1 = thread(&OpenDataServer::ReadingMode,
                            ((OpenDataServer *) c),
                            ((OpenDataServer *) c)->getServerConnection()
                                    ->GetClientSocket(),
                            &there_are_more_commands);
            } else if (interpeted->at(0) == "connectControlClient") { // client
                c->execute();
                t2 = thread(&ConnectCommand::UpdatingMode,
                            ((ConnectCommand *) c), &there_are_more_commands);
            } else if (interpeted->at(0) == "var") { // add variable
                variables_commands->insert({interpeted->at(1), c});
                c->execute();
            }
                // It is an existing variable
            else if (variables_commands->find(interpeted->at(0)) !=
                     variables_commands->end()) {
                c = variables_commands->find(interpeted->at(0))->second;
                c->execute();
            } else { // execute any other command
                c->execute();
            }
        }

        // There are no more commands to execute
        there_are_more_commands = false;
    } catch(const char* c) {
        t1.join();
        t2.join();
        catched = true;
    } catch (std::invalid_argument e) {
        t1.join();
        t2.join();
        catched = true;
    }
    if (!catched) {
        t1.join();
        t2.join();
    }
    // Join the treads of the server and the client.
    return 0;
}

