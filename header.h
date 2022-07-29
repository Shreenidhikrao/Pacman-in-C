
void initialize();
void user_input();
void move_figures();
void show_playfield();
void set_cursor_position(int x, int y);
void hidecursor();



struct coord
{
   int x;
   int y;
};

struct PacMan {
   struct coord position;
   int vx;
   int vy;
   int food_collected;
};


