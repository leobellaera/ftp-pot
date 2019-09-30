//
// Created by leobellaera on 29/9/19.
//

#include <iostream>
#include "client_ClientFtp.h"
#include "common_SocketException.h"

#define INVALID_ARGS_AMOUNT_MSG "Invalid number of arguments"
#define UNKNOWN_ERROR_MSG "An unknown error occurred in the execution"
#define HOST_POS 1
#define SERVICE_POS 2

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout<<INVALID_ARGS_AMOUNT_MSG<<std::endl;
        return 1;
    }
    try {
        ClientFtp client(argv[HOST_POS], argv[SERVICE_POS]);
        client.run();
    } catch (const SocketException& e) {
        return 1;
    } catch (...) {
        std::cerr << UNKNOWN_ERROR_MSG << std::endl;
        return 1;
    }
    return 0;
}
