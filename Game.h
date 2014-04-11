//
//  Game.h
//
//	See main.cpp file header for credits
//
//  The main purpose of this class core of the helicopter game.
//	(more details on the documentation in .cpp file of the game class).
//
//	Created by Fares Alotaibi
//	Modified by Hamad Almarri
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
#include "Configuration.h"
#include "HudsManager.h"
#include "Collision.h"
#include "Logger.h"


class Game {
public:
	
	Game();
	
	~Game();
	
    void initialize(std::string logFileName);
	
	void initialize();
	
	void run();
	
	void run(const char *fileName);
	
	void initializeCamera();
	
	void initializeHudsManager();
	
	void initializePopupHelpScreen();
	
	osg::ref_ptr<osg::Group>& getRoot();
	
	Helicopter* getHelicopter();
	
	std::vector<Model*> getModels();
	
	TimeHandler* getTimeHandler();
	
	Configuration* getConfiguration();
	
	HudsManager* getHudsManager();
	
	HudsManager* getPopupHelpScreen();
	
	Collision* getCollision();
	
	Logger* getLogger();
	
private:
	
	static void runScript(const char *fileName, osg::ref_ptr<Helicopter> helicopter);
	
	TimeHandler *timeHandler;
	
	osg::ref_ptr<osg::Group> root;
	
	HudsManager *hudsManager;
	
	HudsManager *popupHelpScreen;
	
	Collision *collision;
	
	Logger *logger;
	
	Configuration *configuration;
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker;
	osgViewer::Viewer viewer;
	
	// vector of all game models
	std::vector<Model*> models;
};


#endif
