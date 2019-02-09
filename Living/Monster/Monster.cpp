#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "Monster.hpp"

using namespace std;

void Monster::receive_damage(int dmg){
   if(rand()%100/100.0 < this->chance_to_avoid) 
      cout << "The attack was dodged!\n";
   else{
      if(dmg > defence)
         cout << this->name << " lost " << dmg-defence << " HP.\n";
         if(this->get_HP()-dmg+defence < 0){
            this->set_HP(0);
            cout << this->name << " fainted.\n";
         }
         else
            this->set_HP(this->get_HP()-dmg+defence);
   }
}

int Monster::get_min_dmg(){
    return this->min_damage;
}

int Monster::get_max_dmg(){
    return this->max_damage;
}

void Monster::set_min_dmg(int dmg){
    this->min_damage=dmg;
}

void Monster::set_max_dmg(int dmg){
    this->max_damage=dmg;
}
 
int Monster::get_defence(){
    return this->defence;
}

void Monster::set_defence(int d){
    this->defence = d;
}

double Monster::get_ch2a(){
    return this->chance_to_avoid;
}

void Monster::set_ch2a(double chance){
    this->chance_to_avoid=chance;
}

int Monster::attack(){
   if(min_damage != max_damage)  //We are dividing by min - max, hence their difference should not be 0
      return min_damage + rand()%(max_damage - min_damage); //Random damage between min and max
   else
       return min_damage;
}

void Monster::display_monster_stats(){
   cout << fixed << setprecision(3);
   cout << "Name: " << name << endl << "Level: " << level << endl
       << "HP: " << healthPower << endl
       << "Stats: Min Damage:: " << min_damage 
       << ", Max Damage: " << max_damage 
       << ", Defense: " << defence 
       << " Chance to Avoid: " << chance_to_avoid << endl;
}

Monster::Monster(string name,int level, int hp,int min_d,int max_d,int def,double ch2a) : min_damage(min_d), max_damage(max_d) , defence(def), chance_to_avoid(ch2a), Living (name,level,hp){
}

Monster::~Monster(){
}
