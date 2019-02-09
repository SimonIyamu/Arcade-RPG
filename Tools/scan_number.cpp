#include <limits>
#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include "scan_number.hpp"

using namespace std;

int getchar_silent()
{
    int ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

int scan_number(int min,int max,string error_message){ //Scan a number from stdin between min and max. Print msg on false input
   int num;
   cin >> num;
   while(num<min || num>max || cin.fail()){
      if(cin.fail()){
         cin.clear();
         cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
      }
      cout << error_message;
      cin >> num;
   }
   return num;
}
