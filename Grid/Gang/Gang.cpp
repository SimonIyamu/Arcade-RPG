#include <iostream>
#include <cstdlib>
#include "Gang.hpp"
#include <fstream>


using namespace std;

Monster& Gang::get_member(int n){
   int count=1; //Starts from 1 instead of 0 to make it more clear to the player's mind.(Expect if the player is a programmer :P)
   list<Monster*>::iterator i;
   i=members.begin();
   while(count < n){
      i++;
      count++;
   }
   return **i;
}

int Gang::get_n(){
   return this->n;
}

void Gang::print_members(){
   list<Monster*>::iterator i;
   int index=1;
   for(i=members.begin() ; i!=members.end() ; i++)
      cout << index++ << ": " << (*i)->get_name() << " ";
}

bool Gang::is_defeated(){
   list<Monster*>::iterator i;
   bool flag=1;
   for(i=members.begin() ; i!=members.end() ; i++)
      if((*i)->get_HP()){   //If at least one of the members' HP is not 0 then the gang is not defeated yet
         flag=0;
      }
   return flag;
}

void Gang::recover(){
   list<Monster*>::iterator i;
   for(i=members.begin() ; i!=members.end() ; i++){
      if((*i)->get_HP()!=0) //If Monster is alive
        (*i)->recover_HP(10/100.0);
   }
}

void Gang::display_stats(){
   list<Monster*>::iterator i;
   for(i=members.begin() ; i!=members.end() ; i++){
      cout << (*i)->get_name() << " :\n";
      (*i)->display_monster_stats();
      cout << "================================\n" ;
   }
}

Gang::Gang(int n,int lvl) : n(n){  // n is the number of members of the gang
   Monster *member;
   int monster_class;

    ifstream file;
    file.open("MonsterNames.txt",ios::in);
    string MonsterName;
  int randomchoice=rand()%37; //these are all names of monsters and only one is chosen randomly
   for(int i=0 ; i<n ; i++){
      int counter=0;
      while (getline(file,MonsterName))
      {
         counter++;
         if (counter==randomchoice)
            break;
      }
      monster_class=rand()%3;
      switch(monster_class){
         case 0:
            member = new Dragon(MonsterName,lvl);  
            break;
         case 1:
            member = new Exoskeleton(MonsterName,lvl);
            break;
         case 2:
            member = new Spirit(MonsterName,lvl);
            break;
      }
      members.push_back(member);
   }
}

Gang::~Gang(){
   for(list<Monster*>::iterator i = members.begin() ; i!= members.end() ; i++){
       delete *i;
   }
   members.clear();

  // cout << "LOG: I just destroyed a gang\n";
}
