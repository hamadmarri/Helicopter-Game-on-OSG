//
//  Obstacles.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#ifndef testOsg_Obstacles_h
#define testOsg_Obstacles_h


#include "Model.h"
// constructing the obstacles class
class Obstacles : public Model{
public:
    Obstacles();
    osg::Group* get();
};


#endif
