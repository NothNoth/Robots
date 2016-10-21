#include "Arduboy.h"
#include "Robots.h"


Arduboy ab;

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
  ab.beginNoLogo();
  ab.setFrameRate(30);

  game.ab = &ab;
  game.gameState = GameState_Menu;
  game.settings.menuIdx = 0;
  game.settings.menuTrigger = 0;
  game.settings.sound = false;
}

void loop() 
{
  if (!(ab.nextFrame()))
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

    break;
    break;
    case GameState_Infos:
      ShowInfos(&game);
    break;
   }

  if (ab.pressed(A_BUTTON) && ab.pressed(B_BUTTON))
    game.gameState = GameState_SplashScreen;
}
