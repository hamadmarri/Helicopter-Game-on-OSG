//
//  Sky.h
//
//	See main.cpp file header for credits
//
//  A sky calss to represent the sky in our sceen,
//	it has only one constuctor to set the position and call the model from a file.
//  A Sky class inhertitance from Model public.


#ifndef __HelicopterProject__Sky_h__
#define __HelicopterProject__Sky_h__

#include "Model.h"
// define Game class
class Game;
// public inheritance from Model class
class Sky : public Model {
public:
    Sky(Game *game);  // constructor
    ~Sky();           // deconstructor
};


#include "Game.h"
#endif
