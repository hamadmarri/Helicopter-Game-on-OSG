//
//  Obstacles.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//  The implementation of the obstacle class has been created. Each obstacle can have a reference from a node to add it to the osg tree easily and save some line of code by calling these functions. 

#include "Obstacle.h"




Obstacle::Obstacle():Model(){
    
}



Obstacle::Obstacle(osg::Node* node){
    set(node);
}



void Obstacle::set(osg::Node* node){
	this->node->addChild(node);
}
