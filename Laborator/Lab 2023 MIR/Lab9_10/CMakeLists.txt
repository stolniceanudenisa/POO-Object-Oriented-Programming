cmake_minimum_required(VERSION 3.21)
project(Lab9_10)

set(CMAKE_CXX_STANDARD 14)

include_directories(Domain
        Repository
        Tests
        Service
        UserInterface)

add_executable(Lab9_10
        Repository/Repo.cpp
        Repository/Repo.h
        Domain/Product.cpp
        Domain/Product.h
        app.cpp
        Domain/Money.cpp
        Domain/Money.h
        Service/Service.cpp
        Service/Service.h
        UserInterface/UI.cpp
        UserInterface/UI.h
        Repository/RepoFile.h
        Repository/Repo.h
        Repository/RepoFile.cpp Domain/ProductValidator.h Domain/NotFoundElementException.h Domain/InvalidCodeException.h Domain/MoneyValidator.h Domain/InvalidMoneyValueException.h)
