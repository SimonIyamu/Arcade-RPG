#pragma once

#include <string>
#include <list>


class Living
{
protected:
    std::string name; //the name of the living
    int level; //the level of the living
    int healthPower; // when healthPower==0 the living faints(=lipothimaei)
    int max_HP; //max health Power
    
    //we have a list of Items and a list of Spells, in which we keep
    //all the Items and all the Spells a Living has
    
public:
    Living(std::string name, int level, int Healthpower); //constructor
    
    void set_name(std::string);
    void set_HP(int);
    std::string get_name();
    int get_level();
    int get_HP();
    int get_max_HP();
    void recover_HP(double); //Recovers a percentage of total HP
    void change_healthPower(int quantity); //mutator
};
