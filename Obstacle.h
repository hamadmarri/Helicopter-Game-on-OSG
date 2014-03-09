//
//  Obstacles.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//

#ifndef testOsg_Obstacle_h
#define testOsg_Obstacle_h


#include "Model.h"
// constructing the obstacle class
class Obstacle : public Model{
public:
    Obstacle();
    Obstacle(osg::Node* o);
    void set(osg::Node* a);
};


#endif
