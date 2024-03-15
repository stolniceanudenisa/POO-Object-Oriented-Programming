cmake_minimum_required(VERSION 3.21)
project(sem_6_313)

set(CMAKE_CXX_STANDARD 14)

add_executable(sem_6_313 main.cpp domain/Angajat.cpp domain/Angajat.h repository/ListaDeAngajati.cpp repository/ListaDeAngajati.h util/MyException.cpp util/MyException.h service/Service.cpp service/Service.h)
