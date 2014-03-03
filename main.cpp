//
//  main.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#include <osgViewer/Viewer>
#include <osg/Node>
#include <osgDB/ReadFile>
#include "Helicopter.h"
#include "Terrain.h"
#include "Sky.h"
#include "ModelFactory.h"



void testModel() {
	osgViewer::Viewer viewer;
	osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<Helicopter> h = new Helicopter();
	osg::ref_ptr<osg::Node> t = new osg::Node();

	t = osgDB::readNodeFile("lz.osg");

	root->addChild(h->get());
	root->addChild(t.get());
	viewer.setSceneData(root);
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
	
//	testModel();
	
	testModelFactory();
	
	
	return 0;
}