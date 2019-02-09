#include "LightingSpell.hpp"


using namespace std;

LightingSpell::LightingSpell(string NAME,int PRICE, int MIN_LEVEL, int MIN_DAMAGE, int MAX_DAMAGE, int MAGIC_ENERGY_NEEDED, double AVOID_CHANCE_REDUCER,int ROUNDS): Spell(NAME,PRICE,MIN_LEVEL, MIN_DAMAGE, MAX_DAMAGE,MAGIC_ENERGY_NEEDED,ROUNDS) 
{
    avoid_chance_reducer=AVOID_CHANCE_REDUCER;
}

double LightingSpell::get_ch2a_reducer(){
    return this->avoid_chance_reducer;
}

void LightingSpell::print_info()
{
    Spell::print_info();
    cout.width(20);
    cout << left << avoid_chance_reducer;
    cout.width(10);
    cout << left << rounds << endl;
//    cout << "Opponent's Avoid Chance Reducer: " << avoid_chance_reducer << "% Rounds Lasts: " << rounds << endl << endl;
}

