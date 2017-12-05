#include "EnemyUnit.h"
#include <random>

EnemyUnit::EnemyUnit() = default;

EnemyUnit::EnemyUnit(unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, bool melee,
                     string name, Item** drops) {
    this->name = std::move(name);
    this->st_vit = vit;
    this->st_int = intel;
    this->st_dex = speed;
    this->st_str = str;
    this->melee = melee;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->drop = drops;
    this->spellList = new Spell*[4];
    this->visible = false;
}

EnemyUnit::EnemyUnit(Posn *posn, unsigned int vit, unsigned int intel, unsigned int speed, unsigned int str, bool melee,
                     string name, Item** drops) {
    this->position = posn;
    this->name = std::move(name);
    this->st_vit = vit;
    this->st_int = intel;
    this->st_dex = speed;
    this->st_str = str;
    this->melee = melee;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->drop = drops;
    this->visible = false;
}

/* UNNECESSARY COPY CONSTRUCTOR
EnemyUnit::EnemyUnit(const EnemyUnit &unit) {
    this->name = name;
    this->st_vit = unit.st_vit;
    this->st_int = unit.st_int;
    this->st_dex = unit.st_dex;
    this->st_str = unit.st_str;
    this->melee = melee;
    updateStats();
    this->health = this->max_health;
    this->mana = this->max_mana;
    this->lvl = 1;
    int i = 0;
    for (Item drop : unit.drop) {
        this->drop[i] = drop;
        i++;
    }
}
 */

EnemyUnit::~EnemyUnit() {
    delete [] drop;
    delete position;
}

Item* EnemyUnit::calcDrop() {
    int random_int = rand() % 4;
    int size = 0;
    while(this->drop[size] != NULL){
        size++;
    }
    while (random_int >= size){
        random_int--;
    }
    return (this->drop)[random_int];
}

