#include "Arduboy.h"
#include "Robots.h"
#include "Game.h"
#include "Collisions.h"

#define XLEFT 8
#define XRIGHT 120
#define YTOP 0
#define YBOTTOM 52
#define PLAYER_TRIGGER_DELAY 20
Segment level1[] = { {{XLEFT, YTOP},  {XRIGHT, YTOP}},   // top wall
                     {{XLEFT, YBOTTOM}, {XRIGHT, YBOTTOM}}, //bottom wall
                     {{XLEFT, YTOP}, {XLEFT, YBOTTOM}}, //left wall
                     {{XRIGHT, YTOP}, {XRIGHT, 12}}, // right wall
                     {{XRIGHT, 34}, {XRIGHT, YBOTTOM}}, // right wall part 2
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

void PlayerDead(Game_t * game, void * userData);
void RobotDead(Game_t * game, void * userData);

/// Reset level struct to defaults
void SwitchLevel(Game_t * game, byte level)
{
  game->level.currentLevel = level;
  game->level.playerPosition.x = (XRIGHT - XLEFT)/2 + XLEFT; // center X
  game->level.playerPosition.y = YBOTTOM - 15;
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

void SpawnRobotBullet(Bullet * bullets, byte startX, byte startY, byte playerX, byte playerY)
{
  if (rand()%150 != 0)
    return;

  for (int b = 0; b < MAX_BULLETS; b++)
  {        
    //free firing slot
    if (!bullets[b].direction.x && !bullets[b].direction.y)
    {
      bullets[b].position.x = startX;
      bullets[b].position.y = startY;

      bullets[b].direction.x = 0;
      bullets[b].direction.y = 0;
      char xdist = playerX - startX;
      char ydist = playerY - startY;

      bullets[b].direction.x = 0;
      bullets[b].direction.y = 0;
      if ((xdist > 0) && (abs(xdist) > abs(2*ydist))) // really on the right side
        bullets[b].direction.x = 1;
      else if ((xdist < 0) && (abs(xdist) > abs(2*ydist))) // really on the left side
        bullets[b].direction.x = -1;
      else if ((ydist > 0) && (abs(ydist) > abs(2*xdist))) // really on the bottom side
        bullets[b].direction.y = 1;
      else if ((ydist < 0) && (abs(ydist) > abs(2*xdist))) // really on the top side
        bullets[b].direction.y = -1;
      else
      {                                                     //diag shots
        if (xdist > 0)
          bullets[b].direction.x = 1;
         else
          bullets[b].direction.x = -1;
         if (ydist > 0)
          bullets[b].direction.y = 1;
         else
          bullets[b].direction.y = -1;
      }
       
      bullets[b].speed = 3;
      bullets[b].speedIdx = 0;
      return;
    }
  }
}

// Refresh level
void PrintLevel(Game_t * game)
{
  bool moved = false;

  CollisionsClear();

  // Player movement
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

    if (CollisionsAdd(game, game->level.playerPosition.x, game->level.playerPosition.y, 6, 10, PlayerDead, NULL))
      return;
  }

  
  // Move robots
  for (byte r = 0; r < game->level.robotsCount; r++)
  {
    //Ignore dead robots
    if (game->level.robots[r].state == 0)
      continue;

    //Move robot
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

    //Detect collisions
    if (CollisionsAdd(game, game->level.robots[r].position.x, game->level.robots[r].position.y, 8, 8, RobotDead, (void *)&game->level.robots[r]))
    {
      continue;
    }

    //Eventually shoot
    SpawnRobotBullet(game->level.bullets, game->level.robots[r].position.x, game->level.robots[r].position.y, game->level.playerPosition.x, game->level.playerPosition.y);
  }


  game->ab.clear();
  
  //Draw walls
  for (byte l = 0; l < game->level.mapSize; l++)
  {
    byte x, y, w, h;
    
    game->ab.drawLine(game->level.map[l].a.x, game->level.map[l].a.y, game->level.map[l].b.x, game->level.map[l].b.y, 1);
    if (game->level.map[l].a.x == game->level.map[l].b.x)
    {
      //Vertical wall
      x = game->level.map[l].a.x;
      y = min(game->level.map[l].a.y, game->level.map[l].b.y);
      h = abs(game->level.map[l].a.y - game->level.map[l].b.y);
      w = 1;
    }
    else
    {
      //Horizontal wall
      x = min(game->level.map[l].a.x, game->level.map[l].b.x);
      y = game->level.map[l].a.y;
      h = 1;
      w = abs(game->level.map[l].a.x - game->level.map[l].b.x);
    }
    if (CollisionsAdd(game, x, y, w, h, NULL, NULL))
    {
      //game->gameState = GameState_Menu; 

    }
  }
  
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


void PlayerDead(Game_t * game, void * userData)
{
  game->gameState = GameState_Menu; 
}

void RobotDead(Game_t * game, void * userData)
{
  Robot * r = (Robot *) userData;
  r->state = 0;
  game->settings.score += 10;
  
  for (byte r = 0; r < game->level.robotsCount; r++)
  {
    if (game->level.robots[r].state != 0)
      return;
  }

  //All robots dead!
  game->gameState = GameState_Menu; 

}
