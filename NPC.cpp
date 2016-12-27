#include "NPC.h"
#include "Collisions.h"

#include "Collisions.h"

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


void SpawnRobotBullet(Bullet * bullets, byte startX, byte startY, byte playerX, byte playerY)
{
  if (rand()%50 != 0)
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

      //Jump first shot iteration (otherwise it would instant collide with shooter)
      bullets[b].position.x += 5*bullets[b].direction.x;
      bullets[b].position.y += 5*bullets[b].direction.y;
      
      bullets[b].speed = 3;
      bullets[b].speedIdx = 0;
      return;
    }
  }
}


void PrintNPCs(Game_t * game)
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
void UpdateNPCs(Game_t * game)
{
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

}
