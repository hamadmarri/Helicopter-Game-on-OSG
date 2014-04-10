//
//  Game.h
//
//	See main.cpp file header for credits
//
//  The main purpose of this class is just an UI to our helicopter game.
//	It will have one function and a viewer. From this class the user can
//	interact with the helicopter. Just call initilize function to set the
//	scence for the player.
//	(more details on the documentation in .cpp file of the game class).
//

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
#include "GameController.h"
#include "ScriptRunner.h"
#include "Configuration/Configuration.h"
#include "HudsManager.h"
#include "Collision.h"
#include "Logger/Logger.h"


class Game {
public:
	
	Game();
	~Game();
	
    void initialize();
    
	void run();
	void run(const char *fileName);
	
	void initializeCamera();
	
	void initializePopupHelpScreen();
	
	Helicopter* getHelicopter();
	
	std::vector<Model*> getModels();
	
	Configuration* getConfiguration();
	
	TimeHandler *timeHandler;
	
	osg::ref_ptr<osg::Group> root;
	
	HudsManager *hudsManager;
	
	HudsManager *popupHelpScreen;
	
	Collision collision;
	
	Logger logger;
	
private:
	static void runScript(const char *fileName, osg::ref_ptr<Helicopter> helicopter);
	
	Configuration *configuration;
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker;
	osgViewer::Viewer viewer;
	
	// vector of all game models
	std::vector<Model*> models;
};


#endif
