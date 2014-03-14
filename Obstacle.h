//
//  Obstacles.h
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//

#ifndef __HelicopterProject__Obstacle_h__
#define __HelicopterProject__Obstacle_h__


#include "Model.h"

// constructing the obstacle class
class Obstacle : public Model {
public:
    Obstacle();
    Obstacle(osg::Node* node);
    void set(osg::Node* node);
};


#endif
