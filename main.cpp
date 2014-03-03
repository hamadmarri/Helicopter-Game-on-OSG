//
//  main.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#include <osgViewer/Viewer>
#include <osg/Node>
#include <osgDB/ReadFile>
#include "Model.h"



void testModel() {
	osgViewer::Viewer viewer;
	
	osg::ref_ptr<Model> m = new Model();
	
	viewer.setSceneData(m);
	viewer.run();
}


int main() {
	
	testModel();
	
	return 0;
}