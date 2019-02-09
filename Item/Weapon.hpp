#pragma once

#include "Item.hpp"
#include "../Living/Monster/Monster.hpp"

using namespace std;

class Weapon : public Item
{
private:
    int damage; //the number of damage weapon makes
    bool hand; // 0: one handen weapon 1: double handed weapon
public:
    Weapon(string NAME,int PRICE, int MIN_LEVEL, int DAMAGE, bool HAND); //constructor
    void hit (int DAMAGE, Monster& MONSTER);
    
    void print_info();
    bool get_hand();
    int get_damage();
};
