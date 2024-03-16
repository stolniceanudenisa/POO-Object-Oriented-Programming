cmake_minimum_required(VERSION 3.23)
project(Lab7_8final)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab7_8final main.cpp  tranzactie.cpp tranzactie.h
        repo.h repo.cpp teste.h teste.cpp
        UI.h UI.cpp service.cpp service.h)
