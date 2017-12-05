#include <random>
#include "Battle.h"

void Battle::doBattle(PlayerUnit* p, EnemyUnit* e, unsigned int attack) {
    auto playerFirst = p->get_dex() > e->get_dex();

    // player goes first
    if (playerFirst) {

        // enemy gets hit
        e->takeDamage(p->getSpell(attack), p);

        // if enemy is alive, they attack
        if (e->get_health() > 0) {
//            std::random_device rd;
//            std::mt19937 mt(rd());
//            std::uniform_real_distribution<int> dist(0, (int) e->getSpells().size());
            int spell = 0;
            // player takes damage
            p->takeDamage(e->getSpell(spell), e);
        }
    }

    // enemy goes first
    else {
        cout<<"ENEMY FIRST"<<endl;

        // player gets hit
        std::random_device rd;
        std::mt19937 mt(rd());
        cout<<"SPell aqwfwqfqwssigned"<<endl;
        std::uniform_real_distribution<int> dist(0, (int) e->getSpells().size());
        cout<<"SPell assigned"<<endl;

        int spell = dist(mt);

        // player takes damage
        p->takeDamage(e->getSpell(spell), e);

        // if player is alive, they attack
        if (p->get_health() > 0) {
            e->takeDamage(p->getSpell(attack), p);
        }
    }
}
