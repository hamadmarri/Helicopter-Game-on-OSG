//
//  Terrain.h
//
//	See main.cpp file header for credits
//
//	The Terrain class, it has only one constructor to set the position
//	of our terrain and call a file "model" and set it to the scen in the helicopter game.
//  Terrain class inherits public from Model class.
//
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//

#ifndef __HelicopterProject__Terrain_h__
#define __HelicopterProject__Terrain_h__

#include "Model.h"
#include "WorldConstants.h"
// define Game class 
class Game;
// inheritance from Model public
class Terrain : public Model {
public:
    Terrain(Game *game); // constructor
    ~Terrain(); // adding deconstructor 
};

#include "Game.h"
#endif
