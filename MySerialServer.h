//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_MYSERIALSERVER_H
#define UNTITLED9_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer: public Server{
    int port;
    ClientHandler* clientHandler;
public:
    void open(int port, ClientHandler* clientHandler) override;

    bool stop() override;

    static void* start(void* myParams);
};
#endif //UNTITLED9_MYSERIALSERVER_H
