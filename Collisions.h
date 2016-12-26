#ifndef _COLLISIONS_H_
#define _COLLISIONS_H_
#include "Arduboy.h"

#include "Robots.h"

typedef void (*collisionCbPtr)(Game_t *, void *);


typedef struct
{
  byte x;
  byte y;
  byte w;
  byte h;
} Box;

typedef struct 
{
  Box box;
  collisionCbPtr cb;
  void * userData;
} CollisionItem;

//Cleanup collisions state
void CollisionsClear();

//Add collision item
// On collision, returns true
// Colliding item will be notified through collisionCb
bool CollisionsAdd(Game_t * game, byte x, byte y, byte w, byte h, collisionCbPtr cb, void *d);


#endif
