#include "Arduboy.h"
#include "Utils.h"
/*
PROGMEM unsigned const  char fontBMP[] = {0xE0, 0xFE, 0x3F, 0x07, 0xE0, 0x7F, 0xC7, 0x81, 
0xFC, 0x3C, 0x03, 0xE0, 0xFC, 0x3F, 0xE7, 0xF0, 
0x3F, 0xE0, 0x78, 0x0F, 0xE0, 0x1C, 0x03, 0xE0, 
0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x78, 
0x3E, 0x03, 0xC0, 0x3F, 0xC7, 0x81, 0xF8, 0x1C, 
0x03, 0xC0, 0x78, 0x0F, 0xE7, 0xF0, 0x0F, 0x80, 
0x38, 0x03, 0xE0, 0x1C, 0x03, 0x80, 0x3C, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xCE, 0x79, 0x3E, 0xF1, 
0xDF, 0x1F, 0xA7, 0x9F, 0xF1, 0xDF, 0xE7, 0x8E, 
0x31, 0xCF, 0xC3, 0xF3, 0xCF, 0x1F, 0xB9, 0xF1, 
0xE7, 0xFC, 0xFF, 0x1F, 0xBC, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x9F, 0x3F, 0x3F, 0xF9, 0xFF, 0x9F, 
0x27, 0x9F, 0xE3, 0xFF, 0xE7, 0x9F, 0x33, 0xE7, 
0xC3, 0xF3, 0xCF, 0x3F, 0xF9, 0xF9, 0xE7, 0xFC, 
0xFF, 0x3F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x9F, 0x3F, 0x3F, 0xF9, 0xFF, 0x1F, 0x67, 0x83, 
0xE7, 0xFF, 0xE7, 0x8E, 0x33, 0xE7, 0x99, 0xF3, 
0xCE, 0x7F, 0xF9, 0xFC, 0xE7, 0xFC, 0xFE, 0x7F, 
0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9F, 0x3F, 
0x3F, 0xF3, 0xF0, 0x7E, 0xE7, 0x81, 0xE4, 0x3F, 
0xC7, 0xE0, 0xF1, 0xC7, 0x99, 0xF0, 0x1E, 0x7F, 
0xF9, 0xFC, 0xE0, 0x1C, 0x06, 0x78, 0x3C, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x9F, 0x3F, 0x3F, 0xF3, 
0xF0, 0x3C, 0xE7, 0xB8, 0xE0, 0x1F, 0xCF, 0xC0, 
0x78, 0x07, 0x99, 0xF0, 0x1E, 0x7F, 0xF9, 0xFC, 
0xE0, 0x1C, 0x06, 0x78, 0x3C, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x9F, 0x3F, 0x3F, 0xE7, 0xFF, 0x1D, 
0xE7, 0xFC, 0xE3, 0x8F, 0xCF, 0x8E, 0x3C, 0x27, 
0x3C, 0xF3, 0xCE, 0x7F, 0xF9, 0xFC, 0xE7, 0xFC, 
0xFE, 0x7F, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x9F, 0x3F, 0x3F, 0xCF, 0xFF, 0x98, 0x01, 0xFC, 
0xE7, 0xCF, 0x8F, 0x9F, 0x3F, 0xE7, 0x00, 0xF3, 
0xE6, 0x7F, 0xF9, 0xFC, 0xE7, 0xFC, 0xFE, 0x7F, 
0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9F, 0x3F, 
0x3F, 0x9F, 0xFF, 0x98, 0x01, 0xFC, 0xE7, 0xCF, 
0x9F, 0x9F, 0x3F, 0xC6, 0x00, 0x73, 0xE7, 0x3F, 
0xF9, 0xF9, 0xE7, 0xFC, 0xFF, 0x3F, 0x3C, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0xCE, 0x7F, 0x3F, 0x3F, 
0xDF, 0x1F, 0xE7, 0x78, 0xF3, 0x8F, 0x9F, 0x8E, 
0x3B, 0x8E, 0x7E, 0x73, 0xC7, 0x1F, 0xB9, 0xF1, 
0xE7, 0xFC, 0xFF, 0x1F, 0x3C, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xC0, 0x78, 0x06, 0x01, 0xC0, 0x3F, 
0xE7, 0x01, 0xF0, 0x1F, 0x1F, 0xC0, 0x78, 0x1E, 
0x7E, 0x70, 0x0F, 0x80, 0x38, 0x03, 0xE0, 0x1C, 
0xFF, 0x80, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void PrintText(Game_t * game, byte x, byte y, unsigned char * text)
{
  game->ab.drawSlowXYBitmap(x, y, fontBMP, 432, 12, 1);
  return;
    
  unsigned char * c = text;
  while (*c)
  {
    if (((*c) >= '0') && ((*c) <= '9'))
    {
      byte fontX = (*c - '0') * 8;
      game->ab.drawSlowXYBitmap(x, y, fontBMP, fontX, 10, 1);
    }
    c++;
  }
}
*/
