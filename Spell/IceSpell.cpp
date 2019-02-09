//
//  IceSpell_Spell.cpp
//  game
//
//  Created by Κωνσταντίνος Πυθαρούλιος on 11/1/18.
//  Copyright © 2018 Κωνσταντίνος Πυθαρούλιος. All rights reserved.

#include "IceSpell.hpp"

using namespace std;

IceSpell::IceSpell(string NAME,int PRICE, int MIN_LEVEL, int MIN_DAMAGE, int MAX_DAMAGE, int MAGIC_ENERGY_NEEDED, int MIN_DAMAGE_REDUCER, int MAX_DAMAGE_REDUCER, int ROUNDS): Spell(NAME,PRICE,MIN_LEVEL, MIN_DAMAGE, MAX_DAMAGE,MAGIC_ENERGY_NEEDED,ROUNDS)
{
    min_damage_REDUCER=MIN_DAMAGE_REDUCER;
    max_damage_REDUCER=MAX_DAMAGE_REDUCER;
}

void IceSpell::print_info()
{
    Spell::print_info();
    cout.width(20);
    cout << left << min_damage_REDUCER;
    cout.width(20);
    cout << left << max_damage_REDUCER << endl;
//  cout << "Opponent's Minimun Damage Reducer: " << min_damage_REDUCER << "% Opponent's Maximun Damage Reducer: " << max_damage_REDUCER << "% Rounds Lasts: " << rounds_with_reduction << endl << endl;
}

int IceSpell::get_min_dmg_reducer(){
    return this->min_damage_REDUCER;
}

int IceSpell::get_max_dmg_reducer(){
    return this->max_damage_REDUCER;
}
