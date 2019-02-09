#pragma once

#include <string>
#include <iostream>

using namespace std;

class Item
{
protected:
    string name;
    int price;
    int min_level;
    bool currentlyusing; // 0: not in use currently |1: currently in use
public:
    Item(string Name, int PRICE, int MIN_LEVEL); //constructor
    
    virtual void print_info();
    
    //accessors
    string get_name();
    int get_price();
    int get_min_level();
    bool get_currentlyusing();
    
    void set_currentlyusing(bool check);
    
};
