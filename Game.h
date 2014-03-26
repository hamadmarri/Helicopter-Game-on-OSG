//
//  Game.h
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
//  The main purpose of this class is just an UI to our helicopter game. It will have one function and a viewer. From this class the user can interact with the helicopter. Just call initilize function to set the scence for the player.(more details on the documentation in .cpp file of the game class ).

#ifndef __HelicopterProject__Game_h__
#define __HelicopterProject__Game_h__


#include <vector>
#include <thread>
#include <osgViewer/Viewer>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osgGA/NodeTrackerManipulator>
#include "Helicopter.h"
#include "ModelFactory.h"
#include "TimeHandler.h"
#include "HelicopterController.h"
#include "ScriptRunner.h"
#include "Configuration.h"


// game class created
class Game  {
public:
	Game();
    void initialize();
    
	void run();
	void run(const char *fileName);
	
	Helicopter* getHelicopter();
	
	Configuration* getConfiguration();
	
private:
	static void runScript(const char *fileName, osg::ref_ptr<Helicopter> helicopter);
	osgViewer::Viewer viewer;
	
	// vector of all game models
	std::vector<Model*> models;
};


#endif
