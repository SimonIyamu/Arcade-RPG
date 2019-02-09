#include <iostream>
#include "NonAccessibleBlock.hpp"

using namespace std;

NonAccessibleBlock::NonAccessibleBlock(){
   this->type=NON_ACCESSIBLE;
//   cout << "LOG: A new non accessible block was created\n";
}

NonAccessibleBlock::~NonAccessibleBlock(){
//  cout << "LOG: A non acessible block was destroyed\n";
}
