#include "Potion.hpp"

//constructor
Potion::Potion(string NAME, int PRICE, int MIN_LEVEL, double INCREASEMENT,Stat s): Item(NAME, PRICE, MIN_LEVEL),used(0),increasement(INCREASEMENT),stat(s){ }

void Potion::print_info() 
{
    Item::print_info();
    cout.width(15);
    switch(stat){
       case 0:
          cout <<left<< "Strength";
          break;
       case 1:
          cout <<left<< "Dexterity";
          break;
       case 2:
          cout << left<< "Agility";
          break;
       case 3:
          cout << left <<"Health Power";
          break;
       case 4:
          cout << left <<"Magic Power";
          break;
    }
    cout.width(15);
    cout << left << increasement*100 <<endl;
}

Stat Potion::get_stat(){
   return stat;
}

double Potion::get_increasement()
{
    return increasement;
}
