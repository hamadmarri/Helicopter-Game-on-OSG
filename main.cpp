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
	ModelFactory::getInstance()->i = 10;

	ModelFactory::getInstance()->i = 13;
	
	std::cout << ModelFactory::getInstance()->i << std::endl;
}

int main() {
	
//	testModel();
	
	testModelFactory();
	
	
	return 0;
}