#pragma once

#include "Item.hpp"

using namespace std;

class Armor : public Item
{
private:
    double damage_reducer; // it shows how much a damage is reduced // double because it is a % reduce
public:
    Armor(string NAME,int PRICE, int MIN_LEVEL, double DAMAGE_REDUCER); //constructor
    void print_info();
    
    double get_damage_reducer();
};
