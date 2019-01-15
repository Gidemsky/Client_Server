cmake_minimum_required(VERSION 3.13)
project(Client_Server)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(Client_Server main.cpp ClientHandler.cpp ClientHandler.h IClientHandler.h Server.h Solver.h ICacheManager.h SolverSearcher.h ISearcher.h BFS.h Searchable.h State.h Matrix.h Separator.cpp Separator.h FileCacheManager.h ParallelServer.cpp ParallelServer.h DFS.h StringReverseCH.cpp StringReverseCH.h Stringable.h StringableMatrix.cpp StringableMatrix.h SearchableMatrix.h AStar.h StringReverser.h StringReverser.cpp BestFirstSearch.h FileCacheManager.cpp Solution.cpp Solution.h)