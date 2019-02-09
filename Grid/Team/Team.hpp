#include "../../Living/Hero/Hero.hpp"
#include "../../Living/Hero/Warrior.hpp"
#include "../../Living/Hero/Sorcerer.hpp"
#include "../../Living/Hero/Paladin.hpp"

class Team{    //einai san lista apo heroes 
   int x;
   int y;
   int n; //number of team members;
   list<Hero*>  members; // lista apo deiktes se heroes

   public: //Anti gia setters kai getters 8a mporousa kapws na afhnw to grid na exei prosvash sta private toy Team..(alla isws einai kakh idea)
   void set_x(int);
   void set_y(int);
   Hero& get_member(int);
   int get_x();
   int get_y();
   int get_n();
   int get_avg_lvl(); //returns the average level of the teams' members
   bool is_defeated(); // returns 1 if the team is defeated
   void print_members();
   void lost_battle();  //Members lose half of their coins
   void recover(); //Members recover some HP and MP 
   void resurect_defeated_members();
   void display_stats(); //Display team stats

   Team(int);
   ~Team();
};
