#include "Arduboy.h"
#include "Robots.h"



void VerticalTransition()
{
  for (int i = 0; i < 64; i+=2)
  {
    ab.fillRect(0, 0, 128, i, 0x00);
    delay(20);
    ab.display();
  }
}

void ShowInfos()
{
  ab.clear();

  ab.setTextSize(2);
  ab.setCursor(30, 16);
  ab.print("ROBOTS");
  
  ab.setTextSize(1);
  ab.setCursor(12, 32);
  ab.print("Developped by Noth");
  ab.display();

  if (millis() - settings.menuTrigger > MENU_TRIGGER_DELAY)
  {
    if (ab.pressed(A_BUTTON) || ab.pressed(B_BUTTON))
    {
      gameState = GameState_Menu;
      settings.menuTrigger = millis();
      VerticalTransition();
    }
  }
}

void ShowMenu()
{
  int y;
  ab.clear();
  ab.setCursor(10, 5);
  ab.setTextSize(2);
  ab.print("ROBOTS");
  
  ab.setTextSize(1);

  y = 15;


  //New game
  y += 10;
  ab.setCursor(20, y);
  ab.print("New Game");
  if (settings.menuIdx == 0)
    ab.fillRect(14, y+2, 4, 4, 0xCC);


  // Sound
  y += 10;
  ab.setCursor(20, y);
  if (settings.sound)
    ab.print("Sound on");
  else
    ab.print("Sound off");
  if (settings.menuIdx == 1)
    ab.fillRect(14, y+2, 4, 4, 0xCC);
    
  //Infos  
  y += 10;
  ab.setCursor(20, y);
  ab.print("Infos");
  if (settings.menuIdx == 2)
    ab.fillRect(14, y+2, 4, 4, 0xCC);

  // Handle keys
  if (millis() - settings.menuTrigger > MENU_TRIGGER_DELAY)
  {
    if (ab.pressed(UP_BUTTON) && (settings.menuIdx != 0))
    {
      settings.menuIdx--;
      settings.menuTrigger = millis();
    }
    if (ab.pressed(DOWN_BUTTON) && (settings.menuIdx != 2))
    {
      settings.menuIdx++;
      settings.menuTrigger = millis();
    }
    if (ab.pressed(A_BUTTON))
    {
      switch (settings.menuIdx)
      {
        case 0:
          gameState = GameState_Playing;
          VerticalTransition();
        break;
        case 1:
          settings.sound = !settings.sound;
         break;
        case 2:
          gameState = GameState_Infos;
          VerticalTransition();
        break;
      }
      settings.menuTrigger = millis();
    }
  }
/*
  ab.clear();
  ab.drawSlowXYBitmap(50, 50, arrow, 5, 5, 1);
  ab.drawBitmap(8, 8, arrow2, 5, 5, 1);
*/
  ab.display();
}

void Splash()
{
  for(int i = -60; i < 140; i = i + 2)
  {
    ab.clear();
    ab.setCursor(i, 20);
    ab.setTextSize(2);
    ab.print("ROBOTS");
    ab.display();
    delay(50);
  }
  delay(200);
  ab.clear();
  ab.display();
  gameState = GameState_Menu;
}

void setup() 
{
  ab.beginNoLogo();
  ab.setFrameRate(30);
  settings.menuIdx = 0;
  settings.menuTrigger = 0;
  settings.sound = false;
}

void loop() 
{
  if (!(ab.nextFrame()))
    return;

   // Refresh state
  switch (gameState)
  {
    case GameState_SplashScreen:
      Splash();
    break;
    case GameState_Menu:
      ShowMenu();
    break;
    case GameState_Playing:

    break;
    break;
    case GameState_Infos:
      ShowInfos();
    break;
   }

  if (ab.pressed(A_BUTTON) && ab.pressed(B_BUTTON))
    gameState = GameState_SplashScreen;
}
