
#include "ParallelServer.h"
#include "ClientHandler.h"
#include "FileCacheManager.h"
#include "Stringable.h"

#define PORT 1

/**
 * Main
 * @param argc is number of arguments
 * @param argv is the arguments. Needs to include the port
 * value for the server.
 * @return
 */
int main(int argc, char *argv[]) {
    int port = atoi(argv[PORT]);
    ParallelServer server = ParallelServer();
    ICacheManager<Stringable,Stringable> *cache= new FileCacheManager();
    ClientHandler* client_handler = new ClientHandler(cache);
    server.open(port, client_handler);
    cache->saveMap();
    delete client_handler;
    delete cache;
    return 0;
}