#include <iostream>
#include "Spirit.hpp"

using namespace std;

Spirit::Spirit(string name,int level) : Monster(name,level,150 + 10*pow(level,2),40 + 10*pow(level,2) ,50 + 12*pow(level,2), 5 + 10*level,0.3){
   cout << "A " << name << " Spirit has appeared!\n";
}

Spirit::~Spirit(){
   cout << "LOG: " << name << " Spirit was destroyed!\n";
}

