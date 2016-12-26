#include "Collisions.h"

#define MAX_COLLISION_ITEMS 32
static CollisionItem items[MAX_COLLISION_ITEMS];
static int itemsCount = 0;

//Cleanup collisions state
void CollisionsClear()
{
  itemsCount = 0;
}


bool CollisionDetect(Box *a, Box *b)
{
  int X = a->x - b->x;
  int Y = a->y - b->y;
  int W = a->w + b->w;
  int H = a->h + b->h;
  return (abs(X) * 2 < (W)) &&
         (abs(Y) * 2 < (H));
}


//Add collision item
// On collision, returns true
// Colliding item will be notified through collisionCb
bool CollisionsAdd(Game_t * game, byte x, byte y, byte w, byte h, collisionCbPtr cb, void *d)
{
  if (itemsCount + 1 == MAX_COLLISION_ITEMS)
    return false;

  items[itemsCount].box.x = x;
  items[itemsCount].box.y = y;
  items[itemsCount].box.w = w;
  items[itemsCount].box.h = h;
  items[itemsCount].cb = cb;
  items[itemsCount].userData = d;
  itemsCount ++;

  for (int i = 0; i < itemsCount - 1; i++)
  {
    //Intersect boxes
    if (CollisionDetect(&items[itemsCount - 1].box, &items[i].box)) 
    {
      if (items[i].cb)
        items[i].cb(game, items[i].userData);
      if (cb)
        cb(game, d);
      return true;
    }
  }

  
  return false;
}



