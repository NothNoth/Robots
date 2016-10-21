#include "Arduboy.h"
#include "Robots.h"
#include "Game.h"

Game_t game;

PROGMEM unsigned const  char bitmap[] = { 
                   0xAA, 0x11, 
                   0x11, 0xAA,
                   0xAA, 0x11, 
                   0x11, 0xAA,
                   0xAA, 0x11, 
                   0x11, 0xAA,
                   0xAA, 0x11, 
                   0x11, 0xAA  };
                   

PROGMEM const unsigned char arrow[] =
{
  0x20,
  0x10,
  0xF8,
  0x10,
  0x20,
};

PROGMEM const unsigned char arrow2[] =
{
  0x20,
  0x10,
  0xF8,
  0x10,
  0x20,
};


void setup() 
{
  game.ab.beginNoLogo();
  game.ab.setFrameRate(30);

  game.gameState = GameState_Menu;
  game.settings.menuIdx = 0;
  game.settings.menuTrigger = 0;
  game.settings.sound = false;
  game.settings.level = 1;
  game.settings.score = 0;
}

void loop() 
{
  if (!(game.ab.nextFrame()))
    return;

   // Refresh state
  switch (game.gameState)
  {
    case GameState_SplashScreen:
      Splash(&game);
    break;
    case GameState_Menu:
      ShowMenu(&game);
    break;
    case GameState_Playing:
      PrintLevel(&game);
    break;
    break;
    case GameState_Infos:
      ShowInfos(&game);
    break;
   }

  if (game.ab.pressed(A_BUTTON) && game.ab.pressed(B_BUTTON))
    game.gameState = GameState_SplashScreen;
}
