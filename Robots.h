#ifndef ROBOTS_H_
#define ROBOTS_H_

#define MENU_TRIGGER_DELAY 200

typedef struct
{
  byte x;
  byte y;  
} Point;

typedef struct
{
  float x;
  float y;  
} Pointf;

typedef struct
{
  Point a;
  Point b;
} Segment;

typedef enum
{
  GameState_SplashScreen,
  GameState_Menu,
  GameState_Infos,
  GameState_Playing
} GameState;

typedef struct
{
  int menuIdx;
  unsigned long menuTrigger;
  bool sound;

  byte level;
  int  score;
} Settings;

typedef struct
{
  Point position;
  byte state; // 0: dead, 1-3 frames  
} Robot;


typedef struct
{
  Point position;
  Point direction;
  byte speedIdx; //current iteration
  byte speed; //update position evey speed iterations
} Bullet;

typedef struct
{
  byte currentLevel;
  Point playerPosition;
  byte playerFrame;

  Segment * map;
  byte mapSize;

  Robot * robots;
  byte robotsCount;
  byte robotsMovement; // rand()%robotMovement rate
  Bullet bullets[8];
} Level;

typedef struct
{
  Arduboy       ab;
  Settings      settings;
  GameState     gameState;
  Level         level;
} Game_t;


void Splash(Game_t * game);
void ShowMenu(Game_t * game);
void ShowInfos(Game_t * game);
void VerticalTransition(Game_t * game);



#endif
