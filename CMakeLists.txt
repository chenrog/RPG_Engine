cmake_minimum_required(VERSION 3.8)
project(CS3520_2017FA_PROJ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BattleMode.cpp
        Equipment.h
        Item.h
        IUnit.cpp
        IUnit.h
        PlayerCharacter.cpp
        PlayerCharacter.h
        Equipment.cpp
        main.cpp
        Map.cpp
        proposal.pdf
        README.md
        Spell.h Equipment.cpp)

add_executable(CS3520_2017FA_PROJ ${SOURCE_FILES})