//
//  ModelFactory.h
//
//	Purpuse:	this class takes care of creating Model instances to client class.
//
//	Type:		Singleton
//
//	See main.cpp file header for credits
//

#ifndef __HelicopterProject__ModelFactory_h__
#define __HelicopterProject__ModelFactory_h__


#include "Helicopter.h"
#include "Terrain.h"
#include "Sky.h"
#include "Obstacle.h"


class Game;

// enum for model children
enum class ModelsTypes {
	HELICOPTER,
	TERRAIN,
	SKY,
	EIFFEL_TOUR,
	LARGE_RESIDENTIAL_HIGHRISE,
	LARGE_RESIDENTIAL_HIGHRISE_ORANGE,
	TARGET
};


class ModelFactory {
public:
	ModelFactory(Game *game);
	Model* create(ModelsTypes modelType);
	
private:
	Game *game;
};

#include "Game.h"
#endif


