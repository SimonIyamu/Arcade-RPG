#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Tools/scan_number.hpp"
#include "Grid/Grid.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    srand (time(NULL));
    cout <<"\033[2J\033[1;1H"; // clears screen
    cout << " __          __ ______  _       _____  ____   __  __  ______                                                         "<<endl;
    cout << " \\ \\        / /|  ____|| |     / ____|/ __ \\ |  \\/  ||  ____|                                                        "<<endl;
    cout << "  \\ \\  /\\  / / | |__   | |    | |    | |  | || \\  / || |__                                                           "<<endl;
    cout << "   \\ \\/  \\/ /  |  __|  | |    | |    | |  | || |\\/| ||  __|                                                          "<<endl; 
    cout << "    \\  /\\  /   | |____ | |____| |____| |__| || |  | || |____  _  _  _                                                "<<endl;
    cout << "     \\/  \\/    |______||______|\\_____|\\____/ |_|  |_||______|(_)(_)(_)                                               "<<endl;
    cout << "   _______  ____    _______  _    _  ______   _    _            _____   _____   ______   _____  _______              "<<endl;
    cout << "  |__   __|/ __ \\  |__   __|| |  | ||  ____| | |  | |    /\\    |  __ \\ |  __ \\ |  ____| / ____||__   __|             "<<endl;
    cout << "     | |  | |  | |    | |   | |__| || |__    | |__| |   /  \\   | |__) || |  | || |__   | (___     | |                "<<endl;
    cout << "     | |  | |  | |    | |   |  __  ||  __|   |  __  |  / /\\ \\  |  _  / | |  | ||  __|   \\___ \\    | |                "<<endl;
    cout << "     | |  | |__| |    | |   | |  | || |____  | |  | | / ____ \\ | | \\ \\ | |__| || |____  ____) |   | | _  _  _        "<<endl;
    cout << "     |_|   \\____/     |_|   |_|  |_||______| |_|  |_|/_/    \\_\\|_|  \\_\\|_____/ |______||_____/    |_|(_)(_)(_)       "<<endl;
    cout << "   _____            __  __  ______   ______ __      __ ______  _____    __  __            _____   ______           _ "<<endl;
    cout << "  / ____|    /\\    |  \\/  ||  ____| |  ____|\\ \\    / /|  ____||  __ \\  |  \\/  |    /\\    |  __ \\ |  ____|         | |"<<endl;
    cout << " | |  __    /  \\   | \\  / || |__    | |__    \\ \\  / / | |__   | |__) | | \\  / |   /  \\   | |  | || |__            | |"<<endl;
    cout << " | | |_ |  / /\\ \\  | |\\/| ||  __|   |  __|    \\ \\/ /  |  __|  |  _  /  | |\\/| |  / /\\ \\  | |  | ||  __|           | |"<<endl;
    cout << " | |__| | / ____ \\ | |  | || |____  | |____    \\  /   | |____ | | \\ \\  | |  | | / ____ \\ | |__| || |____  _  _  _ |_|"<<endl;
    cout << "  \\_____|/_/    \\_\\|_|  |_||______| |______|    \\/    |______||_|  \\_\\ |_|  |_|/_/    \\_\\|_____/ |______|(_)(_)(_)(_)"<<endl;
    cout << "                                                                                                                     ";
    cout << endl;
 
   char input='\0';
   int choice,members;
   string strchoice1,strchoice2;
   Market* marketptr;
   //Create Team
   cout << "Enter the number of team members : ";
   members = scan_number(1,3,"Party members must be 3 or less. Please enter a valid number : ");
   Team team(members);
   //Create Grid
   Grid grid(32,18,team); 
   
   cout <<"\033[2J\033[1;1H"; //Clears screen

   while(true){
      grid.displayMap();
      
      if(input=='g' || input=='G')
         cout << "Move team with W,A,S,D\n"  
            << "Press I to show an inventory\n"
            << "Press U to view the hero's info, which items are equiped and which spells are in use\n"
            << "Press B or T to buy or sell Items respectively while your team is in a Market\n"
            << "Press E to equip an item from your inventory\n"
            << "Press Q to quit game\n";
      else 
         cout << "Press G to preview the Game Guide\n";

      if(input=='q' || input=='Q')
         break;
      if(input=='b' || input=='B' || input=='t' || input=='T'){ //TODO:na kanw na ginetai clear screen kai to market na mpainei ekei pou empaine to map
         if(grid.team_in_market()){
            cout << "\033[1;33m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
            cout << " \033[1;33m |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl; 
            cout << "                   __  __            _____   _  __ ______  _______                 " << endl; 
            cout << "                  |  \\/  |    /\\    |  __ \\ | |/ /|  ____||__   __|                " << endl; 
            cout << "                  | \\  / |   /  \\   | |__) || ' / | |__      | |                   " << endl; 
            cout << "                  | |\\/| |  / /\\ \\  |  _  / |  <  |  __|     | |                   " << endl; 
            cout << "                  | |  | | / ____ \\ | | \\ \\ | . \\ | |____    | |                   " << endl; 
            cout << "                  |_|  |_|/_/    \\_\\|_|  \\_\\|_|\\_\\|______|   |_|                   " << endl; 
            cout << " \033[1;33m  ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
            cout << " \033[1;33m |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;
            cout << "Welcome to the Market.Here you can buy or sell Items and Spells\n";
            marketptr=grid.get_marketptr(team.get_x(),team.get_y());
            marketptr->show_Market();
            if(members>1){
               cout << "Choose which member enters the store by typing his index(1, 2 or 3)\n";
               grid.print_team();
   
               choice = scan_number(1,members,"Please enter a valid number: ");
               if(input=='b' || input=='B') 
                  marketptr->buy(team.get_member(choice));
               else
                  marketptr->sell(team.get_member(choice));
            }
            else
               if(input=='b' || input=='B') 
                  marketptr->buy(team.get_member(1));
               else
                  marketptr->sell(team.get_member(1));
         }else
            cout << "You must be in the Market in order to buy or sell goods" << endl;
      }
      if(input=='u' || input=='U'){
         if(members>1){
            cout << "Choose which members' info you want to see(1, 2 or 3)\n";
            grid.print_team();
            choice=scan_number(1,members,"Please enter a valid number: ");
            getchar();
         }else
             choice=1;
         team.get_member(choice).show_inventoryinuse();
      }
      if(input=='i' || input=='I'){
         if(members>1){
            cout << "Choose which members invectory you want to see(1, 2 or 3)\n";
            grid.print_team();
            choice=scan_number(1,members,"Please enter a valid number: ");
            getchar();
         }else
            choice=1;
         team.get_member(choice).show_inventory();
      }

      input=getchar_silent(); //Einai ulopoihmenh sto arxeio scan_number.cpp

      if(input=='w' || input=='W'|| input=='a' || input=='A'|| input=='s'  || input=='S'|| input=='d' || input=='D'){
         grid.move(input);
      }
      
      if(input=='e' || input == 'E'){
        bool flag=false;
        cout << "Type Weapon/Armor" << endl;
        getline(cin, strchoice1);
        while ((strchoice1!="Weapon") && (strchoice1 != "Armor")){
            cout << "ERROR: Type again Weapon/Armor/Potion" << endl;
            getline(cin, strchoice1);
        }
        cout << "Type the exact name of the goody" << endl;
        getline(cin, strchoice2);

        if(members>1){
            cout << "Choose which member will equip the item(1, 2 or 3)\n";
            grid.print_team();
            choice=scan_number(1,members,"Please enter a valid number: ");
            getchar();
         }else
            choice=1;

        if (strchoice1=="Weapon"){
            for(list<Weapon*>::iterator it = team.get_member(choice).get_listofHeroWeapons().begin(); it!=team.get_member(choice).get_listofHeroWeapons().end(); it++){
                if ((*it)->get_name()==strchoice2){
                    team.get_member(choice).equip((*it));
                    flag=true;
                    break;
                }
            }
        }
        else
            for(list<Armor*>::iterator it = team.get_member(choice).get_listofHeroArmors().begin(); it!=team.get_member(choice).get_listofHeroArmors().end(); it++){
                if ((*it)->get_name()==strchoice2){
                    team.get_member(choice).equip((*it));
                    flag=true;
                    break;
                }
            }
        if(!flag){
            cout << "Item not found in Hero's inventory\n";
        }
        cout << "Press enter to continue...\n";
        getchar();
      }
   }
   
   return 0;
}
