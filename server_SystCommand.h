//
// Created by leobellaera on 27/9/19.
//

#ifndef TP_SYSTCOMMAND_H
#define TP_SYSTCOMMAND_H

#include "server_Command.h"
#include <map>
#include <string>

class SystCommand : public Command {
private:
    std::map<std::string, std::string> &cfg;
    Login& login;
public:
    SystCommand(std::map<std::string, std::string> &cfg, Login& login);
    std::string execute() override;
    ~SystCommand() override;
};


#endif //TP_SYSTCOMMAND_H
