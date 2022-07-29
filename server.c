#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdbool.h>
#include "header.h"

#define H 28
#define W 100 

struct PacMan mypacman = {{.x = 40,.y = 12},.vx = 0,.vy = 0,.food_collected = 0};

// creating a playfield 
char playfield[H][W] = 
{
   {"_________________________________________________________________________________"},
   {"|                                       #                                       |"},
   {"|                                       #                                       |"},
   {"|     #######        #######            #        #######        #######         |"},
   {"|                                                                               |"},
   {"|                                                                               |"},
   {"|                                                                               |"},
   {"|     #######                 #######################           #######         |"},
   {"|                                                                               |"},
   {"|                                       #                                       |"},
   {"|                                       #                                       |"},
   {"|#######                    #                       #                     ######|"},
   {"|                           #                       #                           |"},
   {"|#######                    #########################                     ######|"},
   {"|                                                                               |"},
   {"|                                       #                                       |"},
   {"|                                       #                                       |"},
   {"|                                                                               |"},
   {"|    #######                #########################          #######          |"},
   {"|                                                                               |"},
   {"|                                                                               |"},
   {"|                                                                               |"},
   {"|    #######         #######            #        #######        #######         |"},
   {"|                                       #                                       |"},
   {"|                                       #                                       |"},
   {"|_______________________________________________________________________________|"},
};

void initialize()
{
   // 1. replace each empty field in the playfield
   //    with a food field
   for (int i = 0; i < H; i+=2)
   {
      for (int j = 0; j < W; j+=3)
      {
         if (playfield[i][j]==' ')
            playfield[i][j] = '.';
      }
   }
} // initialize


void user_input()
{
   if (kbhit()) //kbhit - it is a function in conio.h to determine if the key is pressed or not 
   {             //it returns non zero value if the key is pressed otherwise zero 
      char c1 = getch();

      if (c1 == -32)
      {
         char c2 = getch();

         mypacman.vx = 0;
         mypacman.vy = 0;

         switch (c2)
         {
            case 72: // 72 is the ascii value of up arrow 
               mypacman.vy = -1; 
               break; // cursor up
            case 80: 
               mypacman.vy = +1; 
               break; // cursor down
            case 75: 
               mypacman.vx = -1; 
               break; // cursor left
            case 77: 
               mypacman.vx = +1; 
               break; // cursor right            
         }
      }
   }
}


void move_figures()
{
   // 1. delete PacMan from old position
   playfield[mypacman.position.y][mypacman.position.x] = ' ';

   // 2. compute new desired coordinate (nx,ny)
   int nx = mypacman.vx + mypacman.position.x;
   int ny = mypacman.vy + mypacman.position.y;

   // 3.to see if there is a wall and make the pacman stop 
   if (playfield[ny][nx] == '|'|| playfield[ny][nx] == '_' ||  playfield[ny][nx] == '#')
   {
      mypacman.vx = 0;
      mypacman.vy = 0;
   }

   // 4. updating pacman's coordinate
   mypacman.position.x += mypacman.vx;
   mypacman.position.y += mypacman.vy;

   // 5. is there a food piece at the new location?
   if (playfield[ny][nx] == '.')
   {
      mypacman.food_collected++;
   }

   // 6. put PacMan back again to playfield
   playfield[mypacman.position.y][mypacman.position.x] = '\2'; // number represents the pacman symbol used 

}
 

void show_playfield()
{
   for (int i = 0; i < H; i++)
   {
      for (int j = 0; j < W; j++)
      {
         printf("%c", playfield[i][j]); //prints the playfield using nested loops
      }
      printf("\n");
   }

   printf("Score: %d\n", mypacman.food_collected);// displays the score 
}

// Set cursor position in console
void set_cursor_position(int x, int y)
{
   //Initialize the coordinates
   COORD coord = { x, y };
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//Function to move cursor on console 

} // set_cursor_position


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);// accesses the cursor in cmd prompt
   CONSOLE_CURSOR_INFO info;// accesses its properties
   info.dwSize = 100;//sets cursor size 
   info.bVisible = FALSE;// makes the cursor invisible so that it doesn't interrupt the gaming experience
   SetConsoleCursorInfo(consoleHandle, &info);//updates the changes made to the properties of the cursor
}