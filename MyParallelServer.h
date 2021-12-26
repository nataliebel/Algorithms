//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_MYPARALLELSERVER_H
#define UNTITLED9_MYPARALLELSERVER_H

#include "Server.h"
#include <iostream>
#include <sys/types.h>
#include <algorithm>
#include <unistd.h>
#include <list>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <netinet/in.h>

using namespace std;
struct thread_data {
    int new_sock;
    ClientHandler *ch;
};

class MyParallelServer: public Server{
    int port;
    ClientHandler* clientHandler;
    vector<pthread_t> victor;
    int server_fd;
public:
    void open(int port, ClientHandler* clientHandler) override;

    bool stop() override;

    static void* start(void* myParams);
};

#endif //UNTITLED9_MYPARALLELSERVER_H
