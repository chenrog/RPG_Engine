cmake_minimum_required(VERSION 3.8)
project(CS3520_2017FA_PROJ)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH "/Users/roger/CLionProjects/CS3520-2017FA-PROJ/cmake/;${CMAKE_MODULE_PATH}")

find_package(SDL2 REQUIRED)
find_package(SDL2IMAGE REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIR})


set(SOURCE_FILES
        src/model/Item/Equipment/Equipment.cpp
        src/model/Item/Equipment/Equipment.h
        src/model/Item/Equipment/EquipType.h
        src/model/Spells/DamageType.h
        src/model/Spells/Spell.cpp
        src/model/Spells/Spell.h
        src/model/Spells/SpellType.h
        src/model/Units/IEntity.cpp
        src/model/Units/IEntity.h
        src/model/Units/EnemyUnit.cpp
        src/model/Units/EnemyUnit.h
        src/model/Units/AUnit.cpp
        src/model/Units/AUnit.h
        src/model/Units/NPCUnit.cpp
        src/model/Units/NPCUnit.h
        src/model/Units/NPCUnitType.h
        src/model/Units/PlayerUnit.cpp
        src/model/Units/PlayerUnit.h
        src/model/Battle/Battle.cpp
        src/model/Battle/Battle.h
        src/model/World/DirectionType.h
        src/model/GameState.h
        src/model/Item/Item.cpp
        src/model/Item/Item.h
        src/model/World/MapCell.cpp
        src/model/World/MapCell.h
        src/model/World/Posn.cpp
        src/model/World/Posn.h
        src/model/World/World.cpp
        src/model/World/World.h
        src/model/World/WorldMap.cpp
        src/model/World/WorldMap.h
        src/main.cpp
        src/view/GameWindow.h
        src/view/GameWindow.cpp
        src/view/battleicons
        test
        proposal.pdf
        README-CHECKPOINT.txt
        README.md
        )

add_executable(CS3520_2017FA_PROJ ${SOURCE_FILES})

target_link_libraries(CS3520_2017FA_PROJ SDL2 SDL_ttf ${SDL_IMAGE_LIBRARY})