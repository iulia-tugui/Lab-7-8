cmake_minimum_required(VERSION 3.21)
project(Lab7_8)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab7_8 main.cpp Domain/Cheltuiala.cpp Domain/Cheltuiala.h Domain/HomemadeVector.cpp Domain/HomemadeVector.h Repository/Repository.cpp Repository/Repository.h Tests/Tests.h Tests/Tests.cpp UI/Console.cpp UI/Console.h UI/ReadOption.cpp UI/ReadOption.h UI/ShowMenu.cpp UI/ShowMenu.h Service/CheltuialaService.cpp Service/CheltuialaService.h)
