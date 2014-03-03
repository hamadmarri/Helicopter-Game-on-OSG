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



void Model::setPosistion(osg::Vec3f newPos) {
	this->PAT->setPosition(newPos);
}


void Model::initializer() {
	this->PAT = new osg::PositionAttitudeTransform();
	this->matrixTransform = new osg::MatrixTransform();
	this->PAT->addChild(this);
	this->matrixTransform->addChild(this);
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







