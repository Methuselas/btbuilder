#ifndef __PSUEDO3D_H
#define __PSUEDO3D_H
/*-------------------------------------------------------------------------*\
  <psuedo3d.h> -- Psuedo3D header file

  Date      Programmer  Description
  01/15/07  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include "psuedo3dconfig.h"
#include "psuedo3dmap.h"
#include <SDL.h>

class Psuedo3D
{
 public:
  Psuedo3D(int xM, int yM);
  ~Psuedo3D();

  void clear();
  void draw(Psuedo3DMap *map, int x, int y, int direction);
  SDL_Surface *getDisplay() { return display; }
  SDL_Surface *getMapWall(Psuedo3DMap *map, int x, int y, int direction);
  SDL_Surface *getMapSpecial() { return mapSpecial; }
  SDL_Surface *getMapUnknown() { return mapUnknown; }
  void setConfig(Psuedo3DConfig *configNew);
  void setMultiplier(int xM, int yM) { xMult = xM; yMult = yM; }

 protected:
  void drawEdge(Psuedo3DMap *map, int x, int y, int direction, int image, int radius);
  void drawFront(Psuedo3DMap *map, int x, int y, int direction, int image, int radius);
  SDL_Surface *loadImage(const char *file);

 public:
  typedef SDL_Surface *SDL_Surface_ptr;
  typedef SDL_Surface **SDL_Surface_ary;
  Psuedo3DConfig *config;
  int xMult, yMult;
  SDL_Surface *display;
  SDL_Surface *background;
  SDL_Surface ***walls;
  SDL_Surface ***mapWalls;
  SDL_Surface *mapSpecial;
  SDL_Surface *mapUnknown;

  static int changeXY[4][2];
};

#endif
