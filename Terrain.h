//
//  Terrain.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#ifndef testOsg_Terrain_h
#define testOsg_Terrain_h

#include "Model.h"
class Terrain : public Model{
public:
    Terrain();
    osg::Group* get();
};

#endif
