#include "Arduboy.h"
#include "Robots.h"
#include "Game.h"

typedef struct
{
  byte x;
  byte y;  
} Point;

typedef struct
{
  Point a;
  Point b;
} Segment;

#define XLEFT 8
#define XRIGHT 120
#define YTOP 0
#define YBOTTOM 50

Segment level1[] = { {{XLEFT, YTOP},  {XRIGHT, YTOP}},   // top wall
                     {{XLEFT, YBOTTOM}, {XRIGHT, YBOTTOM}}, //bottom wall
                     {{XLEFT, YTOP}, {XLEFT, YBOTTOM}}, //left wall
                     {{XRIGHT, YTOP}, {XRIGHT, YBOTTOM}}, // right wall
                     
                     
                     }; //right wall
char tmp[16];
 
void PrintLevel(Game_t * game)
{
  game->ab.clear();
  
  //Draw walls
  byte count = sizeof(level1) / sizeof(Segment);
  for (byte l = 0; l < count; l++)
    game->ab.drawLine(level1[l].a.x, level1[l].a.y, level1[l].b.x, level1[l].b.y, 1);

  //Text
  game->ab.setTextSize(1);
  game->ab.setCursor(12, 56);
  sprintf(tmp, "Lvl %d", game->settings.level);
  game->ab.print(tmp);
  game->ab.print("  ");
  sprintf(tmp, "Score %d", game->settings.score);
  game->ab.print(tmp);
  game->ab.display();
}

