//
//  Obstacles.cpp
//
//	See main.cpp file header for credits
//
//  The implementation of the obstacle class has been created.
//	Each obstacle can have a reference from a node to add it to
//	the osg tree easily and save some line of code by calling these functions.
//


#include "Obstacle.h"


Obstacle::Obstacle(Game *game) : Model(game) {
    
}


// a copy constructor to pass a node and set it by using set function below to set the node by using addChild
Obstacle::Obstacle(Game *game, osg::Node* node) : Model(game) {
    set(node);
}


// set function to set the node
void Obstacle::set(osg::Node* node) {
	this->node->addChild(node);
}


// get the boundry function by using the BoundingSpher osg
osg::BoundingSphere Obstacle::getBound() {
	return osg::BoundingSphere(this->PAT->getBound());
}



void Obstacle::collide() {
}



