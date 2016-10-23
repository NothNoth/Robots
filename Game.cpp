#include "Arduboy.h"
#include "Robots.h"
#include "Game.h"



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


/// Reset level struct to defaults
void SwitchLevel(Game_t * game, byte level)
{
  game->level.currentLevel = level;
  game->level.playerX = (XRIGHT - XLEFT)/2 + XLEFT; // center X
  game->level.playerY = YBOTTOM - 10;
  game->level.playerFrame = 0;
  switch (level)
  {
    case 1:
      game->level.map = level1;
      game->level.mapSize = sizeof(level1) / sizeof(Segment);
    break;
    default:
      game->level.map = NULL;   
      game->level.mapSize = 0;
  }
}


// Print player character bitmap
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

bool CollisionDetectionPlayerMap(Game_t * game)
{
  return false;
}

// Refresh level
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

  if (CollisionDetectionPlayerMap(game))
  {
    game->gameState = GameState_Menu; 
    return;
  }
  game->ab.clear();
  
  //Draw walls
  for (byte l = 0; l < game->level.mapSize; l++)
    game->ab.drawLine(game->level.map[l].a.x, game->level.map[l].a.y, game->level.map[l].b.x, game->level.map[l].b.y, 1);

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

