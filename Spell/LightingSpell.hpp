#pragma once

#include "Spell.hpp"

class LightingSpell : public Spell
{
private:
    double avoid_chance_reducer; //this reduced the chance of the opponent to avoid a hit, is is described by %
public:
    LightingSpell(string NAME,int PRICE, int MIN_LEVEL, int MIN_DAMAGE, int MAX_DAMAGE, int MAGIC_ENERGY_NEEDED, double AVOID_CHANCE_REDUCER,int rounds);
    double get_ch2a_reducer();
    void print_info();
};
