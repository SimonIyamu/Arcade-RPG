

#include "Item.hpp"

//constructor of class Item
Item::Item(string NAME,int PRICE, int MIN_LEVEL): currentlyusing(0)
{
    name=NAME; //its a string, so no need to use strcpy
    price=PRICE;
    min_level=MIN_LEVEL;
}

void Item::print_info()
{
    cout.width(30);
    cout << left << name;
    cout.width(15);
    cout << left << price;
    cout.width(15);
    cout << left << min_level;
   // cout << "Name: " << name << " Price: " << price << " Minimun Level: " << min_level << " ";
    
}

string Item::get_name()
{
    return name;
}

int Item::get_price()
{
    return price;
}

int Item::get_min_level()
{
    return min_level;
}

bool Item::get_currentlyusing()
{
    return currentlyusing;
}

void Item::set_currentlyusing(bool check)
{
    currentlyusing=check;
}
