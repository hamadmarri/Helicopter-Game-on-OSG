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
	// TODO:	need to confirm if deep copy will work
	//			with osg node type
}



void Model::setPosistion(osg::Vec3f newPos) {
	this->PAT->setPosition(newPos);
}



void Model::setScale(osg::Matrix scale) {
	this->matrixTransform->setMatrix(scale);
}



void Model::initializer() {
	// alocating new instances of PAT, matrixTransform, and node
	this->PAT = new osg::PositionAttitudeTransform();
	this->matrixTransform = new osg::MatrixTransform();
	this->node = new osg::Group();
	
	// setting the hierarchy by
	// adding node to matrixTransform
	this->matrixTransform->addChild(this->node.get());
	
	// adding matrixTransform to PAT
	this->PAT->addChild(this->matrixTransform.get());
	
	// adding PAT to this
	this->addChild(this->PAT.get());
}



osg::Group* Model::getNode() {
	return this->node.get();
}



osg::PositionAttitudeTransform* Model::getPAT() {
	return this->PAT.get();
}



osg::MatrixTransform* Model::getMatrixTransform() {
	return this->matrixTransform.get();
}



