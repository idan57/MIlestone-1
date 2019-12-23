#include <iostream>
#include "Interpreter/interpreter.h"
#include "Commands/CommandCreator.h"

using namespace std;

int main(int argc, char* argv[]) {
    interpreter* interpreter_flight = new interpreter(argv[1]);
    vector<string>* interpeted;
    CommandCreator* command_creator = new CommandCreator();
    interpreter_flight->lexer();
    interpeted = interpreter_flight->getTokens();
    thread exec(&CommandCreator::Execution, command_creator, interpeted);
    exec.join();
    return 0;
}

