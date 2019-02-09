#pragma once
#include "../Living.hpp"
#include "../../Item/Item.hpp"
#include "../../Item/Weapon.hpp"
#include "../../Item/Armor.hpp"
#include "../../Item/Potion.hpp"
#include "../../Spell/Spell.hpp"
#include "../../Spell/FireSpell.hpp"
#include "../../Spell/IceSpell.hpp"
#include "../../Spell/LightingSpell.hpp"

class Hero : public Living
{
protected:
    int magicPower; // WARNING: OI SHMEIWSEIS DEN LENE TI KANEI AUTO
    int max_MP;
    int strength; // this is the strength of the hero and it is added to the amount of damage his weapon causes
    int dexterity; // this helps the hero to make his Spells more efficient 
    double agility; //this is a % chance for the hero to avoid being hit from the opponent
    int money; // shows how much money the hero has
    int experience; // experience at current level
    int exp_to_level_up; //total experience that the hero need to level up
    int hands_in_use; // (0: no hand in use | 1: one hand in use | 2: two hands in use

    bool exit(bool flag);    
    //========================================================
    /*
    In order not to use copy constructors and many other we
    are using the lists below. These lists below, are containing
    all the Items, and spells a Hero has.
    But... for every single item or spell we have a flag which shows
    us whether this item/spell is currently being used from Hero
    or not.
     */
    
    // ***LISTS OF ALL THE PERKS *** //(all the weapons,armors,potions,IceSpells,FireSpells,LightingSpells)
    
    list<Weapon*> listofHeroWeapons;
    list<Armor*> listofHeroArmors;
    list<Potion*> listofHeroPotions;
    list<IceSpell*> listofHeroIceSpells;
    list<FireSpell*> listofHeroFireSpells;
    list<LightingSpell*> listofHeroLightingSpells;
   
public:
    Hero(string NAME, int LEVEL, int HEALTHPOWER, int MAGICPOWER, int STRENGTH, int DEXTERITY, double AGILITY);
    
    void earn_exp(int); //increases exp , and levels up the hero if he reached exp_to_level_up .Also increases exp_to_level_up according to his level
    virtual void level_up()=0 ; 
    void recover_MP(double);
    void increase_AGI(double);

    void set_money(int);//increases money
    void set_MP(int);
    void set_STR(int);
    void set_DEX(int);
    int get_money();
    int get_MP();
    int get_max_MP();
    int get_STR();
    int get_DEX();
    double get_AGI();


    void receive_damage(int); //Hero is attacked
    int basic_attack(); //Hero attacks (returns the damage that he dealt)
    FireSpell* cast_FireSpell();
    IceSpell* cast_IceSpell();
    LightingSpell* cast_LightingSpell();
    bool use_Potion();
 
    void add_Item(Item& ITEM);
    void add_Spell(Spell& SPELL);
    
    
    // check functions chech if a Hero can buy a specifi item bases
    //on his money, level and free hands when needed
    void check_buy(Weapon* WEAPON);
    void check_buy(Armor* ARMOR);
    void check_buy(Potion* POTION);
    void check_buy(FireSpell* FIRESPELL);
    void check_buy(IceSpell* ICESPELL);
    void check_buy(LightingSpell* LIGHTINGSPELL);
    
    void check_sell(Weapon* WEAPON);
    void check_sell(Armor* ARMOR);
    void check_sell(Potion* POTION);
    void check_sell(FireSpell* FIRESPELL);
    void check_sell(IceSpell* ICESPELL);
    void check_sell(LightingSpell* LIGHTINGSPELL);
    
    void equip(Weapon* WEAPON);
    void equip(Armor* ARMOR);
    void equip(Potion* POTION);
    
    //we don't need these three below because Spells are equipped instantly when bought
    //void equip(FireSpell* FIRESPELL);
    //void equip(IceSpell* ICESPELL);
    //void equip(LightingSpell* LIGHTINGSPELL);
    
    void UNequip(Weapon* WEAPON); //We use this function to unequip
    //a weapon from the currentlyusing weapons
    
    list <Weapon*>& get_listofHeroWeapons();
    list <Armor*>& get_listofHeroArmors();
    list <Potion*>& get_listofHeroPotions();
    list <FireSpell*>& get_listofHeroFireSpells();
    list <IceSpell*>& get_listofHeroIceSpells();
    list <LightingSpell*>& get_listofHeroLightingSpells();
    
    void show_inventory();
    void show_inventoryinuse();
    
    virtual ~Hero(); //the destructor is virtual because this is a parent class
    
};
