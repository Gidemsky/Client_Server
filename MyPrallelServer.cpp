//
// Created by gideon on 08/01/19.
//

#include <unistd.h>
#include <string>
#include "MyPrallelServer.h"

struct Server
{
    char* read();
};

struct ClientHandler
{
    char input[256];
    void handle(int s)
    {
        read(s, input, 255);
    }
};

struct Parameters {
    int port;
    int hz;
    int socket;
};

typedef struct Parameters Parameters;

/**
 * Read data from the server, according to the binds in the xml.
 * @param pparams
 * @return
 */
void *MyPrallelServer::readFromServer(void *pparams) {
    auto *p = (struct Parameters *) pparams;
    Parameters params;
    params.hz = p->hz;
    params.port = p->port;
    params.socket = p->socket;
    delete p;
    std::string buffer;
    char c;
    ssize_t n = 0;

    while (true) {
        do {
            n = read(params.socket, &c, 1);
            buffer += c;
            if (n < 0) {
                perror("Eroor reading from socket");
                exit(1);
            }   else if (n == 0)    {
                exit(1);
            }
        } while (c != '\n');
        //data.setPathValues(buffer);
        buffer = "";
    }
}

/**
 * Execute. the function opens a socket and the pthread
 * in order to read from the server.
 * @return
 */
void MyPrallelServer::open(int port, ClientHandler c) {
    pthread_t pthread;
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr{}, cli_addr{};
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
     * go in sleep mode and will wait for the incoming connection */
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    // A client is accepted
    auto param = new Parameters{};
    param->socket = newsockfd;
    param->hz = hz;
    param->port = port;
    pthread_create(&pthread, nullptr, readFromServer, param);
}