#pragma once

#include "Spell.hpp"

class FireSpell : public Spell
{
private:
    double defence_reducer; // this reduces the amount of defence of the opponent
public:
     FireSpell(string NAME,int PRICE, int MIN_LEVEL, int MIN_DAMAGE, int MAX_DAMAGE, int MAGIC_ENERGY_NEEDED,double DEFENCE_REDUCER, int ROUNDS);
    double get_def_reducer();
    void print_info();
};
