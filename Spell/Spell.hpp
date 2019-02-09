#pragma once

#include <string>
#include <iostream>

using namespace std;

class Spell
{
protected:
    string name; //the name of spell
    int price; //how much the spell costs
    int min_level; // the minimul level a hero should be to use it
    int min_damage; // the minimum amount of damage the spell can cause
    int max_damage; // the maximun amount of damage the spell can cause
    int rounds;
    int magic_energy_needed; // how much magic energy must the hero have to use the filter
    bool currentlyusing; // 0: not in use currently |1: currently in use
public:
    Spell(string NAME,int PRICE, int MIN_LEVEL, int MIN_DAMAGE, int MAX_DAMAGE, int MAGIC_ENERGY_NEEDED, int ROUNDS);
    
    virtual void print_info();
    
    string get_name();
    int get_price();
    int get_min_level();
    int get_min_damage();
    int get_max_damage();
    int get_rounds();
    int get_magic_energy_needed();
    bool get_currentlyusing();
    void set_currentlyusing();
    
    virtual ~Spell();
};

//geia
