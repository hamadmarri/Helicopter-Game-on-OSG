//
//  Obstacles.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//

#include "Obstacle.h"
#include "Model.h"

Obstacle::Obstacle():Model(){
    
}



Obstacle::Obstacle(osg::Node* o){
    set(o);
}



void Obstacle::set(osg::Node* a){
	this->node->addChild(a);
}
