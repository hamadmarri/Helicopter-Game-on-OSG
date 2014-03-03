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



void testModel() {
	osgViewer::Viewer viewer;
	osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<Helicopter> h = new Helicopter();
	osg::ref_ptr<osg::Node> t = new osg::Node();

	t = osgDB::readNodeFile("lz.osg");

//	root->addChild(m->get());
	root->addChild(t.get());
	viewer.setSceneData(root);
	viewer.run();
}


int main() {
	
	testModel();
	
	return 0;
}