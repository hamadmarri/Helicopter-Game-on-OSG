//
//  Model.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#include "Model.h"


Model::Model() : osg::Group() {
	initializer();
}


Model::Model(const Model &B) {
	initializer();
}


void Model::initializer() {
	this->addChild(osgDB::readNodeFile("3124/EC-135_Douane.ac"));
	this->PAT = new osg::PositionAttitudeTransform();
	this->addChild(this->PAT.get());
	this->PAT->addChild(this);
	this->PAT->setPosition(osg::Vec3f(0.0, 0.0, 100.0));
}