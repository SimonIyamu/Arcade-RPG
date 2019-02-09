#include <iostream>
#include "Living.hpp"

using namespace std;

//constructor
Living::Living(string NAME, int LEVEL, int HEALTHPOWER)
{
    name=NAME;
    level=LEVEL;
    max_HP=healthPower=HEALTHPOWER;
}


void Living::set_name(string n){
   this->name=n;
}

void Living::set_HP(int hp){
   this->healthPower=hp;
}

int Living::get_level(){
   return this->level;
}

int Living::get_HP(){
   return this->healthPower;
}

int Living::get_max_HP(){
   return this->max_HP;
}

string Living::get_name(){
   return this->name;
}

void Living::change_healthPower(int quantity)
{
    healthPower+=quantity;
}

void Living::recover_HP(double percentage){
   if(healthPower!=max_HP)
      if(healthPower + max_HP*percentage < max_HP){
         cout << name << " recovered " << max_HP*percentage << " HP.\n";
         healthPower=(healthPower + max_HP*percentage);
      }
      else{
         cout << name << " recovered to full HP.\n";
         healthPower=max_HP; 
      }
}
