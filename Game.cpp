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
PROGMEM unsigned const  char player[] = { 
                   0xAA, 0x11, 
                   0x11, 0xAA,
                   0xAA, 0x11, 
                   0x11, 0xAA,
                   0xAA, 0x11, 
                   0x11, 0xAA,
                   0xAA, 0x11, 
                   0x11, 0xAA  };

void SwitchLevel(Game_t * game, byte level)
{
  game->level.currentLevel = level;
  game->level.playerX = (XRIGHT - XLEFT)/2 + XLEFT; // center X
  game->level.playerY = YBOTTOM - 10;
}

void PrintPlayer(Game_t * game)
{
  // head
  game->ab.drawPixel(game->level.playerX + 2, game->level.playerY, 1);
  game->ab.drawPixel(game->level.playerX + 3, game->level.playerY, 1);
  game->ab.drawPixel(game->level.playerX + 2, game->level.playerY + 1, 1);
  game->ab.drawPixel(game->level.playerX + 3, game->level.playerY + 1, 1);

  // shoulders
  game->ab.drawLine(game->level.playerX + 1, game->level.playerY + 3, 
                    game->level.playerX + 5, game->level.playerY + 3,
                    1);

  //left arm
  game->ab.drawPixel(game->level.playerX, game->level.playerY + 4, 1);
  game->ab.drawPixel(game->level.playerX, game->level.playerY + 5, 1);
  
  //right arm
  game->ab.drawPixel(game->level.playerX + 5, game->level.playerY + 4, 1);
  game->ab.drawPixel(game->level.playerX + 5, game->level.playerY + 5, 1);

  // Belly
  game->ab.drawLine(game->level.playerX + 2, game->level.playerY + 4, 
                    game->level.playerX + 2, game->level.playerY + 8,
                    1);
  game->ab.drawLine(game->level.playerX + 3, game->level.playerY + 4, 
                    game->level.playerX + 3, game->level.playerY + 8,
                    1);                      

  // Feets
  game->ab.drawLine(game->level.playerX + 2, game->level.playerY + 9, 
                    game->level.playerX + 5, game->level.playerY + 9,
                    1);          
}

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

  // Player
  PrintPlayer(game);

  game->ab.display();

  // Controls
  if (millis() - game->settings.menuTrigger > PLAYER_TRIGGER_DELAY)
  {
    if (game->ab.pressed(UP_BUTTON))
    {
      game->level.playerY--;
      game->settings.menuTrigger = millis();
    }
    else if (game->ab.pressed(DOWN_BUTTON))
    {
      game->level.playerY++;
      game->settings.menuTrigger = millis();
    }
    else if (game->ab.pressed(LEFT_BUTTON))
    {
      game->level.playerX--;
      game->settings.menuTrigger = millis();
    }
        else if (game->ab.pressed(RIGHT_BUTTON))
    {
      game->level.playerX++;
      game->settings.menuTrigger = millis();
    }
   }
    
}

