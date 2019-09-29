//
// Created by leobellaera on 27/9/19.
//

#include "server_ThClient.h"
#include "server_Command.h"
#include "common_SocketException.h"
#include <iostream>

#define QUIT_COMMAND "QUIT"

ThClient::ThClient(Socket skt, std::map<std::string,std::string> &cfg, DirectoryOrganizer& dir_org) :
    cfg(cfg),
    login(cfg),
    dir_organizer(dir_org),
    proxy(std::move(skt)),
    finished(false) {}

void ThClient::run() {
    std::string input;
    while (!finished) {
        try {
            this->executeCommand(input);
        } catch (const SocketException& e) {
            finished = true;
            return;
        }
        if (input == QUIT_COMMAND) {
            finished = true;
        }
    }
}

void ThClient::executeCommand(std::string& input) {
    proxy.receiveClientCommand(input);
    Command* command = Command::make_command(cfg, input, login, dir_organizer);
    std::string answer = command->execute();
    proxy.sendAnswerToClient(answer);
    delete command;
}

bool ThClient::isAlive() {
    return !finished;
}

void ThClient::stop() {
    proxy.stopCommunication();
}

ThClient::~ThClient() {}