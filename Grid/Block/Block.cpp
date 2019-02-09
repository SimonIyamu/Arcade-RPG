#include <iostream>
#include "Block.hpp"

using namespace std;

block_type Block::get_type(){
   return type;
}

void Block::show_Market(){}
void Block::buy(Hero& HERO){}
void Block::sell(Hero& HERO){}

Block::Block(){
//   cout << "LOG: A new block was created\n";
}

Block::~Block(){
   //cout << "LOG: A block was destroyed\n";
}
