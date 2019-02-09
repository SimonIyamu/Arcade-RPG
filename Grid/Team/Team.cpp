#include <iostream>
#include <cstdlib>
#include "Team.hpp"

using namespace std;

void Team::set_x(int xx) { x=xx;}

void Team::set_y(int yy) { y=yy;}

int Team::get_x(){return x;}

int Team::get_y(){return y;}

int Team::get_n(){return n;}

int Team::get_avg_lvl(){
   if(n==1) 
      return (*members.begin())->get_level();
   else{
      list<Hero*>::iterator i;
      int lvlsum=0;
      for(i=members.begin() ; i!=members.end() ; i++)
         lvlsum+=(*i)->get_level();

      return lvlsum/n;
   }
}

Hero& Team::get_member(int n){
   int count=1; //Starts from 1 instead of 0 to make it more clear to the player's mind.(Expect if the player is a programmer :P)
   list<Hero*>::iterator i;
   i=members.begin();
   while(count < n){
      i++;
      count++;
   }
   return **i;
}

bool Team::is_defeated(){
   list<Hero*>::iterator i;
   bool flag=1;
   for(i=members.begin() ; i!=members.end() ; i++)
      if((*i)->get_HP())   //If at least one of the members' HP is not 0 then the team is not defeated yet
         flag=0;
   return flag;
}

void Team::print_members(){
   list<Hero*>::iterator i;
   int index=1;
   for(i=members.begin() ; i!=members.end() ; i++)
      cout << index++ << ": " << (*i)->get_name() << " ";
}

void Team::resurect_defeated_members(){
   list<Hero*>::iterator i;
   for(i=members.begin() ; i!=members.end() ; i++)
      if(!(*i)->get_HP())   //for every dead member
         (*i)->set_HP(((*i)->get_max_HP())*50/100);
}

void Team::lost_battle(){
   list<Hero*>::iterator i;
   for(i=members.begin() ; i!=members.end() ; i++){
      (*i)->set_money( ((*i)->get_money())/2 );
   }
}

void Team::recover(){
   list<Hero*>::iterator i;
   for(i=members.begin() ; i!=members.end() ; i++){
      if((*i)->get_HP()!=0){ //If hero is alive
          (*i)->recover_HP(10/100.0);
          (*i)->recover_MP(20/100.0);
      }
   }
}

void Team::display_stats(){
   list<Hero*>::iterator i;
   for(i=members.begin() ; i!=members.end() ; i++){
      cout << (*i)->get_name() << " :\n";
      (*i)->show_inventoryinuse();
      cout << "================================\n" ;
   }
}

Team::Team(int n) : x(0) , y(0) , n(n){  // n is the number of members of the party
   string hero_class;
   Hero *member;

   for(int i=0 ; i<n ; i++){
      hero_class="";
      cout << "Choose a class (Warrior/Sorcerer/Paladin) : ";
      while(hero_class != "Warrior" && hero_class != "Sorcerer" && hero_class != "Paladin" && hero_class != "1"){     //PROSORINO GIA GRHGORO TESTING
         cin >> hero_class;
         if(hero_class == "Warrior")
            member = new Warrior();
         else if(hero_class == "Sorcerer")
            member = new Sorcerer();
         else if(hero_class == "Paladin")
            member = new Paladin();
         else if(hero_class == "1")
            member = new Warrior();              //PROSORINO GIA GRHGORO TESTING
         else
            cout << "Unknown class. Please type one of the following (Warrior/Sorcerer/Paladin) : ";
      }
      members.push_back(member);
   }
   //cout << "LOG: I just created a new team\n";
}

Team::~Team(){
   for(list<Hero*>::iterator i = members.begin() ; i!= members.end() ; i++)
       delete *i;
   members.clear();

   //cout << "LOG: I just destroyed a team\n";
}
