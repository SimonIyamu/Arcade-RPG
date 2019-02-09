#pragma once
#include "../../Living/Hero/Hero.hpp"

enum block_type { NON_ACCESSIBLE, MARKET, COMMON};

class Block{
   protected:
   block_type type;  //mporw na to valw const?
   
   public:
   block_type get_type();
   virtual void show_Market();
   virtual void buy(Hero& HERO);
   virtual void sell(Hero& HERO);

   Block();
   virtual ~Block();
};
