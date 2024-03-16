cmake_minimum_required(VERSION 3.23)
project(111_iteratia_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(111_iteratia_2
        "111-iteratia 2.cpp"
        Repo.cpp
        Repo.h
        RepoTemplate.h
        Service.cpp
        Service.h
        Student.cpp
        Student.h
        Teste.cpp
        Teste.h
        UI.cpp
        UI.h)
