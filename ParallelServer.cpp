//
// Created by gideon on 09/01/19.
//

#include "ParallelServer.h"
#include <iostream>
#include <sys/types.h>
#include <algorithm>
#include <unistd.h>
#include <list>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <cerrno>
#include <stack>
#include <string>
#include <iostream>
#include <netinet/in.h>

using namespace std;

struct thread_data {
    int sock;
    IClientHandler *ch;
};

void ParallelServer::open(int port, IClientHandler *clientHandler) {
    this->port = port;
    this->clientHandler = clientHandler;
    int server_fd;
    struct sockaddr_in address{};
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    int n = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(int));
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        perror("socket bind");
        exit(1);
    }

    if (listen(server_fd, 5) == -1) {
        perror("socket listen");
        exit(1);
    }

    start(server_fd, clientHandler);
//    rc = pthread_create(&thread, nullptr, start, my_thread_data);
//    if (rc) {
//        cout << "Error! unable to create thread";
//        exit(1);
//    }
}

bool ParallelServer::stop() {
    cout << "lalal" << endl;//TODO: check what needed to be in this function
}

void *start_thread_client(void *params) {
    auto data = (thread_data *) params;
    data->ch->handleClient(data->sock);
    delete data;
}

void ParallelServer::start(int server_sock, IClientHandler *ch) {
    stack<pthread_t> threads_stack;
    sockaddr_in address{};
    int addrlen = sizeof(address);

    timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    setsockopt(server_sock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

    int new_socket;
    while (true) {
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;
        setsockopt(server_sock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        if ((new_socket = accept(server_sock,
                                 (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
                cout << "timeout" << endl;
                break;
            }
            perror("accept");
            exit(EXIT_FAILURE);
        }
        setsockopt(new_socket, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

        auto data = new thread_data;
        data->ch = ch;
        data->sock = new_socket;
        pthread_t trid;
        if (pthread_create(&trid, nullptr, start_thread_client, data) < 0) {
            perror("error on creating thread");
            exit(1);
        }

        threads_stack.push(trid);

    }

    while (!threads_stack.empty()) {
        pthread_join(threads_stack.top(), nullptr);
        threads_stack.pop();
    }

    close(server_sock);
}
