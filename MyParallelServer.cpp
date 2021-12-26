//
// Created by oriya on 1/3/19.
//

#include <thread>
#include "MyParallelServer.h"


void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    this->port = port;
    this->clientHandler = clientHandler;
    pthread_t thread;
    int rc;
    int new_socket, valread;
    struct sockaddr_in address{};
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    int counterClient = 0;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    bind(server_fd, (struct sockaddr *) &address, sizeof(address));
    int addrlen = sizeof(address);
    //!=stop
    while (true) {
        timeval timeout;
        listen(server_fd, 5);
        if (counterClient == 0) {
            timeout.tv_sec = 0;
            timeout.tv_usec = 0;
        } else {
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
        }
        setsockopt(server_fd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        (new_socket = accept(server_fd, (struct sockaddr *) &address,
                             (socklen_t *) &addrlen));
        if (new_socket < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                break;
            } else {
                //perror("accept");
                //exit(EXIT_FAILURE);
                break;
            }
        }

        struct thread_data *my_data = new struct thread_data();
        my_data->new_sock = new_socket;
        my_data->ch = this->clientHandler;
        rc = pthread_create(&thread, nullptr, start, my_data);
        if (rc) {
            cout << "Error! unable to create thread";
            exit(1);
        }
        this->victor.push_back(thread);
        counterClient++;
    }

}


bool MyParallelServer::stop() {
    for (pthread_t thread:this->victor) {
        pthread_join(thread, NULL);
    }
    close(this->server_fd);
}

void *MyParallelServer::start(void *myParams) {
    struct thread_data *my_data;
    my_data = (thread_data *) myParams;
    my_data->ch->handleClient(my_data->new_sock);
    delete (my_data);
}
