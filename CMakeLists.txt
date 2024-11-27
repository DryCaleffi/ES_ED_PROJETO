cmake_minimum_required(VERSION 3.29)
project(Projeto C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projeto
    BinaryTree.c
    BinaryTree.h
    DataBase.c
    DataBase.h
    DoubleLinkedList.c
    DoubleLinkedList.h
    main.c
    MashUp.c
    MashUp.h)
