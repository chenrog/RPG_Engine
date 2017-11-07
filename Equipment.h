#ifndef CS3520_2017FA_PROJ_EQUIPMENT_H
#define CS3520_2017FA_PROJ_EQUIPMENT_H

#include <string>
#include <cassert>

using namespace std;

class Equipment {
public:
    friend Equipment & build();

    void level_up();

    void display();

private:
    const string       name;
    unsigned int       level;
    const equip_type_t type;
    // vitality stats by this equipment
    signed int         vit;
    unsigned int       vit_mod;
    // intelligence stats by this equipment
    signed int         intel;
    unsigned int       int_mod;
    // speed stats by this equipment
    signed int         speed;
    unsigned int       speed_mod;
    // strength stats by this equipment
    signed int         str;
    unsigned int       str_mod;

protected:
    enum equip_type_t {Helmet = 0, Armor = 1, Boots = 2, Primary = 3, Offhand = 4};

    Equipment(string name, unsigned int type, signed int v, unsigned int vm, signed int i, unsigned int im,
              signed int sp, unsigned int spm, signed int st, unsigned int stm);
};

#endif //CS3520_2017FA_PROJ_EQUIPMENT_H
