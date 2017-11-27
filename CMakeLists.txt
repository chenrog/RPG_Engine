cmake_minimum_required(VERSION 3.8)
project(CS3520_2017FA_PROJ)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH "/Users/roger/CLionProjects/CS3520-2017FA-PROJ/cmake/;${CMAKE_MODULE_PATH}")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES
        src/model/Equipment/Equipment.cpp
        src/model/Equipment/Equipment.h
        src/model/Equipment/EquipType.h
        src/model/Spells/DamageType.h
        src/model/Spells/Spell.cpp
        src/model/Spells/Spell.h
        src/model/Spells/SpellType.h
        src/model/Spells/TargetType.h
        src/model/Units/AEntity.cpp
        src/model/Units/AEntity.h
        src/model/Units/EnemyUnit.cpp
        src/model/Units/EnemyUnit.h
        src/model/Units/IUnit.cpp
        src/model/Units/IUnit.h
        src/model/Units/NPCUnit.cpp
        src/model/Units/NPCUnit.h
        src/model/Units/NPCUnitType.h
        src/model/Units/PlayerUnit.cpp
        src/model/Units/PlayerUnit.h
        src/model/BattleMode.cpp
        src/model/BattleMode.h
        src/model/Direction.h
        src/model/GameState.h
        src/model/Item.cpp
        src/model/Item.h
        src/model/MapCell.cpp
        src/model/MapCell.h
        src/model/Point.cpp
        src/model/Point.h
        src/model/World.cpp
        src/model/World.h
        src/model/WorldMap.cpp
        src/model/WorldMap.h
        src/main.cpp
        proposal.pdf
        README-CHECKPOINT.txt
        README.md)


set(SOURCE_FILES src/main.cpp)

add_executable(CS3520_2017FA_PROJ ${SOURCE_FILES})
target_link_libraries(CS3520_2017FA_PROJ ${SDL2_LIBRARY})