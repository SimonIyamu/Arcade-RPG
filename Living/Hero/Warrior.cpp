#include <iostream>
#include "Warrior.hpp"

using namespace std;

//Warrior base stats:
//    HP: 250
//    MP: 100
//    STR: 70
//    DEX: 10
//    AGI: 20%

Warrior::Warrior() : Hero("",1,250,100,70,10,0.2) { 
   string name;
   cout << "Enter a username for your Warrior: ";
   cin >> name;
   this->set_name(name);
}

void Warrior::level_up()
{
   experience-=exp_to_level_up;
  
   level++;
   max_HP += 120;
   max_MP += 50;
   strength += 50;
   dexterity += 2;
   agility += agility*0.05;
   exp_to_level_up += 5*level;
   cout << "Congratulations! Your hero " << name << " just reached " << level << " Level!\n";
}

Warrior::~Warrior(){
  // cout << "LOG: A Warrior was destroyed\n";
}
