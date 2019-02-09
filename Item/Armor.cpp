#include "Armor.hpp"

//constructor
Armor::Armor(string NAME,int PRICE, int MIN_LEVEL, double DAMAGE_REDUCER): Item(NAME, PRICE, MIN_LEVEL)
{
    damage_reducer=DAMAGE_REDUCER;
}

void Armor::print_info()
{
    Item::print_info();
    cout.width(15);
    cout <<  left << damage_reducer <<endl;
    //cout << "Hero's Damage from Opponent Reducer: " << damage_reducer << "%" << endl << endl;
}

double Armor::get_damage_reducer()
{
    return damage_reducer;
}

