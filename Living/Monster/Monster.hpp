#pragma once
#include "cmath"
#include "../Living.hpp"

class Monster : public Living
{
   //this is the range of damage of the monster
   int min_damage;
   int max_damage;

   int defence; // when a monster gets hit from an opponent, defence reduces the amount of damage

   double chance_to_avoid; //this is a % chance for the monster to avoid being hit from the opponent
   public:
   void display_monster_stats();
   int attack(); //Monster attacks (returns the damage that he dealt)
   int get_defence();
   int get_min_dmg();
   int get_max_dmg();
   double get_ch2a(); //chance_to_avoid accessor
   void set_min_dmg(int);
   void set_max_dmg(int);
   void set_defence(int);
   void set_ch2a(double);
   void receive_damage(int);

    Monster(std::string,int,int,int,int,int,double);
    virtual ~Monster();
};
