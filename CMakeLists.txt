cmake_minimum_required(VERSION 3.13)
project(Client_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Client_Server main.cpp MyClientHandler.cpp MyClientHandler.h ClientHandler.h Server.h MyPrallelServer.cpp MyPrallelServer.h Solver.h ICacheManager.h SolverSearcher.cpp SolverSearcher.h ISearcher.h BFS.cpp BFS.h Searchable.h State.cpp State.h Matrix.h Separator.cpp Separator.h FileCacheManager.h MySerialServer.cpp MySerialServer.h DFS.cpp DFS.h StringReverseCH.cpp StringReverseCH.h Stringable.h StringableMatrix.cpp StringableMatrix.h)