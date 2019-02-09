#pragma once

#include "Spell.hpp"

class IceSpell : public Spell
{
private:
    int min_damage_REDUCER; // every hero has a range of damage. The range can be described by a minimun and a maximun amount. So when we say that the spell reduces the range, it reduces the minimun and the maximun damage aswell
    int max_damage_REDUCER;
public:
    IceSpell(string NAME,int PRICE, int MIN_LEVEL, int MIN_DAMAGE, int MAX_DAMAGE, int MAGIC_ENERGY_NEEDED, int MIN_DAMAGE_REDUCER, int MAX_DAMAGE_REDUCER, int ROUNDS_WITH_REDUCTION);
    int get_min_dmg_reducer();
    int get_max_dmg_reducer();
    void print_info();
};
