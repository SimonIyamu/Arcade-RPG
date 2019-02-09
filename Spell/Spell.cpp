#include "Spell.hpp"

//constructor
Spell::Spell(string NAME,int PRICE, int MIN_LEVEL, int MIN_DAMAGE, int MAX_DAMAGE, int MAGIC_ENERGY_NEEDED,int ROUNDS): currentlyusing(0)
{
    name=NAME;
    price=PRICE;
    min_level=MIN_LEVEL;
    min_damage=MIN_DAMAGE;
    max_damage=MAX_DAMAGE;
    magic_energy_needed=MAGIC_ENERGY_NEEDED;
    rounds=ROUNDS;
}

int Spell::get_rounds(){
    return this->rounds;
} 

void Spell::print_info()
{
    cout.width(20);
    cout << left << name;
    cout.width(15);
    cout << left << price;
    cout.width(15);
    cout << left <<min_level;
    cout.width(15);
    cout << left << min_damage;
    cout.width(15);
    cout << left << max_damage;
    cout.width(15);
    cout << left << magic_energy_needed;
   // cout << "Name: " << name << " Price: " << price << " Minimun Level: " << min_level << " Minimum Damage: " << min_damage << " Maximun Damage: " << max_damage << " Magic Energy Needed: " << magic_energy_needed << " ";
}

string Spell::get_name()
{
    return name;
}

int Spell::get_price()
{
    return price;
}

int Spell::get_min_level()
{
    return min_level;
}

int Spell::get_min_damage()
{
    return min_damage;
}

int Spell::get_max_damage()
{
    return max_damage;
}

int Spell::get_magic_energy_needed()
{
    return magic_energy_needed;
}

bool Spell::get_currentlyusing()
{
    return currentlyusing;
}

Spell::~Spell()
{
    
}
