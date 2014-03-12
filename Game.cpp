//
//  Game.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
// SID: 200288569
// Here is the main function call in our UI. It will set the scence, helicopters, and other models in some specific locaitons we had decided on. Setting up all things so that the player can play the game.

#include "Game.h"



void Game::initialize(){
    
    // creating nodeTrackerManipulator, group, some model factory, from our factory design. Also setting the controller, timehandler
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker = new osgGA::NodeTrackerManipulator;;
	osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<Helicopter> helicopter = static_cast<Helicopter*>(ModelFactory::getInstance()->get(HELICOPTER_NAME));
	osg::ref_ptr<Terrain> terrain =	static_cast<Terrain*>(ModelFactory::getInstance()->get(TERRAIN_NAME));
	osg::ref_ptr<Sky> sky = static_cast<Sky*>(ModelFactory::getInstance()->get(SKY_NAME));
	osg::ref_ptr<Obstacle> obstacle1 = static_cast<Obstacle*>(ModelFactory::getInstance()->get(OBSTACLE_NAME));
    osg::ref_ptr<Obstacle> obstacle2 = static_cast<Obstacle*>(ModelFactory::getInstance()->get(OBSTACLE_NAME));
    osg::ref_ptr<Obstacle> obstacle3 = static_cast<Obstacle*>(ModelFactory::getInstance()->get(OBSTACLE_NAME));
    Controller* controller = new Controller();
    TimeHandler* timhandler = new  TimeHandler();
    
    // we has decided these obstacles on the scence to be these three models at least
    
	obstacle1->set(osgDB::readNodeFile("2706/large-residential-highrise-orange.ac"));
	obstacle2->set(osgDB::readNodeFile("2705/large-residential-highrise.ac"));
	obstacle3->set(osgDB::readNodeFile("320/tour-eiffel-ba.ac"));
	
    // we set the position of each of them 
    obstacle1->setPosistion(osg::Vec3 (0.0f, -3080.0f, -400.0f));
    obstacle2->setPosistion(osg::Vec3f (500.0f, -3080.0f, -200.0f));
    obstacle3->setPosistion(osg::Vec3f (200.0f, -3080.0f, -600.0f));



    // add obeservers
    controller->AddObserver(helicopter.get()->joystick);
	controller->AddObserver(helicopter.get()->rotor);
    timhandler->AddObserver(helicopter.get());
    
     
	// set node tracker
	nodeTracker->setHomePosition(osg::Vec3f(0.0f, 7.0f, -35.0f),	//homeEye
								 osg::Vec3f(),						//homeCenter
								 osg::Y_AXIS);						//homeUp
	nodeTracker->setTrackerMode(osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION);
    nodeTracker->setRotationMode(osgGA::NodeTrackerManipulator::TRACKBALL);
	nodeTracker->setTrackNode(helicopter.get());
	
	
	// setup viewer
	root->addChild(helicopter.get());
	root->addChild(terrain.get());
	root->addChild(sky.get());
    root->addChild(obstacle1.get());
	root->addChild(obstacle2.get());
	root->addChild(obstacle3.get());
	this->viewer.addEventHandler(controller);
	this->viewer.addEventHandler(timhandler);
	this->viewer.setSceneData(root.get());
    this->viewer.setCameraManipulator(nodeTracker.get());
	this->viewer.run();
}






