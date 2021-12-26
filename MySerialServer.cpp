//
// Created by oriya on 1/3/19.
//

#include "MySerialServer.h"
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
#include <netinet/in.h>


using namespace std;


struct thread_data {
    int port;
    int new_sock;
    int socket;
    struct sockaddr_in address;
    ClientHandler *ch;
};

void MySerialServer::open(int port, ClientHandler *clientHandler) {
    this->port = port;
    this->clientHandler = clientHandler;
    pthread_t thread;
    int rc;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(server_fd, (struct sockaddr *) &address, sizeof(address));
    thread_data *my_thread_data = new thread_data();
    my_thread_data->port = this->port;
    my_thread_data->new_sock = new_socket;
    my_thread_data->socket = server_fd;
    my_thread_data->address = address;
    my_thread_data->ch = this->clientHandler;
    rc = pthread_create(&thread, nullptr, start, my_thread_data);
    if (rc) {
        cout << "Error! unable to create thread";
        exit(1);
    }
}


bool MySerialServer::stop() {

}

void *MySerialServer::start(void *myParams) {
    struct thread_data *my_data;
    my_data = (thread_data *) myParams;
    int port = my_data->port;
    int new_socket = my_data->new_sock;
    int sock = my_data->socket;
    struct sockaddr_in address = my_data->address;
    int addrlen = sizeof(address);
    //!=stop
    while (true) {
        listen(sock, 5);

        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;

        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        (new_socket = accept(sock, (struct sockaddr *) &address,
                             (socklen_t *) &addrlen));
        if (new_socket < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                exit(2);
            } else {
                perror("accept");
                exit(EXIT_FAILURE);
            }
        }
        my_data->ch->handleClient(new_socket);
    }
    close(sock);
}
