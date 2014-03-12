//
//  Obstacles.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
// An Obstacle class, this class is to display some models in our sceene, we are required to have at least three model. Thus, we have decided to implement a class called obstacle to set these models easily. One more thing here, this class can be used in the future if we decided to add some more models , and it can be done quickly and easily. by just calling the consturctor.

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
