#include "Block/Block.hpp"
#include "Block/Market.hpp"
#include "Block/CommonBlock.hpp"
#include "Block/NonAccessibleBlock.hpp"
#include "Team/Team.hpp"
#include "Gang/Gang.hpp"

//TODO na valw const opou xreiazetai( metavlhtes kai meta apo orismous sunarthsewn)

class Grid{
   Team *team;
   Block ***blocks;
   int width;
   int height;

   public:
   Market* get_marketptr(int,int);
   void move(char); //Moves team to the direction of the argument using W,A,S,D keys format
   void displayMap();
   bool team_in_market();
   void print_team();
   void battle();

   Grid(int, int, Team&);
   virtual ~Grid();
};
