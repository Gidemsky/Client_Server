cmake_minimum_required(VERSION 3.13)
project(Client_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client_Server main.cpp myClientHandler.cpp myClientHandler.h IClientHandler.h Server.h MyPrallelServer.cpp MyPrallelServer.h Solver.h ICacheManager.h SolverSearcher.cpp SolverSearcher.h ISearcher.h BFS.cpp BFS.h Searchable.h State.cpp State.h Matrix.cpp Matrix.h Separater.cpp Separater.h)