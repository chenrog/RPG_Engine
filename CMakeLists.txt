cmake_minimum_required(VERSION 3.8)
project(CS3520_2017FA_PROJ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        model/Equipment/Equipment.cpp
        model/Equipment/Equipment.h
        model/Equipment/EquipType.h
        model/BattleMode.cpp
        model/BattleMode.h
        model/Item.cpp
        model/Item.h
        model/Consumable.cpp
        model/Consumable.h
        model/Consumable_Type_t.h
        model/Units/IUnit.cpp
        model/Units/IUnit.h
        model/Units/NPCUnit.cpp
        model/Units/NPCUnit.h
        model/Units/NPCUnitType.h
        model/Units/EnemyUnit.cpp
        model/Units/EnemyUnit.h
        model/Units/PlayerUnit.h
        model/Units/PlayerUnit.cpp
        main.cpp
        model/Point.cpp
        model/Point.h model/Units/AEntity.cpp model/Units/AEntity.h)

add_executable(CS3520_2017FA_PROJ ${SOURCE_FILES})