#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "Hero.hpp"

using namespace std;

//constructor
Hero::Hero(string NAME, int LEVEL, int HEALTHPOWER, int MAGICPOWER, int STRENGTH, int DEXTERITY, double AGILITY): Living(NAME,LEVEL,HEALTHPOWER), money(100), experience(0),exp_to_level_up(100), hands_in_use(0)
{
    max_MP=magicPower=MAGICPOWER;
    strength=STRENGTH;
    dexterity=DEXTERITY;
    agility=AGILITY;
}

    /*
void Hero::level_up()
{
   experience-=exp_to_level_up;
   level++;
   max_HP += max_HP*0.2;
   max_MP += max_MP*0.2;
   strength += strength*0.2;
   dexterity += dexterity*0.2;
   agility += agility*0.2;
   exp_to_level_up += 5*level;
   cout << "Congratulations! Your hero " << name << " just reached " << level << " Level!\n";
}

   */

void Hero::earn_exp(int exp){
   experience+=exp;
   cout << "You just earned " << experience << " exp." << endl;
   while(experience>exp_to_level_up){
      level_up();
  //    getchar(); //gia testing
   }
}

void Hero::set_MP(int mp){
   this->magicPower=mp;
}

void Hero::set_money(int ammount){
   if(ammount>money)
      cout << name << " just earned ";
   else
     cout << name << " just lost "; 
   cout << abs(money-ammount) << " coins." << endl;
   money=ammount;
}

int Hero::get_money(){
   return this->money;
}

int Hero::get_max_MP(){
   return this->max_MP;
}


int Hero::get_MP(){
   return this->magicPower;
}

int Hero::get_STR(){ return this->strength; }
int Hero::get_DEX(){ return this->dexterity; }
double Hero::get_AGI(){ return this->agility; }

void Hero::set_STR(int str){ this->strength = str; }
void Hero::set_DEX(int dex){ this->dexterity = dex; }


void Hero::receive_damage(int dmg){
    int armor; //damage reduced by armor
    if(rand()%100/100.0 < this->agility) 
        cout << "The attack was dodged!\n";
    else{
        for(std::list<Armor*>::iterator it = listofHeroArmors.begin(); it!=listofHeroArmors.end(); it++)
            if ((*it)->get_currentlyusing()){
                armor=(*it)->get_damage_reducer();
                break;
            }
        if(dmg-armor<=0)
            cout << this->name << " lost 0 HP.\n";
        else
            cout << this->name << " lost " << dmg-armor << " HP.\n";
        if(this->get_HP()-dmg+armor < 0){
            this->set_HP(0);
            cout << this->name << " fainted.\n";
        }
        else
            this->set_HP(this->get_HP()-dmg+armor);
   }
}

int Hero::basic_attack(){
   return strength;
}

bool Hero::exit(bool flag)
{
    if (flag==0)
    {
         cout << "Wrong name!" << endl;
         cout << "Press e to exit or a to try again" << endl;
         string answer;
         cin >> answer;
         while (answer!="e" && answer!="a")
         {
            cout << "ERROR: Press e to exit or a to try again" << endl;
         }
         if (answer=="e") return 0;
         else return 1;
    }
}

IceSpell* Hero::cast_IceSpell(){
   bool flag=0;
   string choice;
   int damage=0,MP_consumption=0;
   while(!flag){
      cout << "Type the exact name of the IceSpell : ";
      cin >> choice;
      cout << endl;
      for(list<IceSpell*>::iterator i = listofHeroIceSpells.begin(); i!=listofHeroIceSpells.end(); i++)
      {
         if ((*i)->get_name()==choice)
         {
            flag=1;
            cout << "You've just cast " << (*i)->get_name() << ".\n";
            return (*i);
         }
      }
      if (exit(flag)==0)
         return NULL;
   }
}

FireSpell* Hero::cast_FireSpell(){
   bool flag=0;
   string choice;
   int damage=0,MP_consumption=0;
   while(!flag){
      cout << "Type the exact name of the FireSpell : ";
      cin >> choice;
      cout << endl;
      for(list<FireSpell*>::iterator i = listofHeroFireSpells.begin(); i!=listofHeroFireSpells.end(); i++)
      {
         if ((*i)->get_name()==choice)
         {
            flag=1;
            cout << "You've just cast " << (*i)->get_name() << ".\n";
            return (*i);
         }
      }
      if (exit(flag)==0)
         return NULL;
   }
}

LightingSpell* Hero::cast_LightingSpell(){
   bool flag=0;
   string choice;
   int damage=0,MP_consumption=0;
   while(!flag){
      cout << "Type the exact name of the LightingSpell : ";
      cin >> choice;
      cout << endl;
      for(list<LightingSpell*>::iterator i = listofHeroLightingSpells.begin(); i!=listofHeroLightingSpells.end(); i++)
      {
         if ((*i)->get_name()==choice)
         {
            flag=1;
            cout << "You've just cast " << (*i)->get_name() << ".\n";
            return (*i);
         }
      }
      if (exit(flag)==0)
         return NULL;
   }
}

void Hero::recover_MP(double percentage){
   if(magicPower!=max_MP)
      if(magicPower + max_MP*percentage < max_MP){
         cout << name << " recovered " << max_MP*percentage << " MP.\n";
         magicPower=(magicPower + max_MP*percentage);
      }
      else{
         cout << name << " recovered to full MP.\n";
         magicPower=max_MP;
      }
}

void Hero::increase_AGI(double percentage){
   if(agility!=1)
      if(agility + agility*percentage < 1){
         cout << name << "'s agility increased by " << percentage << " %\n";
         agility=(agility + agility*percentage);
      }
      else{
         cout << name << " has 100 %" << " chance of dodging an attack.\n";
         agility=1;
      }
}



bool Hero::use_Potion(){
   bool flag=0;
   string choice;
   double increasement=0;
   Stat stat;
   while(!flag){
      cout << "Type the exact name of the Potion : ";
      cin >> choice;
      cout << endl;
      for(list<Potion*>::iterator i = listofHeroPotions.begin(); i!=listofHeroPotions.end(); i++)
      {
         if ((*i)->get_name()==choice)
         {
            stat = (*i)->get_stat();
            increasement=(*i)->get_increasement(); 
            flag=1;
            cout << "You've just used " << (*i)->get_name() << " Potion.\n";
            break;
         }
      }
      if (exit(flag)==0)
         return false;
   }
   switch(stat){
       case 0:
          cout << "STR increased by " << increasement*100 << " %\n";
          set_STR((int) (get_STR() + get_STR()*increasement)); 
          break;
       case 1:
          cout << "DEX increased by " << increasement*100 << " %\n";
          set_DEX((int) (get_DEX() + get_DEX()*increasement)); 
          break;
       case 2:
          cout << "AGI increased by " << increasement*100 << " %\n";
          increase_AGI(increasement);
          break;
       case 3:
          recover_HP(increasement);
          break;
       case 4:
          recover_MP(increasement);
          break;
    }
   return true;
}


void Hero::check_buy(Weapon *WEAPON)
{
    if (level < WEAPON->get_min_level())
    {
        cout << "Sorry, your hero is not enough level for this Weapon." << endl;
        return;
    }
    if(money<WEAPON->get_price())
    {
        cout << "Sorry, your hero has not enough money for this Weapon." << endl;
        return;
    }
    
    money -= WEAPON->get_price(); //the money decrease after payment
    listofHeroWeapons.push_back(WEAPON);
    cout << "Do you wish to equip the new weapon instantly on your hero? (yes/no)" << endl;
    string answer;
    getline(cin,answer);
    if (answer=="yes")
        equip(WEAPON);
}

void Hero::equip(Weapon *WEAPON)
{
    if (hands_in_use==2)
    {
        cout << "Sorry, both hands of your hero are currently in use." << endl;
        return;
    }
    if (hands_in_use==1 && WEAPON->get_hand()==1)
    {
        cout << "Sorry, this weapon needs two hands, and your hero gots only one free." << endl;
        return;
    }
    
    hands_in_use += (WEAPON->get_hand()+1); //number of hands now in use
    strength += WEAPON->get_damage(); //the weapon increases hero's damage
    WEAPON->set_currentlyusing(1); //the weapon is now in use
    cout << "A Weapon with name: " << WEAPON->get_name() << " was just equipped" << endl;
    
}

void Hero::check_buy(Armor* ARMOR)
{
    if (level < ARMOR->get_min_level())
    {
        cout << "Sorry, your hero is not enough level for this Armor." << endl;
        return;
    }
    if(money<ARMOR->get_price())
    {
        cout << "Sorry, your hero has not enough money for this Armor." << endl;
        return;
    }
    
    money -= ARMOR->get_price();
    listofHeroArmors.push_back(ARMOR);
    cout << "Do you wish to equip the new armor instantly on your hero? (yes/no)" << endl;
    string answer;
    getline(cin,answer);
    if (answer=="yes")
        equip(ARMOR);
}

void Hero::equip(Armor* ARMOR)
{
    //befrore we equip an Armor we are checking if the is another
    //armor already in use.
    //In this case we firslty unequip this Armor for the chosen one
    for(list<Armor*>::iterator it = listofHeroArmors.begin(); it!=listofHeroArmors.end(); it++)
    {
        if ((*it)->get_currentlyusing()==1)
        {
            (*it)->set_currentlyusing(0);
        }
    }
    //the chosen Armor takes the place of the currently using Armor
    ARMOR->set_currentlyusing(1);
    cout << "An Armor with name: " << ARMOR->get_name() << "was just equipped" << endl;
}

void Hero::check_buy(Potion* POTION)
{
    if (level < POTION->get_min_level())
    {
        cout << "Sorry, your hero is not enough level for this Potion." << endl;
        return;
    }
    if(money<POTION->get_price())
    {
        cout << "Sorry, your hero has not enough money for this Potion." << endl;
        return;
    }

    money -= POTION->get_price(); //the money decrease after payment
    listofHeroPotions.push_back(POTION);
    
}

void Hero::equip(Potion* POTION)
{
    POTION->set_currentlyusing(1); //the weapon is now in use
    
    //we are choosing randomly one of three statistics
    //(strength/dexterity,agility) of the hero
    // to increasse it
    int random=rand()%3;
    if (random==0)
        strength= strength + strength * POTION->get_increasement();
    else if (random==1)
        dexterity= dexterity + dexterity * POTION->get_increasement();
    else
        agility= agility + agility * POTION->get_increasement();
    
    cout << "A Potion with name: " << POTION->get_name() << "was just equipped" << endl;
}

void Hero::check_buy(FireSpell* FIRESPELL)
{
    if (level < FIRESPELL->get_min_level())
    {
        cout << "Sorry, your hero is not enough level for this FireSpell." << endl;
        return;
    }
    if(money<FIRESPELL->get_price())
    {
        cout << "Sorry, your hero has not enough money for this FireSpell." << endl;
        return;
    }
    
    money -= FIRESPELL->get_price(); //the money decrease after payment
    listofHeroFireSpells.push_back(FIRESPELL);
}


void Hero::check_buy(IceSpell* ICESPELL)
{
    if (level < ICESPELL->get_min_level())
    {
        cout << "Sorry, your hero is not enough level for this IceSpell." << endl;
        return;
    }
    if(money<ICESPELL->get_price())
    {
        cout << "Sorry, your hero has not enough money for this IceSpell." << endl;
        return;
    }
    
    money -= ICESPELL->get_price(); //the money decrease after payment
    listofHeroIceSpells.push_back(ICESPELL);
}

void Hero::check_buy(LightingSpell* LIGHTINGSPELL)
{
    if (level < LIGHTINGSPELL->get_min_level())
    {
        cout << "Sorry, your hero is not enough level for this LightingSpell." << endl;
        return;
    }
    if(money<LIGHTINGSPELL->get_price())
    {
        cout << "Sorry, your hero has not enough money for this LightingSpell." << endl;
        return;
    }
    
    money -= LIGHTINGSPELL->get_price(); //the money decrease after payment
    listofHeroLightingSpells.push_back(LIGHTINGSPELL);
}

void Hero::UNequip(Weapon *WEAPON)
{
     for(list<Weapon*>::iterator it = listofHeroWeapons.begin(); it!=listofHeroWeapons.end(); it++)
     {
         if ((*it)->get_name()==WEAPON->get_name())
         {
             (*it)->set_currentlyusing(0);
             bool h=(*it)->get_hand();
             strength -= (*it)->get_damage(); //the weapon increases hero's damage
             hands_in_use-=(h+1); //we free one or two hands of the hero
         }
     }
}

list <Weapon*>& Hero::get_listofHeroWeapons()
{
    return listofHeroWeapons;
}

list <Armor*>& Hero::get_listofHeroArmors()
{
    return listofHeroArmors;
}

list <Potion*>& Hero::get_listofHeroPotions()
{
    return listofHeroPotions;
}

list <FireSpell*>& Hero::get_listofHeroFireSpells()
{
    return listofHeroFireSpells;
}

list <IceSpell*>& Hero::get_listofHeroIceSpells()
{
    return listofHeroIceSpells;
}

list <LightingSpell*>& Hero::get_listofHeroLightingSpells()
{
    return listofHeroLightingSpells;
}

void Hero::check_sell(Weapon *WEAPON)
{
    int flag=1;
    for (list<Weapon*>::iterator it=listofHeroWeapons.begin(); it!= listofHeroWeapons.end();)
    {
        if (WEAPON->get_name()==(*it)->get_name())
        {
            cout << "You have just sold " << WEAPON->get_name() << " for: " << (WEAPON->get_price()/2) << endl;
            flag=0;
            it=listofHeroWeapons.erase(it);
        }
        else it++;
    }
    if(flag){
       cout << "The Weapon you are trying to sell does not exist in your inventory\n";
       return;
    }
    money += (WEAPON->get_price())/2;
    if (WEAPON->get_currentlyusing()==1)
    {
        hands_in_use-=(WEAPON->get_hand()+1);
    }
}

void Hero::check_sell(Armor *ARMOR)
{
    int flag=1;
    for (list<Armor*>::iterator it=listofHeroArmors.begin(); it!= listofHeroArmors.end();)
    {
        if (ARMOR->get_name()==(*it)->get_name())
        {
            cout << "You have just sold " << ARMOR->get_name() << " for: " << (ARMOR->get_price()/2) << endl;
            flag=0;
            it=listofHeroArmors.erase(it);
        }
        else it++;
    }
    if(flag){
       cout << "The Armor you are trying to sell does not exist in your inventory\n";
       return;
    }

    money += (ARMOR->get_price())/2;
}

void Hero::check_sell(Potion *POTION)
{
    int flag=1;
    for (list<Potion*>::iterator it=listofHeroPotions.begin(); it!= listofHeroPotions.end();)
    {
        if (POTION->get_name()==(*it)->get_name())
        {
            cout << "You have just sold " << POTION->get_name() << " for: " << (POTION->get_price()/2) << endl;
            flag=0;
            it=listofHeroPotions.erase(it);
        }
        else it++;
    }
    if(flag){
       cout << "The Potion you are trying to sell does not exist in your inventory\n";
       return;
    }

    money += (POTION->get_price())/2;
}

void Hero::check_sell(FireSpell *FIRESPELL)
{
    int flag=1;
    for (list<FireSpell*>::iterator it=listofHeroFireSpells.begin(); it!= listofHeroFireSpells.end();)
    {
        if (FIRESPELL->get_name()==(*it)->get_name())
        {
            cout << "You have just sold " << FIRESPELL->get_name() << " for: " << (FIRESPELL->get_price()/2) << endl;
            flag=0;
            it=listofHeroFireSpells.erase(it);
        }
        else it++;
    }
    if(flag){
       cout << "The FireSpell you are trying to sell does not exist in your inventory\n";
       return;
    }

    money += (FIRESPELL->get_price())/2;
}

void Hero::check_sell(IceSpell *ICESPELL)
{
    int flag=1;
    for (list<IceSpell*>::iterator it=listofHeroIceSpells.begin(); it!= listofHeroIceSpells.end();)
    {
        if (ICESPELL->get_name()==(*it)->get_name())
        {
            cout << "You have just sold " << ICESPELL->get_name() << " for: " << (ICESPELL->get_price()/2) << endl;
            flag=0;
            it=listofHeroIceSpells.erase(it);
        }
        else it++;
    }
    if(flag){
       cout << "The IceSpell you are trying to sell does not exist in your inventory\n";
       return;
    }

    money += (ICESPELL->get_price())/2;
}

void Hero::check_sell(LightingSpell *LIGHTINGSPELL)
{
    int flag=1;
    for (list<LightingSpell*>::iterator it=listofHeroLightingSpells.begin(); it!= listofHeroLightingSpells.end();)
    {
        if (LIGHTINGSPELL->get_name()==(*it)->get_name())
        {
            cout << "You have just sold " << LIGHTINGSPELL->get_name() << " for: " << (LIGHTINGSPELL->get_price()/2) << endl;
            flag=0;
            it=listofHeroLightingSpells.erase(it);
        }
        else it++;
    }
    if(flag){
       cout << "The LightingSpell you are trying to sell does not exist in your inventory\n";
       return;
    }

    money += (LIGHTINGSPELL->get_price())/2;
}

void Hero::show_inventory()
{
    cout << "================================================\n";
    cout << "|                  Inventory                   |\n";
    cout << "================================================\n\n";
    cout << "Hero Name: " << name << endl;

    if(!listofHeroWeapons.empty()){
        cout << endl << "These are all the weapons your hero has: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout.width(30);
        cout << left << "NAME";
        cout.width(15);
        cout << left << "PRICE";
        cout.width(15);
        cout << left << "MIN LEVEL";
        cout.width(15);
        cout << left << "DAMAGE";
        cout.width(15);
        cout << left << "HANDS NEEDED" << right << endl << endl;

     
        for(std::list<Weapon*>::iterator it = listofHeroWeapons.begin(); it!=listofHeroWeapons.end(); it++)
        {
            (*it)->print_info();
        }
    }
    
    if(!listofHeroArmors.empty()){
        cout << endl << "These are all Armors your hero has: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout.width(30);
        cout << left << "NAME";
        cout.width(15);
        cout << left << "PRICE";
        cout.width(15);
        cout << left << "MIN LEVEL";
        cout.width(15);
        cout << left << "OPPONENT'S DAMAGE" << right << endl;
        cout.width(73);
        cout << right << "REDUCER %" << endl << endl;

        for(std::list<Armor*>::iterator it = listofHeroArmors.begin(); it!=listofHeroArmors.end(); it++)
        {
            (*it)->print_info();
        }
    }
        
    if(!listofHeroPotions.empty()){
        cout << endl << "These are all the Potions your hero has: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout.width(30);
        cout << left << "NAME";
        cout.width(15);
        cout << left << "PRICE";
        cout.width(15);
        cout << left << "MIN LEVEL";
        cout.width(15);
        cout << left << "STATISTIC";
        cout.width(15);
        cout << left << "INCREASEMENT %" << right << endl << endl;

        for(std::list<Potion*>::iterator it = listofHeroPotions.begin(); it!=listofHeroPotions.end(); it++)
        {
            (*it)->print_info();
        }
    }

        
    if(!listofHeroFireSpells.empty()){
        cout << endl << "These are all the FireSpells your hero has: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout.width(20);
        cout << left << "NAME";
        cout.width(15);
        cout << left << "PRICE";
        cout.width(15);
        cout << left << "MIN LEVEL";
        cout.width(15);
        cout << left << "MIN DAMAGE";
        cout.width(15);
        cout << left << "MAX DAMAGE";
        cout.width(15);
        cout << left << "MAGIC ENERGY" << right << endl;
        cout.width(20);
        cout << left << "OPPONENT'S DEFENCE";
        cout.width(10);
        cout << left << "ROUNDS" << right << endl;
        cout.width(109);
        cout << right << "REDUCER %" << endl << endl;




        for(std::list<FireSpell*>::iterator it = listofHeroFireSpells.begin(); it!=listofHeroFireSpells.end(); it++)
        {
            (*it)->print_info();
        }
    }
        
        
    if(!listofHeroIceSpells.empty()){
        cout << endl << "These are all the IceSpells your hero has: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout.width(20);
        cout << left << "NAME";
        cout.width(15);
        cout << left << "PRICE";
        cout.width(15);
        cout << left << "MIN LEVEL";
        cout.width(15);
        cout << left << "MIN DAMAGE";
        cout.width(15);
        cout << left << "MAX DAMAGE";
        cout.width(15);
        cout << left << "MAGIC ENERGY";
        cout.width(20);
        cout << left << "MIN DAMAGE";
        cout.width(20);
        cout << left << "MAX DAMAGE" << right << endl;
        cout.width(104);
        cout << right << "REDUCER %";
        cout.width(20);
        cout << right << "REDUCER %" << endl << endl;

        for(std::list<IceSpell*>::iterator it = listofHeroIceSpells.begin(); it!=listofHeroIceSpells.end(); it++)
        {
            (*it)->print_info();
        }
    }
        
        
    if(!listofHeroLightingSpells.empty()){
        cout << endl << "These are all the LightingSpells your hero has: " << endl;
        cout << "-------------------------------------------------------" << endl;
        cout.width(20);
        cout << left << "NAME";
        cout.width(15);
        cout << left << "PRICE";
        cout.width(15);
        cout << left << "MIN LEVEL";
        cout.width(15);
        cout << left << "MIN DAMAGE";
        cout.width(15);
        cout << left << "MAX DAMAGE";
        cout.width(15);
        cout << left << "MAGIC ENERGY";
        cout.width(20);
        cout << left << "AVOID CHANCE";
        cout.width(10);
        cout << left << "ROUNDS" << right << endl;
        cout.width(105);
        cout << right << "REDUCER %" << endl << endl;

        for(std::list<LightingSpell*>::iterator it = listofHeroLightingSpells.begin(); it!=listofHeroLightingSpells.end(); it++)
        {
            (*it)->print_info();
        }
    }
    
    cout << endl << "Coins: " << money << endl;
}

void Hero::show_inventoryinuse() //TODO:more like show_hero_info or display_hero_stats
{
   cout << fixed << setprecision(1);
   cout << "Name: " << name << endl << "Level: " << level << endl
       << "HP: " << healthPower << " MP: " << magicPower << endl
       << "Stats: STR: " << strength << ", DEX: " << dexterity << ", AGI: " << agility << endl
       << "Experience: " << experience << " (" << experience*100/(double)exp_to_level_up << "%)" << endl;
       
    cout << "Items and spells in use: " << endl;
    //cout << "This is the inventory IN USE of Hero with name: " << name << endl;
    //cout << "================================================" << endl << endl;
    //cout << "These are all the weapons your hero in now using: " << endl;
    //cout << "-------------------------------------------------------" << endl;
    for(std::list<Weapon*>::iterator it = listofHeroWeapons.begin(); it!=listofHeroWeapons.end(); it++)
    {
        if ((*it)->get_currentlyusing())
            cout << (*it)->get_name() << endl;//print_info();
    }
    
    //cout << "This is the Armor your hero is now using: " << endl;
    //cout << "-------------------------------------------------------" << endl;
    for(std::list<Armor*>::iterator it = listofHeroArmors.begin(); it!=listofHeroArmors.end(); it++)
    {
        if ((*it)->get_currentlyusing())
            cout << (*it)->get_name() << endl;//print_info();
    }
    
    //cout << "These are all the Potions your hero is now using " << endl;
    //cout << "-------------------------------------------------------" << endl;
    for(std::list<Potion*>::iterator it = listofHeroPotions.begin(); it!=listofHeroPotions.end(); it++)
    {
        if ((*it)->get_currentlyusing())
            cout << (*it)->get_name() << endl;//print_info();
    }
    
    
    //cout << "These are all the FireSpells your hero is now using: " << endl;
    //cout << "-------------------------------------------------------" << endl;
    for(std::list<FireSpell*>::iterator it = listofHeroFireSpells.begin(); it!=listofHeroFireSpells.end(); it++)
    {
        if ((*it)->get_currentlyusing())
            cout << (*it)->get_name() << endl;//print_info();
    }
    
    
    //cout << "These are all the IceSpells your hero is now using: " << endl;
    //cout << "-------------------------------------------------------" << endl;
    for(std::list<IceSpell*>::iterator it = listofHeroIceSpells.begin(); it!=listofHeroIceSpells.end(); it++)
    {
        if ((*it)->get_currentlyusing())
            cout << (*it)->get_name() << endl;//print_info();
    }
    
    
    //cout << "These are all the LightingSpells your hero is now using: " << endl;
    //cout << "-------------------------------------------------------" << endl;
    for(std::list<LightingSpell*>::iterator it = listofHeroLightingSpells.begin(); it!=listofHeroLightingSpells.end(); it++)
    {
        if ((*it)->get_currentlyusing())
            cout << (*it)->get_name() << endl;//print_info();
    }
}

Hero::~Hero()
{
    
}




