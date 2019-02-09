

#include "Weapon.hpp"

//constructor
Weapon::Weapon(string NAME,int PRICE, int MIN_LEVEL, int DAMAGE, bool HAND):Item(NAME,PRICE, MIN_LEVEL)
{
    damage=DAMAGE;
    hand=HAND;
}

void Weapon::hit(int DAMAGE, Monster& MONSTER )
{
    DAMAGE= DAMAGE * (-1); //because then we add
    MONSTER.change_healthPower(DAMAGE);
}

void Weapon::print_info()
{
    Item::print_info();
    cout.width(15);
    cout << left << damage;
    cout.width(15);
    cout << left << (hand+1)<<endl;
    //cout << "Damage: " << damage << " Hands Needed: " << (hand+1) << endl << endl;
}

bool Weapon::get_hand()
{
    return hand;
}


int Weapon::get_damage()
{
    return damage;
}
