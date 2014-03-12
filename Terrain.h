//
//  Terrain.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
// The Terrain class, it has only one constructor to set the position of our terrain and call a file "model" and set it to the scen in the helicopter game.
//

#ifndef testOsg_Terrain_h
#define testOsg_Terrain_h

#include "Model.h"
#include "WorldConstants.h"

class Terrain : public Model {
public:
    Terrain();
};

#endif
