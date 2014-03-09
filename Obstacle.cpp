//
//  Obstacles.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
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
