#include <list>
#include "../../Living/Monster/Dragon.hpp"
#include "../../Living/Monster/Exoskeleton.hpp"
#include "../../Living/Monster/Spirit.hpp"


class Gang{
   int n;
   std::list<Monster*> members; // lista apo deiktes se monsters

   public:
   Monster& get_member(int);
   int get_n();
   void print_members();
   bool is_defeated();
   void recover(); //Members recover some HP and MP 
   void display_stats();

   Gang(int,int);
   ~Gang();
};
