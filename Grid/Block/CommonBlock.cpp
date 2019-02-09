#include <iostream>
#include "CommonBlock.hpp"

using namespace std;


CommonBlock::CommonBlock(){
   this->type=COMMON;
//   cout << "LOG: A new common block was created\n";
}

CommonBlock::~CommonBlock(){
//   cout << "LOG: A common block was destroyed\n";
}
