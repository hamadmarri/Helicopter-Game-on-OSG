//
//  Obstacles.h
//
//	See main.cpp file header for credits
//
//	An Obstacle class, this class is to display some models in our sceene,
//	we are required to have at least three model. Thus, we have decided to
//	implement a class called obstacle to set these models easily. One more
//	thing here, this class can be used in the future if we decided to add some
//	more models , and it can be done quickly and easily. by just calling the consturctor.
//


#ifndef __HelicopterProject__Obstacle_h__
#define __HelicopterProject__Obstacle_h__


#include "Model.h"
#include "Collidable.h"

class Game;


// constructing the obstacle class
class Obstacle : public Model, public Collidable {
public:
    Obstacle(Game *game);
    Obstacle(Game *game, osg::Node* node);
    void set(osg::Node* node);
	osg::BoundingSphere getBound();
	void collide();
};

#include "Game.h"
#endif
