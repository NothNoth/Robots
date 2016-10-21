#ifndef ROBOTS_H_
#define ROBOTS_H_
#include "Arduboy.h"

#define MENU_TRIGGER_DELAY 200
typedef enum
{
  GameState_SplashScreen,
  GameState_Menu,
  GameState_Infos,
  GameState_Playing
} GameState;

struct _Settings
{
  int menuIdx;
  unsigned long menuTrigger;
  bool sound;
} settings;


Arduboy ab;
//GameState gameState = GameState_SplashScreen;
GameState gameState = GameState_Menu;


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

#endif
