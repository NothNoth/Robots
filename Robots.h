#ifndef ROBOTS_H_
#define ROBOTS_H_

#define MENU_TRIGGER_DELAY 200
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
} Settings;

struct Game_t
{
  Settings      settings;
  GameState     gameState;
  Arduboy *     ab;
};


void Splash(Game_t * game);
void ShowMenu(Game_t * game);
void ShowInfos(Game_t * game);
void VerticalTransition(Game_t * game);



#endif
