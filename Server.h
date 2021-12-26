//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_SERVER_H
#define UNTITLED9_SERVER_H

#include "ClientHandler.h"

class Server {
public:
    virtual void open(int port, ClientHandler* clientHandler) = 0;

    virtual bool stop() = 0;

    static  void* start(void* myParams );
};

#endif //UNTITLED9_SERVER_H
