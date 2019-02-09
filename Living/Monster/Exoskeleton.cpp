#include <iostream>
#include "Exoskeleton.hpp"

using namespace std;

Exoskeleton::Exoskeleton(string name,int level) : Monster(name,level,150 + 10*pow(level,2),40 + 10*pow(level,2) ,50 + 12*pow(level,2), 10 + 12*level,0.1){
   cout << "A " << name << " Exoskeleton has appeared!\n";
}

Exoskeleton::~Exoskeleton(){
   cout << "LOG: " << name << " Exoskeleton was destroyed!\n";
}

