//
//  Game.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#include "Game.h"



void Game::initialize(){
    
    
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker = new osgGA::NodeTrackerManipulator;;
	osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<Helicopter> h = new Helicopter();
	osg::ref_ptr<Terrain> t = new Terrain();
	osg::ref_ptr<Sky> s = new Sky();
    osg::ref_ptr<Obstacle> o1 = new Obstacle(osgDB::readNodeFile("2706/large-residential-highrise-orange.ac"));
    osg::ref_ptr<Obstacle> o2 = new Obstacle(osgDB::readNodeFile("2705/large-residential-highrise.ac"));
    osg::ref_ptr<Obstacle> o3 = new Obstacle(osgDB::readNodeFile("320/tour-eiffel-ba.ac"));
    Controller* = new controller;
    TimeHandler* = new  timehandler;
    
    ModelFactory::getInstance()->add(HELICOPTER_NAME,h.get());
    ModelFactory::getInstance()->add(TERRAIN_NAME,t.get());
    ModelFactory::getInstance()->add(SKY_NAME,s.get());
    ModelFactory::getInstance()->add("building1",o1.get());
    ModelFactory::getInstance()->add("building2",o2.get());
    ModelFactory::getInstance()->add("building3",o3.get());
    
    
    
    
    o1->setPosistion(osg::Vec3 (0.0f, -3080.0f, -400.0f));
    o2->setPosistion(osg::Vec3f (500.0f, -3080.0f, -200.0f));
    o3->setPosistion(osg::Vec3f (200.0f, -3080.0f, -600.0f));
	// set node tracker
	nodeTracker->setHomePosition(osg::Vec3f(0.0f, 7.0f, -35.0f),	//homeEye
								 osg::Vec3f(),						//homeCenter
								 osg::Y_AXIS);						//homeUp
	nodeTracker->setTrackerMode( osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION );
    nodeTracker->setRotationMode( osgGA::NodeTrackerManipulator::TRACKBALL );
	nodeTracker->setTrackNode(h.get());
	
    
	// setup viewer
	osg::DisplaySettings::instance()->setNumMultiSamples(4);	
	
    viewer.addEventHandler(controller);
	viewer.addEventHandler(timehandler);
	
	
	root->addChild(h.get());
	root->addChild(t.get());
	root->addChild(s.get());
    root->addChild(o1.get());
    root->addChild(o2.get());
    root->addChild(o3.get());
    
	viewer.setSceneData(root.get());
    viewer.setCameraManipulator(nodeTracker.get());
	viewer.run();
}