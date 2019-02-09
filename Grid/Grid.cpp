#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "Grid.hpp"
#include "../Tools/scan_number.hpp"

using namespace std;

void Grid::move(char dir){
   int x=team->get_x(),y=team->get_y(),r;
   bool flag=0;
   switch(dir){
      case 'd':
      case 'D':
         if(x+1 < width && blocks[y][x+1]->get_type()!=NON_ACCESSIBLE){
            team->set_x(x + 1);
            flag =1;
         }
         break;
      case 's':
      case 'S':
         if(y+1 < height && blocks[y+1][x]->get_type()!=NON_ACCESSIBLE){
            team->set_y(y + 1);
            flag=1;
         }
         break;
     case 'a':
     case 'A':
         if(x-1 >= 0 && blocks[y][x-1]->get_type()!=NON_ACCESSIBLE){
            team->set_x(x - 1);
            flag=1;
         }
         break;
     case 'w':
     case 'W':
         if(y-1 >= 0 && blocks[y-1][x]->get_type()!=NON_ACCESSIBLE){
            team->set_y(y - 1);
            flag=1;
         }
         break;
   }
   if(flag && !team_in_market() && rand()%25==0) //4% chance to find a monster
      battle();
}

void Grid::displayMap(){         //na to kanw pio cpp kai pio ka8aro an ginetai
   int i,j;
   cout <<"\033[2J\033[1;1H";
   cout << "x= " << team->get_x() << ", y= "<< team->get_y() << "\n";
   for(i=0;i<width+2;i++)
      cout << "* ";				//Prints the Top of the box
   cout << endl;
   for(i=0;i<height;i++){
      cout << "* ";				//Prints the Left side of the box
      if(i==team->get_y()){				//if j==y then C must be printed in this line
         for(j=0 ; j<team->get_x() ; j++){
            if(blocks[i][j]->get_type()==COMMON)
               cout << " ";
            else if (blocks[i][j]->get_type()==MARKET) 
               cout << "\033[1;33mM\033[0m";
            else
               cout << "*";	//fill with spaces before C 
            cout << " ";		//Vazw 2 kena ka8e fora wste na einai omoiomorfo me ta \n tou y
         }
         cout << "\033[1;31mi \033[0m";
         //fill with spaces after team and *
         for( j=team->get_x()+1 ; j < width ; j++){
            if(blocks[i][j]->get_type()==COMMON)
               cout << " ";
            else if (blocks[i][j]->get_type()==MARKET) 
               cout << "\033[1;33mM\033[0m";
            else 
               cout << "*";
            cout << " ";
         }
         cout << "*";
      }
      else{
         for(j=0;j<width;j++)		//fills with enough spaces to print the Right side of the box.
            if(blocks[i][j]->get_type()==COMMON)
                  cout << "  ";
            else if (blocks[i][j]->get_type()==MARKET) 
               cout << "\033[1;33mM \033[0m";
           else 
               cout << "* ";
         cout << "*" ;
      }
      cout << endl;
   }
   for(j=0;j<width+2;j++)				//Prints the Bottom of the box
      cout << "* ";
   cout << endl;
}

Market* Grid::get_marketptr(int x,int y){
   return dynamic_cast<Market*>(blocks[y][x]);
}

bool Grid::team_in_market(){
   return blocks[team->get_y()][team->get_x()]->get_type()==MARKET;
}

void Grid::print_team(){
   team->print_members(); 
}

void Grid::battle(){
    cout <<"\033[2J\033[1;1H";
    cout << "\033[1;34m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
    cout << "\033[1;34m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl; 
    cout << "               ____         _______  _______  _       ______  _  _  _              " << endl; 
    cout << "              |  _ \\    /\\ |__   __||__   __|| |     |  ____|| || || |             " << endl; 
    cout << "              | |_) |  /  \\   | |      | |   | |     | |__   | || || |             " << endl; 
    cout << "              |  _ <  / /\\ \\  | |      | |   | |     |  __|  | || || |             " << endl; 
    cout << "              | |_) |/ ____ \\ | |      | |   | |____ | |____ |_||_||_|             " << endl; 
    cout << "              |____//_/    \\_\\|_|      |_|   |______||______|(_)(_)(_)             " << endl; 
    cout << "\033[1;34m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
    cout << "\033[1;34m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl; 
   int n=team->get_n(),lvlofmonsters=team->get_avg_lvl(),round=1,damage,monsterchoice,random,
       firespell_debuff_endround = -1,firespell_reduce_ammount,firespell_monster,
       icespell_debuff_endround = -1,icespell_min_dmg_reduce_ammount,icespell_max_dmg_reduce_ammount,icespell_monster,
       lightingspell_debuff_endround = -1,lightingspell_monster; //If there were more than three spell types in our game we would use some diffrent data type than just variables
   double lightingspell_reduce_ammount;
   char choice;
   bool potion_flag;
   int team_member_index=1;
   string spellchoice;
   Gang gang(n,lvlofmonsters);    //ME auton ton tropo ta terata 8a einai osoi oi heroes... 8a mporousa na valw kai rand()%3

   while(1){   //Battle loop

      choice='\0';
      cout << "~~~~~~ ROUND " << round << "! ~~~~~~\n";
      cout << "~~~~~~   FIGHT!  ~~~~~~\n\n";
      //Heroes' turn
      while(choice!='a' && choice!='c' && choice!='u'){
          int team_member_index=1;
          while(team_member_index<=team->get_n() && !gang.is_defeated()){

             if(team->get_member(team_member_index).get_HP()){                     //If Hero is alive
                 cout << "It's " << team->get_member(team_member_index).get_name() << "'s turn.\n";
                 cout << "Choose an option (A: Attack / C: Cast Spell / U: Use Potion / D: Display Stats):";
                 cin >> choice;
                 cout << endl;
                 switch(choice){
                    case 'A':
                    case 'a':
                       if(gang.get_n()>1){ //if there are more than one monsters
                          cout << "Choose which monster you want to attack(1, 2 or 3)\n";
                          gang.print_members();
                          monsterchoice=scan_number(1,gang.get_n(),"Please enter a valid number : ");
                       }
                       else
                          monsterchoice=1;

                       gang.get_member(monsterchoice).receive_damage(team->get_member(team_member_index).basic_attack()); //monster receives a basic attack
                       team_member_index++; //It's the next member's turn
                       break;
                    case 'C':
                    case 'c':
                       //Spell Type selection
                       cout << "Choose what kind of spell you want to use (FireSpell/IceSpell/LightingSpell)" << endl;
                       cin >> spellchoice;
                       while (spellchoice!="FireSpell" && spellchoice!="IceSpell" && spellchoice!= "LightingSpell"){
                          cout << "ERROR: Type again FireSpell/IceSpell/LightingSpell" << endl;
                          cin >> spellchoice;
                       }

                        //Monster selection
                       if(gang.get_n()>1){ //if there are more than one monsters
                          cout << "Choose which monster you want to attack(1, 2 or 3)\n";
                          gang.print_members();
                          monsterchoice=scan_number(1,gang.get_n(),"Please enter a valid number : ");
                       }
                       else
                          monsterchoice=1;

                       if(spellchoice == "FireSpell"){ //TODO:Kai ginetai to debuff kai twn allwn spell
                             FireSpell* fireSpell = team->get_member(team_member_index).cast_FireSpell();
                             if(fireSpell==NULL)
                                 damage=-1;
                             else{ 
                                //Spend magic energy
                                team->get_member(team_member_index).set_MP(team->get_member(team_member_index).get_MP() + fireSpell->get_magic_energy_needed());
                                //Save damage
                                damage = fireSpell->get_min_damage() + rand()%(fireSpell->get_max_damage() - fireSpell->get_min_damage());
                             
                                firespell_monster=monsterchoice;
                                if(firespell_debuff_endround < round){ 
                                   //If endround < round then there is no other firespell debuff on the monster at the current round
                                   firespell_reduce_ammount = gang.get_member(monsterchoice).get_defence()*(fireSpell->get_def_reducer())/100;
                                   //Reduce monster's defence
                                   gang.get_member(monsterchoice).set_defence(gang.get_member(monsterchoice).get_defence() - firespell_reduce_ammount);
                                   cout << "Reduced defence of " << gang.get_member(monsterchoice).get_name() 
                                        << " by " << firespell_reduce_ammount << " for " << fireSpell->get_rounds() << " rounds.\n";
                                }
                                else //If the monster has already a firespell debuff then the defence reduce ammount stays the same but we increase the duration of the debuff.
                                   cout << "Increased duration of FireSpell debuff by " << fireSpell->get_rounds() << " rounds\n";
                                firespell_debuff_endround= round + fireSpell->get_rounds(); 
                             }
                       }
                       else if(spellchoice == "IceSpell"){

                             IceSpell* iceSpell = team->get_member(team_member_index).cast_IceSpell();
                             if(iceSpell==NULL)
                                 damage=-1;
                             else{ 
                                //Spend magic energy
                                team->get_member(team_member_index).set_MP(team->get_member(team_member_index).get_MP() + iceSpell->get_magic_energy_needed());
                                //Save damage
                                damage = iceSpell->get_min_damage() + rand()%(iceSpell->get_max_damage() - iceSpell->get_min_damage());
                             
                                icespell_monster=monsterchoice;
                                if(icespell_debuff_endround < round){ 
                                   //If endround < round then there is no other icespell debuff on the monster at the current round
                                   icespell_min_dmg_reduce_ammount = gang.get_member(monsterchoice).get_min_dmg()*(iceSpell->get_min_dmg_reducer())/100;
                                   icespell_max_dmg_reduce_ammount = gang.get_member(monsterchoice).get_max_dmg()*(iceSpell->get_max_dmg_reducer())/100;
                                   //Reduce monster's min and max damage
                                   gang.get_member(monsterchoice).set_min_dmg(gang.get_member(monsterchoice).get_min_dmg() - icespell_min_dmg_reduce_ammount);
                                   gang.get_member(monsterchoice).set_max_dmg(gang.get_member(monsterchoice).get_max_dmg() - icespell_max_dmg_reduce_ammount);
                                   cout << "Reduced min damage of " << gang.get_member(monsterchoice).get_name() 
                                        << " by " << icespell_min_dmg_reduce_ammount
                                       << " and max damage for " << icespell_max_dmg_reduce_ammount << " for " << iceSpell->get_rounds() << " rounds.\n";
                                }
                                else //If the monster has already a icespell debuff then the min and max damage reduce ammounts stay the same but we increase the duration of the debuff.
                                   cout << "Increased duration of IceSpell debuff by " << iceSpell->get_rounds() << " rounds\n";
                                icespell_debuff_endround= round + iceSpell->get_rounds(); 
                             }
                       }
                       
                       else{ // spellchoice== Lighting spell

                             LightingSpell* lightingSpell = team->get_member(team_member_index).cast_LightingSpell();
                             if(lightingSpell==NULL)
                                 damage=-1;
                             else{ 
                                //Spend magic energy
                                team->get_member(team_member_index).set_MP(team->get_member(team_member_index).get_MP() + lightingSpell->get_magic_energy_needed());
                                //Save damage
                                damage = lightingSpell->get_min_damage() + rand()%(lightingSpell->get_max_damage() - lightingSpell->get_min_damage());
                             
                                lightingspell_monster=monsterchoice;
                                if(lightingspell_debuff_endround < round){ 
                                   //If endround < round then there is no other lightingspell debuff on the monster at the current round
                                   lightingspell_reduce_ammount = gang.get_member(monsterchoice).get_ch2a()*(lightingSpell->get_ch2a_reducer())/100;
                                   //Reduce monster's chance to avoid
                                   gang.get_member(monsterchoice).set_ch2a(gang.get_member(monsterchoice).get_ch2a() - lightingspell_reduce_ammount);
                                   cout << "Reduced chance to avoid of " << gang.get_member(monsterchoice).get_name() 
                                        << " by " << lightingspell_reduce_ammount << " for " << lightingSpell->get_rounds() << " rounds.\n";
                                }
                                else //If the monster has already a lightingspell debuff then the chance to avoid reduce ammount stays the same but we increase the duration of the debuff.
                                   cout << "Increased duration of LightingSpell debuff by " << lightingSpell->get_rounds() << " rounds\n";
                                lightingspell_debuff_endround= round + lightingSpell->get_rounds(); 
                             }

                       }
                       if (damage == -1) // -1 is returned when player wants to exit spell casting
                       {
                          choice='\0'; //if we don't change choice then while will be skipped
                          continue;
                       }
                       damage = damage + team->get_member(team_member_index).get_DEX()*5/100; //Damage is increased depending on the hero's dex
                       gang.get_member(monsterchoice).receive_damage(damage); //monster receives damage from spell
                       team_member_index++;
                       break;
                    case 'U':
                    case 'u':
                       potion_flag = team->get_member(team_member_index).use_Potion();
                       if (potion_flag==false){
                          choice='\0'; //if we don't change choice then while will be skipped
                          continue;
                       }
                       team_member_index++;
                       break;
                    case 'D':
                    case 'd':
                       cout << "================================================\n";
                       cout << "|                  Team stats:                 |\n";
                       cout << "================================================\n\n";
                       team->display_stats();
                       cout << "\n================================================\n";
                       cout << "|                  Gang stats:                 |\n";
                       cout << "================================================\n\n";
                       gang.display_stats();
                       break;
                    default:
                       choice = '\0';
                       cout << "Wrong input. Please try again\n";
                       break;
                 }
                 if(gang.is_defeated()){
                    cout <<"\033[2J\033[1;1H";
                    cout << "\033[1;32m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______ \033[0m " << endl; 
                    cout << "\033[1;32m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl; 
                    cout << "            __      __ _____  _____  _______  ____   _____ __     __               " << endl; 
                    cout << "            \\ \\    / /|_   _|/ ____||__   __|/ __ \\ |  __ \\\\ \\   / /               " << endl; 
                    cout << "             \\ \\  / /   | | | |        | |  | |  | || |__) |\\ \\_/ /                " << endl; 
                    cout << "              \\ \\/ /    | | | |        | |  | |  | ||  _  /  \\   /                 " << endl; 
                    cout << "               \\  /    _| |_| |____    | |  | |__| || | \\ \\   | |                  " << endl; 
                    cout << "                \\/    |_____|\\_____|   |_|   \\____/ |_|  \\_\\  |_|                  " << endl; 
                    cout << " \033[1;32m  ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
                    cout << " \033[1;32m |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl; 
                    cout << "                                                                                   " << endl; 
                    cout << " 	                                .-. " << endl; 
                    cout << " 	       	                       {{@}} " << endl; 
                    cout << " 	               <>               8@8 " << endl; 
                    cout << " 	             .::::.             888 " << endl; 
                    cout << " 	         @\\\\/W\\/\\/W\\//@         8@8 " << endl; 
                    cout << " 	          \\\\/^\\/\\/^\\//     _    )8(    _ " << endl; 
                    cout << " 	           \\_O_<>_O_/     (@)__/8@8\\__(@) " << endl; 
                    cout << " 	      ____________________ `~\"-=):(=-\"~` " << endl; 
                    cout << " 	     |<><><>  |  |  <><><>|     |.| " << endl; 
                    cout << " 	     |<>      |  |      <>|     | | " << endl; 
                    cout << " 	     |<>      |  |      <>|     |'| " << endl; 
                    cout << " 	     |<>   .--------.   <>|     |.| " << endl; 
                    cout << " 	     |     |   ()   |     |     |W| " << endl; 
                    cout << " 	     |_____| (O\\/O) |_____|     |'| " << endl; 
                    cout << " 	     |     \\   /\\   /     |     |.| " << endl; 
                    cout << " 	     |------\\  \\/  /------|     |I| " << endl; 
                    cout << " 	     |       '.__.'       |     |'| " << endl; 
                    cout << " 	     |        |  |        |     |.| " << endl; 
                    cout << " 	     :        |  |        :     |N| " << endl; 
                    cout << " 	      \\<>     |  |     <>/      |'| " << endl; 
                    cout << " 	       \\<>    |  |    <>/       |.| " << endl; 
                    cout << " 	        \\<>   |  |   <>/        | | " << endl; 
                    cout << " 	         `\\<> |  | <>/'         |'| " << endl; 
                    cout << " 	           `-.|  |.-`           \\ / " << endl; 
                    cout << "         	      '--'               ^                                                                          " << endl; 
                    cout << "                                                                                   " << endl; 

                    //Earn money and exp
                    for(int i =1 ; i <= team->get_n() ; i++){
                        if(team->get_member(i).get_HP()){ //only alive members gain rewards
                            team->get_member(i).earn_exp(pow(lvlofmonsters,2) + 99);
                            team->get_member(i).set_money(team->get_member(i).get_money() + pow(lvlofmonsters,1.5) + 99);
                        }
                    }
                    cout << "Press enter to continue...";
                    getchar();
                    team->resurect_defeated_members();
                    break;
                 }
            }else
                team_member_index++;     //If member is dead then move on to the next member
          }
      }
      if(gang.is_defeated())
               break;
      
      //Monster's turn
      for(int gang_member_index = 1 ; gang_member_index <= gang.get_n() ; gang_member_index++){
        random=rand()%team->get_n()+1;
        if(team->get_member(random).get_HP()) //if hero is alive then the monster can attack him
           team->get_member(random).receive_damage((gang.get_member(gang_member_index)).attack()); //Every monster attacks a random hero from the team
        else{       //if hero is not alive then the monster will attack the first alive hero
            int i=1;
            while(!team->get_member(i).get_HP())
                i++;
            team->get_member(i).receive_damage((gang.get_member(gang_member_index)).attack()); //Every monster attacks a random hero from the team
        }
      }

       if(team->is_defeated()){

        cout <<"\033[2J\033[1;1H";
        cout << "  " << endl; 
        cout << "\033[1;31m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
        cout << " \033[1;31m |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl; 
        cout << "                   _____   ______  ______  ______         _______                  " << endl; 
        cout << "                  |  __ \\ |  ____||  ____||  ____|    /\\ |__   __|                 " << endl; 
        cout << "                  | |  | || |__   | |__   | |__      /  \\   | |                    " << endl; 
        cout << "                  | |  | ||  __|  |  __|  |  __|    / /\\ \\  | |                    " << endl; 
        cout << "                  | |__| || |____ | |     | |____  / ____ \\ | |                    " << endl; 
        cout << "                  |_____/ |______||_|     |______|/_/    \\_\\|_|                    " << endl; 
        cout << " \033[1;31m  ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
        cout << "  \033[1;31m|______||______||______||______||______||______||______||______||______||______| \033[0m" << endl; 
        cout << "                                                                 _ " << endl; 
        cout << "                                                               _( (~\\ " << endl; 
        cout << "        _ _                        /                          ( \\> > \\ " << endl; 
        cout << "    -/~/ / ~\\                     :;                \\       _  > /(~\\/ " << endl; 
        cout << "   || | | /\\ ;\\                   |l      _____     |;     ( \\/    > > " << endl; 
        cout << "   _\\\\)\\)\\)/ ;;;                  `8o __-~     ~\\   d|      \\      // " << endl; 
        cout << "  ///(())(__/~;;\\                  \"88p;.  -. _\\_;.oP        (_._/ / " << endl; 
        cout << " (((__   __ \\\\   \\                  `>,% (\\  (\\./)8\"         ;:'  i " << endl; 
        cout << " )))--`.'-- (( ;,8 \\               ,;%%%:  ./V^^^V'          ;.   ;. " << endl; 
        cout << " ((\\   |   /)) .,88  `: ..,,;;;;,-::::::'_::\\   ||\\         ;[8:   ; " << endl; 
        cout << "  )|  ~-~  |(|(888; ..``'::::8888oooooo.  :\\`^^^/,,~--._    |88::  | " << endl; 
        cout << "  |\\ -===- /|  \\8;; ``:.      oo.8888888888:`((( o.ooo8888Oo;:;:'  | " << endl; 
        cout << "  |_~-___-~_|   `-\\.   `        `o`88888888b` )) 888b88888P""'     ; " << endl; 
        cout << "  ; ~~~~;~~         \"`--_`.       b`888888888;(.,\"888b888\"  ..::;-' " << endl; 
        cout << "    ;      ;              ~\"-....  b`8888888:::::.`8888. .:;;;'' " << endl; 
        cout << "       ;    ;                 `:::. `:::OOO:::::::.`OO' ;;;'' " << endl; 
        cout << "  :       ;                     `.      \"``::::::''    .' " << endl; 
        cout << "     ;                           `.   \\_              / " << endl; 
        cout << "   ;       ;                       +:   ~~--  `:'  -'; " << endl; 
        cout << "                                    `:         : .::/   " << endl; 
        cout << "       ;                            ;;+_  :::. :..;;;   " << endl; 
        cout << "                                    ;;;;;;,;;;;;;;;,; " << endl; 
        cout << "  " << endl; 
        cout << "  " << endl; 
        team->lost_battle();
        cout << "Press enter to continue...";
        team->resurect_defeated_members();
        getchar();
        break;
      }

      team->recover();  //In each round, the heroes and the monster recover some HP or MP
      gang.recover();
      round++;
      if(round==icespell_debuff_endround){
        gang.get_member(icespell_monster).set_min_dmg(gang.get_member(icespell_monster).get_min_dmg() + icespell_min_dmg_reduce_ammount);
        gang.get_member(icespell_monster).set_max_dmg(gang.get_member(icespell_monster).get_max_dmg() + icespell_max_dmg_reduce_ammount);
        cout << gang.get_member(icespell_monster).get_name() << "'s IceSpell debuff ended\n";
      }
      if(round==firespell_debuff_endround){
        gang.get_member(firespell_monster).set_defence(gang.get_member(firespell_monster).get_defence() + firespell_reduce_ammount);
        cout << gang.get_member(firespell_monster).get_name() << "'s FireSpell debuff ended\n";
      }
     if(round==lightingspell_debuff_endround){
        gang.get_member(lightingspell_monster).set_ch2a(gang.get_member(lightingspell_monster).get_ch2a() + lightingspell_reduce_ammount);
        cout << gang.get_member(lightingspell_monster).get_name() << "'s LightingSpell debuff ended\n";
      }
 
   }
   getchar();
}

Grid::Grid(int w, int h,Team &rteam) : width(w), height(h) , team(&rteam){
  //Allocate memory
   blocks = new Block**[h];
   for(int i=0; i<h ; i++) 
      blocks[i] = new Block*[w];
   int j;
   for(int i=0 ; i<h ; i++)
      for(j=0 ; j<w ; j++)
         if(rand()%10)
            blocks[i][j] = new CommonBlock();
         else
            if(rand()%4)
               blocks[i][j] = new NonAccessibleBlock();
            else
               blocks[i][j] = new Market();

      cout <<endl;
   /*//print just for debuging 
   cout << "tiles board:" << endl;
   for(int i=0; i<h ; i++){
      cout <<endl;
      for(int j=0; j<w ; j++)
         cout << tiles[i][j] << "  ";
   }
   */
   //cout << "LOG:A new grid was just created\n";
}

Grid::~Grid(){
    int i,j;
    for(i=0 ; i<height ; i++){
      for(j=0 ; j<width ; j++)
        delete blocks[i][j];
      delete[] blocks[i];
    }

    delete[] blocks;

    //cout << "LOG: A grid was just destroyed\n";
}
