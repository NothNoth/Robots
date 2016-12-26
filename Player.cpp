#include "Player.h"
#include "Collisions.h"

#define PLAYER_TRIGGER_DELAY 20


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


// Print player character bitmap
void PrintPlayer(Game_t * game, bool moved)
{
  if (moved)
  {
    game->level.playerFrame ++;
    game->level.playerFrame = game->level.playerFrame%3;
  }
  
  if (game->level.playerFrame == 0)
    game->ab.drawSlowXYBitmap(game->level.playerPosition.x, game->level.playerPosition.y, player1BMP, 6, 10, 1);
  else if (game->level.playerFrame == 1)
    game->ab.drawSlowXYBitmap(game->level.playerPosition.x, game->level.playerPosition.y, player2BMP, 6, 10, 1);
  else
    game->ab.drawSlowXYBitmap(game->level.playerPosition.x, game->level.playerPosition.y, player3BMP, 6, 10, 1);
}

bool UpdatePlayer(Game_t * game)
{
  bool moved = false;

  // Player movement
  if (millis() - game->settings.menuTrigger <= PLAYER_TRIGGER_DELAY) return;
  
  if (game->ab.pressed(UP_BUTTON))
  {
    game->level.playerPosition.y--;
    moved = true;
  }
  if (game->ab.pressed(DOWN_BUTTON))
  {
    game->level.playerPosition.y++;
    moved = true;
  }
  if (game->ab.pressed(LEFT_BUTTON))
  {
    game->level.playerPosition.x--;
    moved = true;
  }
  if (game->ab.pressed(RIGHT_BUTTON))
  {
    game->level.playerPosition.x++;
    moved = true;
  }
  if (moved)
    game->settings.menuTrigger = millis();    

  CollisionsAdd(game, game->level.playerPosition.x, game->level.playerPosition.y, 6, 10, PlayerDead, NULL);
  return moved;
}


void PlayerDead(Game_t * game, void * userData)
{
  game->gameState = GameState_Menu; 
}


