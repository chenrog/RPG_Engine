cmake_minimum_required(VERSION 3.8)
project(CS3520_2017FA_PROJ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        model/Equipment/Equipment.cpp
        model/Equipment/Equipment.h
        model/Equipment/EquipType.h

        model/Spells/DamageType.h
        model/Spells/Spell.cpp
        model/Spells/Spell.h
        model/Spells/SpellType.h
        model/Spells/TargetType.h

        model/Units/AEntity.cpp
        model/Units/AEntity.h
        model/Units/EnemyUnit.cpp
        model/Units/EnemyUnit.h
        model/Units/IUnit.cpp
        model/Units/IUnit.h
        model/Units/NPCUnit.cpp
        model/Units/NPCUnit.h
        model/Units/NPCUnitType.h
        model/Units/PlayerUnit.h
        model/Units/PlayerUnit.cpp

        model/BattleMode.cpp
        model/BattleMode.h
        model/Item.cpp
        model/Item.h
        model/Consumable.cpp
        model/Consumable.h
        model/Consumable_Type_t.h
        model/Direction.h
        model/GameState.h
        model/Item.cpp
        model/Item.h
        model/MapCell.cpp
        model/MapCell.h
        model/Point.cpp
        model/Point.h
        model/World.cpp
        model/World.h
        model/WorldMap.cpp
        model/WorldMap.h

        main.cpp)

add_executable(CS3520_2017FA_PROJ ${SOURCE_FILES})