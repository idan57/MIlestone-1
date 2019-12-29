# MIlestone-1
Advanced Programming - Course

# Commands
## Command - abstract class

The main class that all other command object inherit from.
It contains the following abstract method:

    * virtual int execute() - parsing the interpeted tokens and exectuting the command.
    * virtual Command* copy(vector<string>* inter, SymbolTable* symT) - copying the command (factory design pattern).

Also there are the following commands that provide more functionalities to the object:

    * vector<string>* parse(int n) - parses the interpeted tokens.
    * vector<double>* splitNums(char* data, char delimeter) - spits a string by a given delimeter.
    * void UpdateVariables(vector<double>* updatedVars, char SerOrCli) - updates the variables' map according to the values in a given vector.
    * bool Condition (double var, double val, string op) - check if a condition op is met.
    * Expression* setVar(string s) - gets a string and returns the expression it represents.


The following classes inherit from this class:

    * ConnectCommand
    * DefineVarCommand
    * IfCommand
    * OpenDataServer
    * PrintCommand
    * Sleep
    * WhileCommand

## ConnectCommand
### int execute()
Opens a client, connects to the **FlightGear Simulator** and sending data to it.

### void OpenClientConnection()
Creates the client.

### void UpdatingMode(bool \*there_are_more_commands)
Connecting to the **FlightGear Simulator** and sending data until "there_are_more_commands" is False.

## DefineVarCommand
### int execute()
Defines a new Var by parsing on the interpeted data and inserts it into the variables map.

## IfCommand
### int execute()
Initiates an If condition, if the condition is met it executes the commands defined in a certain block.

## OpenDataServer
### int execute()
By using the data that was interpeted, it opens a server that listens on a given port and gets data from the **FlightGear Simulator**.

### void OpenServerConnection(int port)
Open a server on a given port and waits for a connection from a client.

### void ReadingMode(int client_connected ,bool* there_are_more_commands)
Geting data from the **FlightGear Simulator** and udpdating the needed variables accordingly.

## void ChangeMap(char* dataFromSim)
Updating the data from the simulator according to the data it sent.

## PrintCommand
### int execute()
Parses the data that was interpeted and then prints on screen what that is needed.

## Sleep
### int execute()
Uses the **std::this_thread::sleep_for** method to stop all threads for a certain time.

## WhileCommand
### int execute()
Works like the IfCommand, but it stops when the iteration's condition is not met.

