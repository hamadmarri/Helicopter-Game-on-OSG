//
//  Game.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#include "Game.h"

#include "Helicopter.h"
#include "Terrain.h"
#include "Sky.h"
#include "ModelFactory.h"
#include "Obstacle.h"


void Game::initialize(){
    
    
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker = new osgGA::NodeTrackerManipulator;;
	osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<Helicopter> h = new Helicopter();
	osg::ref_ptr<Terrain> t = new Terrain();
	osg::ref_ptr<Sky> s = new Sky();
    osg::ref_ptr<Obstacle> o1 = new Obstacle(osgDB::readNodeFile("320/large-residential-highrise-orange.ac"));
    
    ModelFactory::getInstance()->add(HELICOPTER_NAME,h.get());
    ModelFactory::getInstance()->add(TERRAIN_NAME,t.get());
    ModelFactory::getInstance()->add(SKY_NAME,s.get());
    ModelFactory::getInstance()->add("building",o1.get());
    
    
    
    o1->setPosistion(osg::Vec3 (0.0f, -3080.0f, -400.0f));
	// set node tracker
	nodeTracker->setHomePosition(osg::Vec3f(0.0f, 7.0f, -35.0f),	//homeEye
								 osg::Vec3f(),						//homeCenter
								 osg::Y_AXIS);						//homeUp
	nodeTracker->setTrackerMode( osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION );
    nodeTracker->setRotationMode( osgGA::NodeTrackerManipulator::TRACKBALL );
	nodeTracker->setTrackNode(h.get());
	
    
	// setup viewer
	osg::DisplaySettings::instance()->setNumMultiSamples(4);
	//	viewer.setUpViewInWindow(50, 50, 800, 600);
	
	
	
	
	root->addChild(h.get());
	root->addChild(t.get());
	root->addChild(s.get());
    root->addChild(o1.get());
	viewer.setSceneData(root.get());
    //	viewer.setCameraManipulator(nodeTracker.get());
	
}