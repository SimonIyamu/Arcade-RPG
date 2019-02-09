//
//  FireSpell.cpp
//  game
//
//  Created by Κωνσταντίνος Πυθαρούλιος on 11/1/18.
//  Copyright © 2018 Κωνσταντίνος Πυθαρούλιος. All rights reserved.
//

#include "FireSpell.hpp"


using namespace std;
//constructor
FireSpell::FireSpell(string NAME,int PRICE, int MIN_LEVEL, int MIN_DAMAGE, int MAX_DAMAGE, int MAGIC_ENERGY_NEEDED, double DEFENCE_REDUCER, int ROUNDS): Spell(NAME,PRICE,MIN_LEVEL, MIN_DAMAGE, MAX_DAMAGE,MAGIC_ENERGY_NEEDED,ROUNDS)
{
    defence_reducer=DEFENCE_REDUCER;
}

double FireSpell::get_def_reducer(){
    return this->defence_reducer;
}

void FireSpell::print_info()
{
    Spell::print_info();
    cout.width(20);
    cout << left << defence_reducer;
    cout.width(10);
    cout << left << rounds << endl;
   // cout << "Opponent's Defence Reducer: "<< defence_reducer << "% Rounds Lasts: " << rounds << endl << endl;
    
}
