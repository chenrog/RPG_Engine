cmake_minimum_required(VERSION 3.8)
project(CS3520_2017FA_PROJ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        model/Equipment.cpp
        model/Equipment.h
        model/Units/IUnit.cpp
        model/Units/IUnit.h
        model/Units/NPCUnit.cpp
        model/Units/NPCUnit.h
        model/Units/EnemyUnit.cpp
        model/Units/EnemyUnit.h
        model/Units/PlayerUnit.h
        model/Units/PlayerUnit.cpp
        model/Map.cpp
        model/Spell.h
        main.cpp
        model/EquipType.h
        model/Point.cpp
        model/Point.h)

add_executable(CS3520_2017FA_PROJ ${SOURCE_FILES})