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
#define PLAYER_TRIGGER_DELAY 20

Segment level1[] = { {{XLEFT, YTOP},  {XRIGHT, YTOP}},   // top wall
                     {{XLEFT, YBOTTOM}, {XRIGHT, YBOTTOM}}, //bottom wall
                     {{XLEFT, YTOP}, {XLEFT, YBOTTOM}}, //left wall
                     {{XRIGHT, YTOP}, {XRIGHT, 16}}, // right wall
                     
                     {{XRIGHT, 28}, {XRIGHT, YBOTTOM}}, // right wall part 2
                     
                     };
char tmp[16];
PROGMEM unsigned const  char player1BMP[] = { // 6 x 10
                   0b00110000,
                   0b00110000,
                   0b00000000,
                   0b01111000,
                   0b10110100,
                   0b10110100,
                   0b00110000,
                   0b00110000,
                   0b00110000,
                   0b00111000
                   };
PROGMEM unsigned const  char player2BMP[] = { // 6 x 10
                   0b00110000,
                   0b00110000,
                   0b00000000,
                   0b01111000,
                   0b10110100,
                   0b10110100,
                   0b00110000,
                   0b00110000,
                   0b01010000,
                   0b01101000
                   };
PROGMEM unsigned const  char player3BMP[] = { // 6 x 10
                   0b00110000,
                   0b00110000,
                   0b00000000,
                   0b01111000,
                   0b10110100,
                   0b10110100,
                   0b00110000,
                   0b00110000,
                   0b01010000,
                   0b01101100
                   };
                   
void SwitchLevel(Game_t * game, byte level)
{
  game->level.currentLevel = level;
  game->level.playerX = (XRIGHT - XLEFT)/2 + XLEFT; // center X
  game->level.playerY = YBOTTOM - 10;
  game->level.playerFrame = 0;
}

void PrintPlayer(Game_t * game, bool moved)
{
  if (moved)
  {
    game->level.playerFrame ++;
    game->level.playerFrame = game->level.playerFrame%3;
  }
  
  if (game->level.playerFrame == 0)
    game->ab.drawSlowXYBitmap(game->level.playerX, game->level.playerY, player1BMP, 6, 10, 1);
  else if (game->level.playerFrame == 1)
    game->ab.drawSlowXYBitmap(game->level.playerX, game->level.playerY, player2BMP, 6, 10, 1);
  else
    game->ab.drawSlowXYBitmap(game->level.playerX, game->level.playerY, player3BMP, 6, 10, 1);
}

void PrintLevel(Game_t * game)
{
  bool moved = false;
  // Controls
  if (millis() - game->settings.menuTrigger > PLAYER_TRIGGER_DELAY)
  {
    if (game->ab.pressed(UP_BUTTON))
    {
      game->level.playerY--;
      moved = true;
    }
    else if (game->ab.pressed(DOWN_BUTTON))
    {
      game->level.playerY++;
      moved = true;
    }
    else if (game->ab.pressed(LEFT_BUTTON))
    {
      game->level.playerX--;
      moved = true;
    }
    else if (game->ab.pressed(RIGHT_BUTTON))
    {
      game->level.playerX++;
      moved = true;
    }
    if (moved)
      game->settings.menuTrigger = millis();    
  }
   
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

  // Player
  PrintPlayer(game, moved);

  game->ab.display();

    
}

