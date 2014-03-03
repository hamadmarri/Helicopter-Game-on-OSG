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
	this->PAT->addChild(this);
	this->PAT->setPosition(osg::Vec3f(100.0, 0.0, 100.0));
}


osg::Group* Model::get() {
	return this->PAT;
}


osg::Group* Model::operator()() {
	return get();
}


osg::PositionAttitudeTransform* Model::getPAT() {
	return this->PAT;
}


osg::MatrixTransform* Model::getMatrixTransform() {
	return this->matrixTransform;
}







