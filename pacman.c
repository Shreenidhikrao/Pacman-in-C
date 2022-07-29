// PACMAN GAME 

#include <stdio.h> 
#include "header.h"
#include <windows.h>
#include <stdbool.h>

#define H 28
#define W 100 


int main()
{
   system("cls");// clears the cmd so that the playfield will always be placed from the first 
   hidecursor();
   initialize();

   while (1)
   {
      set_cursor_position(0,0);
      user_input();
      move_figures();
      show_playfield();
      Sleep( 1000 /50 );//whith the sleep function we can make the screen sleep for particular interval of time 
                        //so that we can take care of the speed by which pacman moves 
   }
}



