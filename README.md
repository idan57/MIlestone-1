# MIlestone-1
Advanced Programminh - Course

1. When using UpdateVariables method in Command class - you sould create a vector that is ordered by the paths in 'directories' (field). Then you should iterate on the paths that the client should update (directories - field in Command) and get the index in the vector of the value that is need to be updated in a certain Var.

2. Files to update:
    - Command class:
        * SetVariablesField - through this add variables that are defined in DefineVariableCommand
        * copy - abstract method for copying command instances
        * sleep, ElseCommand, IfCommand, PrintCommand - I added default implementation with the copy method for CommandCreator
        * WhileCommand - also default, but with addVariablesToIter that adds variables to iter on
    - Added CommandCreator - it includes the while loop for executing commands!
    - Expressions - add a field with a string that contains the expression that later will be interperted
    - 



Liad  - please add the interpeted + lexer implementation (as a folder if you can) :)
also all the commands that has no implementations that you created please add (DefineVariable, While, etc.).
