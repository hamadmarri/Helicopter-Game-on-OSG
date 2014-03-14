//
//  Game.h
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
//  The main purpose of this class is just an UI to our helicopter game. It will have one function and a viewer. From this class the user can interact with the helicopter. Just call initilize function to set the scence for the player.(more details on the documentation in .cpp file of the game class ).

#ifndef __HelicopterProject__Game_h__
#define __HelicopterProject__Game_h__


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
