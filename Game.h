//
//  Game.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
//

#ifndef testOsg_Game_h
#define testOsg_Game_h
#include <osgViewer/Viewer>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osgGA/NodeTrackerManipulator>
#include "Helicopter.h"
#include "ModelFactory.h"
#include "TimeHandler.h"
#include "Controller.h"
// game class created

class Game  {
public:
    void initialize();
    
    osgViewer::Viewer viewer;
};


#endif
