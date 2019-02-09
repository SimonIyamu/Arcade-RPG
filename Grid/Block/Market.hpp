#pragma once
#include "Block.hpp"
#include "../../Living/Hero/Hero.hpp"
#include "../../Living/Living.hpp"
#include "../../Item/Item.hpp"
#include "../../Spell/Spell.hpp"
#include "../../Item/Weapon.hpp"
#include "../../Item/Armor.hpp"
#include "../../Item/Potion.hpp"
#include "../../Spell/FireSpell.hpp"
#include "../../Spell/IceSpell.hpp"
#include "../../Spell/LightingSpell.hpp"

class Market : public Block
{
private:
    list <Weapon*> listofWeapons;
    list <Armor*> listofArmors;
    list <Potion*> listofPotions;
    
    list <FireSpell*> listofFireSpells;
    list <IceSpell*> listofIceSpells;
    list <LightingSpell*> listofLightingSpells;
    
public:
    void set_listofWeapons();
    void set_listofArmors();
    void set_listofPotions();
    void set_listofFireSpells();
    void set_listofIceSpells();
    void set_listofLightingSpells();
    
    void show_Market();
    
    //lists accessors
    /*list <Weapon*> get_listofWeapons();
    list <Armor*> get_listofArmors();
    list <Potion*> get_listofPotions();
    list <FireSpell*> get_listofFireSpells();
    list <IceSpell*> get_listofIceSpells();
    list <LightingSpell*> get_listofLightingSpells(); */
    
    void buy(Hero& HERO); //this is the function that helps the hero             //TODO:mhpws na epairne deikth se hero
    //to buy a goody from the the market
    void sell(Hero& HERO); //Warning!: Here when a hero sells something, we just erase(delete) it from his inventory,and nothing more. There is no need to keep sold things in a list, when they are sold, hero takes his money, and they are just gone!
    void interface(string& choice1, string& choice2, string& choice3); //this is a function in which we ask the user what we wants to buy/sell, (Item/Spell > Type of Item/Spell / the exact name of Item/Spell // The reason for
    //making this function is because we don't want
    //to write the same code twice,
    //once in funtion buy, and once in function sell
    
    bool check_flag(string& choice1, string& choice2, string& choice3, bool flag); // flag is always 0 and becomes 1 when we find an object in the list with the name that player gave us
    //if we end iteration of list and we haven't found a matching
    //object then flag remains 0 and based on this we
    //ask user to give us the information again
    
    void iteration(bool category, Hero& HERO);  //this is a function which is used from both buy and sell function.
    //this functions takas the exact goody and the hero who
    //wants to buy/sell it as parameters
    
    Market();
    ~Market(); //destructor
    
};
