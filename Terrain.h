//
//  Terrain.h
//
//	See main.cpp file header for credits
//
//	The Terrain class, it has only one constructor to set the position
//	of our terrain and call a file "model" and set it to the scen in the helicopter game.
//


#ifndef __HelicopterProject__Terrain_h__
#define __HelicopterProject__Terrain_h__

#include "Model.h"
#include "WorldConstants.h"

class Terrain : public Model {
public:
    Terrain();
    ~Terrain(); // adding deconstructor 
};

#endif
