cmake_minimum_required(VERSION 3.13)
project(untitled9)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled9 main.cpp Server.h ClientHandler.h MyClientHandler.cpp MyClientHandler.h
        StringReverseCH.cpp StringReverseCH.h MySerialServer.cpp MySerialServer.h MyParallelServer.cpp
        MyParallelServer.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Solver.h StringReverser.cpp
        StringReverser.h Searchable.h Searcher.h SolverSearcher.h
        Stringable.h MyString.cpp MyString.h Matrix.h State.h SearchableMatrix.cpp
        SearchableMatrix.h MatrixBuilder.cpp MatrixBuilder.h Dfs.cpp Dfs.h Solution.cpp Solution.h
        Point.h Bfs.h BestFirstSearch.h Main.cpp Main.h A_Star.h)