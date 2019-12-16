//
// Created by idan on 12/12/2019.
//

#ifndef MILESTONE_1_DEFINEVARCOMMAND_H
#define MILESTONE_1_DEFINEVARCOMMAND_H



class DefineVarCommand : public  Command {

    int clientVar = 0;
    int serverVar = 0;
public:
    int execute();


};

#endif //MILESTONE_1_DEFINEVARCOMMAND_H
