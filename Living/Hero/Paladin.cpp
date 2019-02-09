#include <iostream>
#include "Paladin.hpp"

using namespace std;

//Paladin base stats:
   //HP: 250
   //MP: 200
   //STR: 70
   //DEX: 70
   //AGI: 5%


Paladin::Paladin() : Hero("",1,250,200,70,70,0.05){ 
   string name;
   cout << "Enter a username for your Paladin: ";
   cin >> name;
   this->set_name(name);
}

void Paladin::level_up()
{
   experience-=exp_to_level_up;
   level++;
   max_HP += 120;
   max_MP += 100;
   strength += 50;
   dexterity += 50;
   agility += agility*0.01;
   exp_to_level_up += 5*level;
   cout << "Congratulations! Your hero " << name << " just reached " << level << " Level!\n";
}

Paladin::~Paladin() {
   cout << "LOG: A Paladin was destroyed\n";
}
