#pragma once
#include "Item.hpp"

using namespace std;

enum Stat { STR, DEX, AGI, HP, MP };

class Potion : public Item
{
private:
    bool used; //it shows whether a Potion is used or not // 0: potion is not used yet | 1: potion is used
    Stat stat;
    double increasement; // it is a % which shows how much a statistic is increased
public:
    Potion(string NAME, int PRICE, int MIN_LEVEL, double INCREASEMENT,Stat); //constructor
    void print_info();
    Stat get_stat();
    double get_increasement();
};

