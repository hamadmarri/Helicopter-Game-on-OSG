//
//  main.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#include <osgViewer/Viewer>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osgGA/NodeTrackerManipulator>
#include "Helicopter.h"
#include "Terrain.h"
#include "Sky.h"
#include "ModelFactory.h"
#include "Obstacle.h"
#include "Game.h"

void testModel() {
	osgViewer::Viewer viewer;
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker = new osgGA::NodeTrackerManipulator;;
	osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<Helicopter> h = new Helicopter();
	osg::ref_ptr<Terrain> t = new Terrain();
	osg::ref_ptr<Sky> s = new Sky();
    osg::ref_ptr<Obstacle> o1 = new Obstacle(osgDB::readNodeFile("320/large-residential-highrise-orange.ac"));
    
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
	//root->addChild(s.get());
    root->addChild(o1.get());
	viewer.setSceneData(root.get());
//	viewer.setCameraManipulator(nodeTracker.get());
	viewer.run();
}

void testModelFactory() {
//	osg::ref_ptr<Helicopter> h = new Helicopter();
//	osg::ref_ptr<Terrain> t = new Terrain();
//	osg::ref_ptr<Sky> s = new Sky();
	osg::ref_ptr<Model> m1;
	osg::ref_ptr<Model> m2;
	osg::ref_ptr<Model> m3;
	
//	ModelFactory::add("h", h);
//	ModelFactory::add("t", t);
//	ModelFactory::getInstance()->add("s", s);
	
	m1 = ModelFactory::getInstance()->get(HELICOPTER_NAME);
	m2 = ModelFactory::getInstance()->get(TERRAIN_NAME);
	m3 = ModelFactory::getInstance()->get(SKY_NAME);
	
	
	
	std::cout << "";
	
}

int main() {
	
	//testModel();
	
//	testModelFactory();
	Game test;
    test.initialize();
	
	return 0;
}