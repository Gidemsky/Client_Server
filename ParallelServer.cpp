
#include "ParallelServer.h"

using namespace std;

struct thread_data {
    int sock;
    IClientHandler *ch;
};

/**
 * open the server
 * @param port
 * @param clientHandler
 */
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
}

bool ParallelServer::stop() {
}

/**
 *
 * @param params
 * @return
 */
void *start_thread_client(void *params) {
    auto data = (thread_data *) params;
    data->ch->handleClient(data->sock);
    delete data;
}

/**
 * starts the connection between the server and the client
 * @param server_sock
 * @param ch
 */
void ParallelServer::start(int server_sock, IClientHandler *ch) {
    stack<pthread_t> threads_stack;
    sockaddr_in address{};
    int addrlen = sizeof(address);
    //defines the timeout
    timeval timeout;
//    timeout.tv_sec = 10;
//    timeout.tv_usec = 0;
//    setsockopt(server_sock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

    int new_socket;
    //runs the function and collects the client's problems using threads
    while (true) {
        new_socket = accept(server_sock, (struct sockaddr *) &address, (socklen_t *) &addrlen);
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(server_sock, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        if (new_socket < 0) {
            if (errno == EWOULDBLOCK || errno == EAGAIN) {
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
