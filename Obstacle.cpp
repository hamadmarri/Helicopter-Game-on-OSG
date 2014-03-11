//
//  Obstacles.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//

#include "Obstacle.h"


Obstacle::Obstacle():Model(){
    
}



Obstacle::Obstacle(osg::Node* node){
    set(node);
}



void Obstacle::set(osg::Node* node){
	this->node->addChild(node);
}
