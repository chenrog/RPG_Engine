
void Unit::takeDamage(const int damage) { }
void castSpell(const Spell spell); // to be figured out later
void Equip(Equipment const equipment);
void addEXP(int const exp);
int getDamage();
Item calcDrop();

/**
 *
 * @param vit
 * @param intel
 * @param dex
 * @param str
 */
Unit(int vit, int intel, int dex, int str);

/**
 *
 * @param vit
 * @param intel
 * @param dex
 * @param str
 * @param equipment
 * @param spell
 */
Unit(int vit, int intel, int dex, int str, Equipment equipment[], Spells spell[]);
