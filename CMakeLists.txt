cmake_minimum_required(VERSION 3.20)
project(OOP CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
    add_compile_definitions(UNICODE _UNICODE)
    add_compile_options(/utf-8)
endif()

# lab1 (папка OOP)
add_executable(lab1 OOP/lab1.cpp OOP/calculator.cpp OOP/Class.h)

add_executable(lab2
    lab2/main.cpp lab2/Department.cpp lab2/Institute.cpp lab2/University.cpp
    lab2/Department.h lab2/Institute.h lab2/University.h lab2/InputHelper.h)

add_executable(lab3 lab3/main.cpp lab3/Salary.cpp lab3/Salary.h)

add_executable(lab4 lab4/main.cpp lab4/Person.cpp lab4/Person.h)

add_executable(lab5 lab5/main.cpp lab5/FileWorker.cpp lab5/FileWorker.h)
