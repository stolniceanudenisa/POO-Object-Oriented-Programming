cmake_minimum_required(VERSION 3.23)
project(Lab_5_14)

set(CMAKE_CXX_STANDARD 14)

include_directories(Solution/Repositories)
include_directories(Solution/Service)
include_directories(Solution/Tests)
include_directories(Solution/UI)
include_directories(Solution/Utilities)

add_executable(Lab_5_14
        Solution/Repositories/Repository.cpp
        Solution/Repositories/Repository.h
        Solution/Repositories/RepositoryCSV.cpp
        Solution/Repositories/RepositoryCSV.h
        Solution/Repositories/RepositoryFile.cpp
        Solution/Repositories/RepositoryFile.h
        Solution/Repositories/RepositoryHTML.cpp
        Solution/Repositories/RepositoryHTML.h
        Solution/Repositories/RepositoryMemory.cpp
        Solution/Repositories/RepositoryMemory.h
        Solution/Repositories/RepositorySQL.cpp
        Solution/Repositories/RepositorySQL.h
        Solution/Service/Service.cpp
        Solution/Service/Service.h
        Solution/Tests/tests.cpp
        Solution/Tests/tests.h
        Solution/UI/GUI.cpp
        Solution/UI/GUI.h
        Solution/UI/TurretsTableView.cpp
        Solution/UI/TurretsTableView.h
        Solution/UI/UI.cpp
        Solution/UI/UI.h
        Solution/Utilities/Domain.cpp
        Solution/Utilities/Domain.h
        Solution/Utilities/DynamicArray.h
        Solution/Utilities/Exceptions.cpp
        Solution/Utilities/Exceptions.h
        Solution/Utilities/SettingsParser.cpp
        Solution/Utilities/SettingsParser.h
        Solution/Utilities/Utils.cpp
        Solution/Utilities/Utils.h
        Solution/Utilities/Validator.cpp
        Solution/Utilities/Validator.h
        Solution/main.cpp)
