#include <iostream>
#include <cstdlib>
#include <fstream>
#include <list>
#include <ctime>
#include <string>
#include "Market.hpp"

using namespace std;

void Market::set_listofWeapons()
{
    //==================================
    // ***INSERTING WEAPONS DATA***
    //==================================
    ifstream file;
    file.open("WeaponNames.txt",ios::in); 
    if(!file.is_open()){
       cerr << "Could not open file\n";
       exit(EXIT_FAILURE);
    }
    string WeaponName;
    int price;
    int min_level;
    int damage;
    bool hand;
    while (getline(file,WeaponName))
    {
        price=rand()%1000 + 1;
        min_level=rand()%15 + 1;
        damage=rand()%500 + 1;
        hand=rand()%2;

        Weapon *WEAPON=new Weapon(WeaponName,price,min_level,damage,hand);
        listofWeapons.push_back(WEAPON);
    }
    
}
//--------------------------------------------------------------
void Market::set_listofArmors()
{
    //==================================
    // ***INSERTING ARMOR DATA***
    //==================================
    ifstream file;
    file.open("ArmorNames.txt",ios::in);
    if(!file.is_open()){
       cerr << "Could not open file\n";
       exit(EXIT_FAILURE);
    }
    string ArmorName;
    int price;
    int min_level;
    double damage_reducer;
    while (getline(file,ArmorName))
    {
        price=rand()%500 + 1;
        min_level=rand()%15 + 1;
        damage_reducer=rand()%51 + 1;
        
        Armor *ARMOR=new Armor(ArmorName,price,min_level,damage_reducer);
        listofArmors.push_back(ARMOR);
    }
}
//-----------------------------------------------------------------
void Market::set_listofPotions()
{
    //==================================
    // ***INSERTING POTION DATA***
    //==================================
    ifstream file;
    file.open("PotionNames.txt",ios::in);
    if(!file.is_open()){
       cerr << "Could not open file\n";
       exit(EXIT_FAILURE);
    }
   string PotionName;
    int price;
    int min_level;
    double increasement;
    while (getline(file,PotionName))
    {
        
        price=rand()%100+ 1;
        min_level=rand()%15 + 1;
        increasement=rand()%25 /100.0 ;
        
        Potion *POTION=new Potion(PotionName,price,min_level,increasement,Stat(rand()%5));
        listofPotions.push_back(POTION);
    }
}
//-----------------------------------------------------------------

void Market::set_listofFireSpells()
{
    //==================================
    // ***INSERTING FIRESPELL DATA***
    //==================================
    ifstream file;
    file.open("FireSpellNames.txt",ios::in);
    if(!file.is_open()){
       cerr << "Could not open file\n";
       exit(EXIT_FAILURE);
    }
    string FireSpellName;
    int price;
    int min_level;
    int min_damage;
    int max_damage;
    int magic_energy_needed;
    double defence_reducer;
    int rounds;
    while (getline(file,FireSpellName))
    {
        price=rand()%500 + 1;
        min_level=rand()%15 + 1;
        min_damage=rand()%500 + 1;
        max_damage=rand()%500 + 1;
        magic_energy_needed=rand()%500 + 1;
        defence_reducer=rand()%51;
        rounds=rand()%10 + 1;
        
        FireSpell *FIRESPELL=new FireSpell(FireSpellName,price,min_level,min_damage,max_damage,magic_energy_needed,defence_reducer,rounds);
        listofFireSpells.push_back(FIRESPELL);
    }
}
//-----------------------------------------------------------------
void Market::set_listofIceSpells()
{
    //==================================
    // ***INSERTING ICESPELL DATA***
    //==================================
    ifstream file;
    file.open("IceSpellNames.txt",ios::in);
    if(!file.is_open()){
       cerr << "Could not open file\n";
       exit(EXIT_FAILURE);
    }
   string IceSpellName;
    int price;
    int min_level;
    int min_damage;
    int max_damage;
    int magic_energy_needed;
    int min_damage_reducer;
    int max_damage_reducer;
    int rounds_with_reduction;
    while (getline(file,IceSpellName))
    {
        price=rand()%500 + 1;
        min_level=rand()%15 + 1;
        min_damage=rand()%500 + 1;
        max_damage=rand()%500 + 1;
        magic_energy_needed=rand()%500 + 1;
        min_damage_reducer=rand()%51;
        max_damage_reducer=rand()%51;
        rounds_with_reduction=rand()%10 + 1;
        
        IceSpell  *ICESPELL=new IceSpell(IceSpellName,price,min_level,min_damage,max_damage,magic_energy_needed,min_damage_reducer,max_damage_reducer,rounds_with_reduction);
        listofIceSpells.push_back(ICESPELL);
    }
}

//-----------------------------------------------------------------
void Market::set_listofLightingSpells()
{
    //==================================
    // ***INSERTING LIGHTINGSPELL DATA***
    //==================================
    ifstream file;
    file.open("LightingSpellNames.txt",ios::in);
    if(!file.is_open()){
       cerr << "Could not open file\n";
       exit(EXIT_FAILURE);
    }
    string LightingSpellName;
    int price;
    int min_level;
    int min_damage;
    int max_damage;
    int magic_energy_needed;
    double avoid_chance_reducer;
    int rounds;
    while (getline(file,LightingSpellName))
    {
        price=rand()%500 + 1;
        min_level=rand()%15 + 1;
        min_damage=rand()%501 + 1;
        max_damage=rand()%501 + 1;
        magic_energy_needed=rand()%501 + 1;
        avoid_chance_reducer =rand()%51;
        rounds=rand()%10 + 1;
        
        LightingSpell *LIGHTINGSPELL=new LightingSpell(LightingSpellName,price,min_level,min_damage,max_damage,magic_energy_needed,avoid_chance_reducer,rounds);
        listofLightingSpells.push_back(LIGHTINGSPELL);
    }
}
//-----------------------------------------------------------------
Market::Market()
{
    this->type=MARKET;
    set_listofWeapons();
    set_listofArmors();
    set_listofPotions();
    set_listofFireSpells();
    set_listofIceSpells();
    set_listofLightingSpells();
//    cout << "LOG: A new market was created\n";
}
//------------------------------------------------------------------
//==================================================================
Market::~Market() //desctructing all list <mylist*> // deleting pointers inside them
{
    for(list<Weapon*>:: iterator it = listofWeapons.begin(); it != listofWeapons.end(); it++)
    {
        delete *it;
    }
    listofWeapons.clear();
    
    for(list<Armor*>:: iterator it = listofArmors.begin(); it != listofArmors.end(); it++)
    {
        delete *it;
    }
    listofArmors.clear();

    for (list<Potion*>:: iterator it = listofPotions.begin(); it != listofPotions.end(); it++)
    {
        delete *it;
    }
    listofPotions.clear();
    
    for(list<FireSpell*>:: iterator it = listofFireSpells.begin(); it != listofFireSpells.end(); it++)
    {
        delete *it;
    }
    listofFireSpells.clear();
    
    for(list<IceSpell*>:: iterator it = listofIceSpells.begin(); it != listofIceSpells.end(); it++)
    {
        delete *it;
    }
    listofIceSpells.clear();
    
    for(list<LightingSpell*>:: iterator it = listofLightingSpells.begin(); it != listofLightingSpells.end(); it++)
    {
        delete *it;
    }
    listofLightingSpells.clear();
    
    //cout << "LOG: A market was destroyed\n";
}

//=====================================================
//=====================================================

void Market::show_Market()
{
   cout << endl << "\033[1;33mThese are all the weapons you can buy:\033[0m" << endl;
   cout << "\033[1;33m---------------------------------------\033[0m" << endl;
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

    for(std::list<Weapon*>::iterator it = listofWeapons.begin(); it!=listofWeapons.end(); it++)
    {
        (*it)->print_info();
    }
    
    cout << endl << "\033[1;33mThese are all Armors you can buy: \033[0m" << endl;
    cout << "\033[1;33m-----------------------------------\033[0m" << endl;
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


    for(std::list<Armor*>::iterator it = listofArmors.begin(); it!=listofArmors.end(); it++)
    {
        (*it)->print_info();
    }
    
    cout << endl << "\033[1;33mThese are all the Potions you can buy:\033[0m" << endl;
    cout << "\033[1;33m---------------------------------------\033[0m" << endl ;
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

    for(std::list<Potion*>::iterator it = listofPotions.begin(); it!=listofPotions.end(); it++)
    {
        (*it)->print_info();
    }
    
    
    cout << endl << "\033[1;33mThese are all the FireSpells you can buy: \033[0m" << endl;
    cout << "\033[1;33m------------------------------------------\033[0m" << endl;
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
    cout << left << "OPPONENT'S DEFENCE";
    cout.width(10);
    cout << left << "ROUNDS" << right << endl;
    cout.width(109);
    cout << right << "REDUCER %" << endl << endl;


    for(std::list<FireSpell*>::iterator it = listofFireSpells.begin(); it!=listofFireSpells.end(); it++)
    {
        (*it)->print_info();
    }
    
    
    cout << endl << "\033[1;33mThese are all the IceSpells you can buy: \033[0m" << endl;
    cout << "\033[1;33m------------------------------------------\033[0m" << endl;
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


    for(std::list<IceSpell*>::iterator it = listofIceSpells.begin(); it!=listofIceSpells.end(); it++)
    {
        (*it)->print_info();
    }
    
    
    cout << endl << "\033[1;33mThese are all the LightingSpells you can buy: \033[0m" << endl;
    cout << "\033[1;33m------------------------------------------------\033[0m" << endl;
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


    for(std::list<LightingSpell*>::iterator it = listofLightingSpells.begin(); it!=listofLightingSpells.end(); it++)
    {
        (*it)->print_info();
    }
    
}
//=================================================================
/*
list <Weapon*> Market::get_listofWeapons()
{
    return listofWeapons;
}

list <Armor*> Market::get_listofArmors()
{
    return listofArmors;
}

list <Potion*> Market::get_listofPotions()
{
    return listofPotions;
}

list <FireSpell*> Market::get_listofFireSpells()
{
    return listofFireSpells;
}

list <IceSpell*> Market::get_listofIceSpells()
{
    return listofIceSpells;
}

list <LightingSpell*> Market::get_listofLightingSpells()
{
    return listofLightingSpells;
}
 */
//================================================================
void Market::interface(string& choice1, string& choice2, string& choice3) //this helps as take the exact type and name of the thing
//that the hero wants to buy/sell
{
    //============================================================
    // *** This is the place we understand what the player wants to
    // buy/sell exactly for his hero ***
    //============================================================
    
    //------------------
    //>>>>> Item/Spell
    //------------------
    cout << "Item or Spell? (type Item/Spell)" << endl;
    getline(cin, choice1);
    while ((choice1!="Item") && (choice1!="Spell") ) //in order to check if the user gave a proper answer
    {
        cout << "ERROR: Type again Item or Spell." << endl;
        getline(cin, choice1);
    }
    //------------------------------------
    //>>>>>> Item > Weapon/Armor/Potion
    //------------------------------------
    if (choice1=="Item")
    {
        cout << "Type Weapon/Armor/Potion" << endl;
        getline(cin, choice2);
        while ((choice2!="Weapon") && (choice2 != "Armor") && (choice2!= "Potion"))
        {
            cout << "ERROR: Type again Weapon/Armor/Potion" << endl;
            getline(cin, choice2);
        }
    }
    //-------------------------------------------------
    //>>>>>> Spell > FireSpell/IceSpell/LightingSpell
    //-------------------------------------------------
    else //if (choice1=="Spell")
    {
        cout << "Type FireSpell/IceSpell/LightingSpell" << endl;
        getline(cin, choice2);
        while (choice2!="FireSpell" && choice2!="IceSpell" && choice2!= "LightingSpell")
        {
            cout << "ERROR: Type again FireSpell/IceSpell/LightingSpell" << endl;
            getline(cin, choice2);
        }
    }
    //---------------------------------------------------------
    //============================================================
    //Now we know exactly the type of what the player wants to buy/sell for his hero
    // and we are going to ask for its name
    //============================================================
    //string choice3;
    cout << "Type the exact name of the goody" << endl;
    getline(cin, choice3);
}
//=============================================================
bool Market::check_flag(string& choice1, string& choice2, string& choice3, bool flag)
{
    if (flag==0)
    {
        cout << "ERROR: You gave incorrect name of Item/Spell" << endl;
        cout << "Try again. " << endl;
        return 0;
    }
    else return 1;
}
//==============================================================
//When we come inside this function, the user wants either
//to buy or to sell something
//1. using function "interface" we get the exact information
//of the thing that the Hero wants to buy/sell
//2. Depending on the choice of Hero to either buy(0) or sell(1)
//we follow the appropriate operations
//      -we
void Market::iteration(bool category, Hero& HERO)
{
    //category: 1 = buy something
    //category: 2 = sell something
    string choice1,choice2,choice3;
    //choice1: Item or Spell
    //choice2: If Item > Weapon/Armor/Potion
    //         If Spell > FireSpell/IceSpell/LightingSpell
    //choice3: exact name of Item/Spell
    
    interface(choice1,choice2,choice3);
    bool flag=0; // flag is always 0 and becomes 1 when we find an object in the list with the name that player gave us
    //if we end iteration to list and we haven't found a matching
    //object then flag remains 0 and based on this we
    //ask user to give us the information again
    if (choice1=="Item")
    {
        if (choice2=="Weapon")
        {
            Weapon* WEAPON;
            if (category==0) //buy
            {
                for(list<Weapon*>::iterator it = listofWeapons.begin(); it!=listofWeapons.end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        WEAPON=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            else //sell
            {
                for(list<Weapon*>::iterator it = HERO.get_listofHeroWeapons().begin(); it!=HERO.get_listofHeroWeapons().end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        WEAPON=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            if (check_flag(choice1,choice2,choice3,flag)==1 )
            {
                if (category==0) //buy
                {
                    HERO.check_buy(WEAPON);
                    /*list <Weapon*>:: iterator it=HERO.get_listofHeroWeapons().end();
                    cout << (*it)->get_name() << endl << endl;*/
                }
                else
                    HERO.check_sell(WEAPON);
            }
            else
            {
                interface(choice1,choice2,choice3);
            }
        }
        else if (choice2=="Armor")
        {
            Armor* ARMOR;
            if (category==0) //buy
            {
                for(list<Armor*>::iterator it = listofArmors.begin(); it!=listofArmors.end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        ARMOR=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            else //sell
            {
                for(list<Armor*>::iterator it = HERO.get_listofHeroArmors().begin(); it!=HERO.get_listofHeroArmors().end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        ARMOR=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            if (check_flag(choice1,choice2,choice3,flag)==1 )
            {
                if (category==0)
                    HERO.check_buy(ARMOR);
                else
                    HERO.check_sell(ARMOR);
            }
            else
            {
                interface(choice1,choice2,choice3);
            }
        }
        else// if (choice2=="Potion")
        {
            Potion* POTION;
            if (category==0) //buy
            {
                for(list<Potion*>::iterator it = listofPotions.begin(); it!=listofPotions.end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        POTION=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            else //sell
            {
                for(list<Potion*>::iterator it = HERO.get_listofHeroPotions().begin(); it!=HERO.get_listofHeroPotions().end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        POTION=(*it);
                        flag=1;
                        break;
                    }
                }
            }
                
            if (check_flag(choice1,choice2,choice3,flag)==1 )
            {
                if (category==0)
                    HERO.check_buy(POTION);
                else
                    HERO.check_sell(POTION);
            }
            else
                interface(choice1,choice2,choice3);
        }
    }
    else //choice1 == "Spell"
    {
        if (choice2=="FireSpell")
        {
            FireSpell* FIRESPELL;
            if (category==0) //buy
            {
                for(list<FireSpell*>::iterator it = listofFireSpells.begin(); it!=listofFireSpells.end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        FIRESPELL=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            else //sell
            {
                for(list<FireSpell*>::iterator it = HERO.get_listofHeroFireSpells().begin(); it!=HERO.get_listofHeroFireSpells().end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        FIRESPELL=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            if (check_flag(choice1,choice2,choice3,flag)==1 )
            {
                if (category==0)
                    HERO.check_buy(FIRESPELL);
                else
                    HERO.check_sell(FIRESPELL);
            }
            else
            {
                interface(choice1,choice2,choice3);
            }
        }
        else if (choice2=="IceSpell")
        {
            IceSpell* ICESPELL;
            if (category==0)
            {
                for(list<IceSpell*>::iterator it = listofIceSpells.begin(); it!=listofIceSpells.end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        ICESPELL=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            else //sell
            {
                for(list<IceSpell*>::iterator it = HERO.get_listofHeroIceSpells().begin(); it!=HERO.get_listofHeroIceSpells().end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        ICESPELL=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            if (check_flag(choice1,choice2,choice3,flag)==1 )
            {
                if (category==0)
                    HERO.check_buy(ICESPELL);
                else
                    HERO.check_sell(ICESPELL);
            }
            else
            {
                interface(choice1,choice2,choice3);
            }
        }
        else// if (choice2=="LightingSpell")
        {
            LightingSpell* LIGHTINGSPELL;
            if (category==0) //buy
                for(list<LightingSpell*>::iterator it = listofLightingSpells.begin(); it!=listofLightingSpells.end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        LIGHTINGSPELL=(*it);
                        flag=1;
                        break;
                    }
                }
            else //sell
            {
                for(list<LightingSpell*>::iterator it = HERO.get_listofHeroLightingSpells().begin(); it!=HERO.get_listofHeroLightingSpells().end(); it++)
                {
                    if ((*it)->get_name()==choice3)
                    {
                        LIGHTINGSPELL=(*it);
                        flag=1;
                        break;
                    }
                }
            }
            if (check_flag(choice1,choice2,choice3,flag)==1 )
            {
                if (category==0)
                    HERO.check_buy(LIGHTINGSPELL);
                else
                    HERO.check_sell(LIGHTINGSPELL);
            }
            else
            {
                interface(choice1,choice2,choice3);
            }
        }
    }
    cout << "The transaction has been completed\n";
    cout << "Press enter to continue...\n";
}

void Market::buy(Hero& HERO)
{
    cout << "You chose to buy something" << endl;
    //string choice1,choice2,choice3;
    //choice1: Item or Spell
    //choice2: If Item > Weapon/Armor/Potion
    //         If Spell > FireSpell/IceSpell/LightingSpell
    //choice3: exact name of Item/Spell
    
    //interface(choice1,choice2,choice3);
    iteration(0,HERO);
}
void Market::sell(Hero& HERO)
{
    cout << "You chose to sell something" << endl;
    //string choice1,choice2,choice3;
    //choice1: Item or Spell
    //choice2: If Item > Weapon/Armor/Potion
    //         If Spell > FireSpell/IceSpell/LightingSpell
    //choice3: exact name of Item/Spell
    
    //interface(choice1,choice2,choice3);
    iteration(1,HERO);
}
