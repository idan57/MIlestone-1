# MIlestone-1
Advanced Programming - Course.
Link to Github: https://github.com/idan57/MIlestone-1/settings

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

### void ChangeMap(char* dataFromSim)
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

## CommandCreator
### CommandCreator()
A constructor that initializes a map of Var objects that will later be used to create instances of all available commands.

# Connection
## client
An object that illustrates a client on a certain socket.

### int CreateClient(const char * destAddr, int port)
Binds a client to a socket on the computer and creates a server's address struct to connect to.

### int ConnectToServer()
Connects to the server defined in the constructor.

### void CreateDestAddress(const char \*addr, int port)
Creates a server's address struct to connect to - with address **addr** and port.

### int SendData(string* data)
Sending data to the server the client is connected to.

## server
An object that illustrates a server that listens on a socket.

### int CreateServer()
Creates a server that listens on the port defined in the contructor.

### void CreateConnection()
Waits for a client to connect (until the accept method gets a client's file discriptor).

### void CreateDestAddress()
Create the address that the server will listen on.

### void close()
Close that server connection.

# Expressions

## Expression
An abstract class to represent expressions, each expression will have the following virtual commands:

   * calculate - evaluate the value of the expression
   * ~Expression - destructor
   
## Var
A class that creates objects that represent variables in the **.txt** file given to the Interpter (*another class in the project*).
Each expression has a **value** and a name described as **path**.

###  void SetPath(string p)
Set a name for the variable.

### void SetValue(double val)
Set the value of the variable.

### double GetValue()
Gettung the value of the variable.

## ex1
The implementation of all expression and operation needed for our project to interpert any expression and create an object that calculates its value. The following are the available operators in the project:
   * Plus - + operator
   * Minus - - operator
   * Mul - * operator
   * Div - / operator
   * UPlus - unary + operator
   * UMinus - unary - operator

Also it includes a representation of **Value** (a constant value) and a **Variable** in an expression.

Each class will override the **calculate** method and return the value of the expression recursively.

We also have an **Interpeter** that gets a string and returns an expression by using the **Shunting-Yard** algorithm.
   
   > Explanation regarding the Shunting-Yard algorithm can be found here: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
   
# Extra Methods
A class that contains extra methods that is connected to all other files and objects.

## Extra

### map<string,int>* initializeDirectories()
Creates a map that has all the directoris in the **generic_small.xml** provided to us.

# Interpeter

## interpeter
A class that gets a files and interpets it to a vector of tockens that will later be parsed bu the **Commands**.

### void lexer()
Splits the data in a **.txt** file to tokens.

### vector<string> \*interpreter::getTokens()
Returns a pointer to the tokens.
   
# SymbolTable

## SymbolTable
A class that reprsents a table that contains all the data needed for the commands to run properly, the following are the data contained in this object:
   * variables - the variables that are found in the **.txt** file
   * directories - the directories of all the data that can be altered on the **FlightGear Simulator**.
   * ServerUpdate - all the directories that the server can get data from and update the related variables that we have.
   * ClientUpdate - the directories that the client can alter on the simulator.
   
