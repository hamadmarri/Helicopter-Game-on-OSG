//
//  Game.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
// SID: 200288569
//

#include "Game.h"



void Game::initialize(){
    
    
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker = new osgGA::NodeTrackerManipulator;;
	osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<Helicopter> helicopter = static_cast<Helicopter*>(ModelFactory::getInstance()->get(ModelsTypes::HELICOPTER));
	osg::ref_ptr<Terrain> terrain =	static_cast<Terrain*>(ModelFactory::getInstance()->get(ModelsTypes::TERRAIN));
	osg::ref_ptr<Sky> sky = static_cast<Sky*>(ModelFactory::getInstance()->get(ModelsTypes::SKY));
	osg::ref_ptr<Obstacle> eiffelTour = static_cast<Obstacle*>(ModelFactory::getInstance()->get(ModelsTypes::EIFFEL_TOUR));
    osg::ref_ptr<Obstacle> building1 = static_cast<Obstacle*>(ModelFactory::getInstance()->get(ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE));
    osg::ref_ptr<Obstacle> building2 = static_cast<Obstacle*>(ModelFactory::getInstance()->get(ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE_ORANGE));
    Controller* controller = new Controller();
    TimeHandler* timhandler = new  TimeHandler();
    

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
	
	
	// add children nodes to root
	root->addChild(helicopter.get());
	root->addChild(terrain.get());
	root->addChild(sky.get());
    root->addChild(eiffelTour.get());
	root->addChild(building1.get());
	root->addChild(building2.get());
	
	// setup viewer
	this->viewer.addEventHandler(controller);
	this->viewer.addEventHandler(timhandler);
	this->viewer.setSceneData(root.get());
    this->viewer.setCameraManipulator(nodeTracker.get());
	this->viewer.run();
}






