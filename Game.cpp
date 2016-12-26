#include "Arduboy.h"
#include "Robots.h"
#include "Game.h"
#include "Collisions.h"
#include "Player.h"
#include "NPC.h"

#define XLEFT 8
#define XRIGHT 120
#define YTOP 0
#define YBOTTOM 52
Segment level1[] = { {{XLEFT, YTOP},  {XRIGHT, YTOP}},   // top wall
                     {{XLEFT, YBOTTOM}, {XRIGHT, YBOTTOM}}, //bottom wall
                     {{XLEFT, YTOP}, {XLEFT, YBOTTOM}}, //left wall
                     {{XRIGHT, YTOP}, {XRIGHT, 12}}, // right wall
                     {{XRIGHT, 34}, {XRIGHT, YBOTTOM}}, // right wall part 2
                     };

Robot  robots1[] = {{{20, 20}, 1},
                    {{30, 44}, 1}};
                 
char tmp[16];




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
      game->level.robotsMovement = 180;
    break;
    default:
      game->level.map = NULL;   
      game->level.mapSize = 0;
      game->level.robotsMovement = 0;
  }
  memset(game->level.bullets, 0x00, sizeof(Bullet) * MAX_BULLETS);
}





void UpdateBullets(Game_t * game)
{
  for (byte b = 0; b < MAX_BULLETS; b++)
  {
    if (!game->level.bullets[b].direction.x || !game->level.bullets[b].direction.y)
      continue;
  
    game->level.bullets[b].speedIdx+= game->level.bullets[b].speed;
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
    CollisionsAdd(game, game->level.bullets[b].position.x, game->level.bullets[b].position.y, 1, 1, NULL, NULL);
  }
}

void PrintBottomLine(Game_t * game)
{
  //Text
  game->ab.setTextSize(1);
  game->ab.setCursor(12, 56);
  sprintf(tmp, "Lvl %d", game->settings.level);
  game->ab.print(tmp);
  game->ab.print("  ");
  sprintf(tmp, "Score %d", game->settings.score);
  game->ab.print(tmp);  
}

void PrintLevel(Game_t * game)
{
  //Draw walls
  for (byte l = 0; l < game->level.mapSize; l++)
  {
    int x, y, w, h;
    game->ab.drawLine(game->level.map[l].a.x, game->level.map[l].a.y, game->level.map[l].b.x, game->level.map[l].b.y, 1);

    //Setup collision box for wall
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
    
    CollisionsAdd(game, x, y, w, h, NULL, NULL);
  }
}

// Refresh level
void GameLoop(Game_t * game)
{
  CollisionsClear();
  game->ab.clear();
  
  bool playerMoved = UpdatePlayer(game);
  UpdateNPCs(game);
  UpdateBullets(game);

  PrintLevel(game);
  PrintBottomLine(game);
  PrintPlayer(game, playerMoved);
  PrintNPCs(game);


  
  game->ab.display();
}



