cmake_minimum_required(VERSION 3.22)
project(ee205_lab_10d_animal_farm_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_lab_10d_animal_farm_3
        main.cpp                config.h
        Cat.cpp                 Cat.h
        Animal.cpp              Animal.h
        Mammal.cpp              Mammal.h
        Node.cpp                Node.h
        List.cpp                List.h
        SinglyLinkedList.cpp    SinglyLinkedList.h
        Weight.cpp              Weight.h
        Gender.h                Color.h)

