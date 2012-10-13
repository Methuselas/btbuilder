/*-------------------------------------------------------------------------*\
  <psuedo3dmap.C> -- Psuedo3DMap implementation file

  Date      Programmer  Description
  10/08/12  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include "psuedo3dmap.h"

Psuedo3DMap *Psuedo3DMap::map = 0;

Psuedo3DMap::Psuedo3DMap()
{
 if (0 == map)
 {
  map = this;
 }
}

int Psuedo3DMap::getFacing()
{
 return facing;
}

int Psuedo3DMap::getX()
{
 return xPos;
}

int Psuedo3DMap::getY()
{
 return yPos;
}

Psuedo3DMap *Psuedo3DMap::getMap()
{
 return map;
}
