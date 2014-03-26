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


Obstacle::Obstacle():Model() {
    
}



Obstacle::Obstacle(osg::Node* node) {
    set(node);
}



void Obstacle::set(osg::Node* node) {
	this->node->addChild(node);
}
