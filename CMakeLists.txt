cmake_minimum_required(VERSION 3.8)
project(CS3520_2017FA_PROJ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Equipment.cpp
        Equipment.h
        IUnit.cpp
        IUnit.h
        PlayerUnit.h
        PlayerUnit.cpp
        Map.cpp
        Spell.h
        main.cpp EquipType.h)

add_executable(CS3520_2017FA_PROJ ${SOURCE_FILES})