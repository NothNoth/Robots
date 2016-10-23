#include "Arduboy.h"
#include "Robots.h"
#include "Utils.h"

void ShowInfos(Game_t * game)
{
  game->ab.clear();

  game->ab.setTextSize(2);
  game->ab.setCursor(30, 16);
  game->ab.print("ROBOTS");
  
  game->ab.setTextSize(1);
  game->ab.setCursor(12, 32);
  game->ab.print("Developped by Noth");
  game->ab.display();

  if (millis() - game->settings.menuTrigger > MENU_TRIGGER_DELAY)
  {
    if (game->ab.pressed(A_BUTTON) || game->ab.pressed(B_BUTTON))
    {
      game->gameState = GameState_Menu;
      game->settings.menuTrigger = millis();
      VerticalTransition(game);
    }
  }
}

void ShowMenu(Game_t * game)
{
  int y;
  game->ab.clear();
  game->ab.setCursor(10, 5);
  game->ab.setTextSize(2);
  game->ab.print("ROBOTS");
  game->ab.setTextSize(1);

  y = 15;


  //New game
  y += 10;
  game->ab.setCursor(20, y);
  game->ab.print("New Game");
  if (game->settings.menuIdx == 0)
    game->ab.fillRect(14, y+2, 4, 4, 0xCC);


  // Sound
  y += 10;
  game->ab.setCursor(20, y);
  if (game->settings.sound)
    game->ab.print("Sound on");
  else
    game->ab.print("Sound off");
  if (game->settings.menuIdx == 1)
    game->ab.fillRect(14, y+2, 4, 4, 0xCC);
    
  //Infos  
  y += 10;
  game->ab.setCursor(20, y);
  game->ab.print("Infos");
  if (game->settings.menuIdx == 2)
    game->ab.fillRect(14, y+2, 4, 4, 0xCC);

  // Handle keys
  if (millis() - game->settings.menuTrigger > MENU_TRIGGER_DELAY)
  {
    if (game->ab.pressed(UP_BUTTON) && (game->settings.menuIdx != 0))
    {
      game->settings.menuIdx--;
      game->settings.menuTrigger = millis();
    }
    if (game->ab.pressed(DOWN_BUTTON) && (game->settings.menuIdx != 2))
    {
      game->settings.menuIdx++;
      game->settings.menuTrigger = millis();
    }
    if (game->ab.pressed(A_BUTTON))
    {
      switch (game->settings.menuIdx)
      {
        case 0:
          game->gameState = GameState_Playing;
          VerticalTransition(game);
        break;
        case 1:
          game->settings.sound = !game->settings.sound;
         break;
        case 2:
          game->gameState = GameState_Infos;
          VerticalTransition(game);
        break;
      }
      game->settings.menuTrigger = millis();
    }
  }
/*
  game->ab.clear();
  game->ab.drawSlowXYBitmap(50, 50, arrow, 5, 5, 1);
  game->ab.drawBitmap(8, 8, arrow2, 5, 5, 1);
*/
  game->ab.display();
}

void Splash(Game_t * game)
{
  for(int i = -60; i < 140; i = i + 2)
  {
    game->ab.clear();
    game->ab.setCursor(i, 20);
    game->ab.setTextSize(2);
    game->ab.print("ROBOTS");
    game->ab.display();
    delay(50);
  }
  delay(200);
  game->ab.clear();
  game->ab.display();
  game->gameState = GameState_Menu;
}


void VerticalTransition(Game_t * game)
{
  for (int i = 0; i < 64; i+=2)
  {
    game->ab.fillRect(0, 0, 128, i, 0x00);
    delay(20);
    game->ab.display();
  }
}
