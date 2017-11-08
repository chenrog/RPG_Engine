cmake_minimum_required(VERSION 3.8)
project(CS3520_2017FA_PROJ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        model/Units/EnemyUnit.cpp
        model/Units/EnemyUnit.h
        model/Units/IUnit.cpp
        model/Units/IUnit.h
        model/Units/NPCUnit.cpp
        model/Units/NPCUnit.h
        model/Units/PlayerUnit.cpp
        model/Units/PlayerUnit.h
        model/BattleMode.cpp
        model/Equipment/Equipment.cpp
        model/Equipment/Equipment.h
        model/Equipment/EquipType.h
        model/Item.h
        model/Map.cpp
        model/Point.cpp
        model/Point.h
        model/Spell.h
        main.cpp)

add_executable(CS3520_2017FA_PROJ ${SOURCE_FILES})