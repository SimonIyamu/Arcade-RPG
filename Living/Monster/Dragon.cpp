#include <iostream>
#include "Dragon.hpp"

using namespace std;

Dragon::Dragon(string name,int level) : Monster(name,level,200 + 10*pow(level,2),50 + 12*pow(level,2) ,60 + 14*pow(level,2), 5 + 10*pow(level,1.5),0.1){
   cout << "A " << name << " Dragon has appeared!\n";
}

Dragon::~Dragon(){
   cout << "LOG: " << name << " Dragon was destroyed!\n";
}

