#include <iostream>
#include "Sorcerer.hpp"

using namespace std;

//Sorcerer base stats:
   //HP: 150
   //MP: 250
   //STR: 10
   //DEX: 80
   //AGI: 20%


Sorcerer::Sorcerer() : Hero("",1,150,250,10,80,0.2){ 
   string name;
   cout << "Enter a username for your Sorcerer: ";
   cin >> name;
   this->set_name(name);
}

void Sorcerer::level_up()
{
   experience-=exp_to_level_up;
   level++;
   max_HP += 90;
   max_MP += 120;
   strength += 2;
   dexterity += 60;
   agility += agility*0.05;
   exp_to_level_up += 5*level;
   cout << "Congratulations! Your hero " << name << " just reached " << level << " Level!\n";
}

Sorcerer::~Sorcerer(){
   cout << "LOG: A Sorcerer was destroyed\n";
}
