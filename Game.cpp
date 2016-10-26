#include "Arduboy.h"
#include "Robots.h"
#include "Game.h"


#define XLEFT 8
#define XRIGHT 120
#define YTOP 0
#define YBOTTOM 52
#define PLAYER_TRIGGER_DELAY 20
Segment level1[] = { {{XLEFT, YTOP},  {XRIGHT, YTOP}},   // top wall
                     {{XLEFT, YBOTTOM}, {XRIGHT, YBOTTOM}}, //bottom wall
                     {{XLEFT, YTOP}, {XLEFT, YBOTTOM}}, //left wall
                     {{XRIGHT, YTOP}, {XRIGHT, 16}}, // right wall
                     {{XRIGHT, 28}, {XRIGHT, YBOTTOM}}, // right wall part 2
                     };

Robot  robots1[] = {{{20, 20}, 1},
                    {{30, 44}, 1}};
                 
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


PROGMEM unsigned const char robot1BMP[] = { // 8 x 8
  0b00111100,
  0b01100110,
  0b11111111,
  0b10111101,
  0b10111101,
  0b00100100,
  0b00100100,
  0b01100110
};

PROGMEM unsigned const char robot2BMP[] = { // 8 x 8
  0b00111100,
  0b01110110,
  0b11111111,
  0b10111101,
  0b10111101,
  0b00100100,
  0b00100100,
  0b01100110
};

PROGMEM unsigned const char robot3BMP[] = { // 8 x 8
  0b00111100,
  0b01111110,
  0b11111111,
  0b10111101,
  0b10111101,
  0b00100100,
  0b00100100,
  0b01100110
};
/// Reset level struct to defaults
void SwitchLevel(Game_t * game, byte level)
{
  game->level.currentLevel = level;
  game->level.playerPosition.x = (XRIGHT - XLEFT)/2 + XLEFT; // center X
  game->level.playerPosition.y = YBOTTOM - 10;
  game->level.playerFrame = 0;
  switch (level)
  {
    case 1:
      game->level.map = level1;
      game->level.mapSize = sizeof(level1) / sizeof(Segment);
      
      game->level.robots = robots1;
      game->level.robotsCount = sizeof(robots1) / sizeof(Robot);
      game->level.robotsMovement = 60;
    break;
    default:
      game->level.map = NULL;   
      game->level.mapSize = 0;
      game->level.robotsMovement = 0;
  }
  memset(game->level.bullets, 0x00, sizeof(Bullet) * MAX_BULLETS);

/*
  game->level.bullets[0].position.x = XLEFT + 1;
  game->level.bullets[0].position.y = YTOP + 1;
  game->level.bullets[0].direction.x = 1;
  game->level.bullets[0].direction.y = 1;
  game->level.bullets[0].speed = 2;
  game->level.bullets[0].speedIdx = 0;
*/
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
    game->ab.drawSlowXYBitmap(game->level.playerPosition.x, game->level.playerPosition.y, player1BMP, 6, 10, 1);
  else if (game->level.playerFrame == 1)
    game->ab.drawSlowXYBitmap(game->level.playerPosition.x, game->level.playerPosition.y, player2BMP, 6, 10, 1);
  else
    game->ab.drawSlowXYBitmap(game->level.playerPosition.x, game->level.playerPosition.y, player3BMP, 6, 10, 1);
}

void PrintRobots(Game_t * game)
{
  for (byte i = 0; i < game->level.robotsCount; i++)
  {
    if (game->level.robots[i].state != 0)
    {
      if (game->level.robots[i].state == 1)
        game->ab.drawSlowXYBitmap(game->level.robots[i].position.x, game->level.robots[i].position.y, robot1BMP, 8, 8, 1);
      else if (game->level.robots[i].state == 1)
        game->ab.drawSlowXYBitmap(game->level.robots[i].position.x, game->level.robots[i].position.y, robot2BMP, 8, 8, 1);
      else
        game->ab.drawSlowXYBitmap(game->level.robots[i].position.x, game->level.robots[i].position.y, robot3BMP, 8, 8, 1);
      game->level.robots[i].state ++;
      game->level.robots[i].state = game->level.robots[i].state%3 + 1;
    }
  }
}

bool CollisionDetectionPlayerMap(Game_t * game)
{
  return false;
}

void UpdateBullets(Game_t * game)
{
  for (byte b = 0; b < MAX_BULLETS; b++)
  {
    if (game->level.bullets[b].direction.x || game->level.bullets[b].direction.y)
    {
      game->level.bullets[b].speedIdx++;
      //Time to update bullet position ?
      if (game->level.bullets[b].speed && (game->level.bullets[b].speedIdx == game->level.bullets[b].speed))
      {
        game->level.bullets[b].position.x += game->level.bullets[b].direction.x;
        game->level.bullets[b].position.y += game->level.bullets[b].direction.y;
        game->level.bullets[b].speedIdx = 0;
      }

      if ((game->level.bullets[b].position.x >= XRIGHT) ||
          (game->level.bullets[b].position.x <= XLEFT) ||
          (game->level.bullets[b].position.y >= YBOTTOM) ||
          (game->level.bullets[b].position.y <= YTOP))
      {
        memset(&game->level.bullets[b], 0x00, sizeof(Bullet));
        game->level.bullets[b].direction.x = 0;
        game->level.bullets[b].direction.y = 0;
      }
      else
      {
        game->ab.drawLine(game->level.bullets[b].position.x, game->level.bullets[b].position.y,
                          game->level.bullets[b].position.x + 2*game->level.bullets[b].direction.x, game->level.bullets[b].position.y + 2*game->level.bullets[b].direction.y, 
                          1);
      }
    }
  }
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
  }

  // Move robots
  for (byte r = 0; r < game->level.robotsCount; r++)
  {
    if (rand()%game->level.robotsMovement == 0)
    {
      if (game->level.robots[r].position.x < game->level.playerPosition.x)
        game->level.robots[r].position.x++;
      else
        game->level.robots[r].position.x--;

      if (game->level.robots[r].position.y < game->level.playerPosition.y)
        game->level.robots[r].position.y++;
      else
        game->level.robots[r].position.y--;      
    }

    if (rand()%10 == 0)
    {
      for (int b = 0; b < MAX_BULLETS; b++)
      {
      
        //free firing slot
        if (!game->level.bullets[b].direction.x && !game->level.bullets[b].direction.y)
        {
          game->level.bullets[b].position.x = game->level.robots[r].position.x;
          game->level.bullets[b].position.y = game->level.robots[r].position.y;

          game->level.bullets[b].direction.x = 0;
          game->level.bullets[b].direction.y = 0;
          char xdist = game->level.playerPosition.x - game->level.robots[r].position.x;
          char ydist = game->level.playerPosition.y - game->level.robots[r].position.y;

          game->level.bullets[b].direction.x = 0;
          game->level.bullets[b].direction.y = 0;
          if ((xdist > 0) && (abs(xdist) > abs(2*ydist))) // really on the right side
            game->level.bullets[b].direction.x = 1;
          else if ((xdist < 0) && (abs(xdist) > abs(2*ydist))) // really on the left side
            game->level.bullets[b].direction.x = -1;
          else if ((ydist > 0) && (abs(ydist) > abs(2*xdist))) // really on the bottom side
            game->level.bullets[b].direction.y = 1;
          else if ((ydist < 0) && (abs(ydist) > abs(2*xdist))) // really on the top side
            game->level.bullets[b].direction.y = -1;
          else
          {                                                     //diag shots
            if (xdist > 0)
              game->level.bullets[b].direction.x = 1;
             else
              game->level.bullets[b].direction.x = -1;
             if (ydist > 0)
              game->level.bullets[b].direction.y = 1;
             else
              game->level.bullets[b].direction.y = -1;
          }
           
          game->level.bullets[b].speed = 3;
          game->level.bullets[b].speedIdx = 0;
          break;
        }
      }
    }
  }
  
  //Detect collisions
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

  //Robots
  PrintRobots(game);

    //Bullets
  UpdateBullets(game);
  
  game->ab.display();
}

