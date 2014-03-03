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

void Obstacle::set(osg::Node* a){
	this->node->addChild(a);
}

Obstacle::Obstacle(osg::Node* o){
    
    set(o);
    
    
}