//
//  Model.cpp
//  This is the implementation of Model class. The main purpose of is to initialize the
//  PAT, matrixTransfrom, node , and to set position, set scale, convert from to real Axis,
//  convert to system Axis, and some more getter functions to reuturn positins, PAT, node ,matrixTransform.
//
//	See main.cpp file header for credits
//

#include "Model.h"

// once the  constructor called, setting the game will be made and an initialization of  PAT,matrixTransform,node.
Model::Model(Game *game) : osg::Group() {
	this->game = game;
	initializer();
}



Model::Model(const Model &B) {
	// TODO:	need to confirm if deep copy will work
	//			with osg node type
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


// return the node function
osg::Group* Model::getNode() {
	return this->node.get();
}


// setting new position to convert it from regular x,y,z to a system x,y,z
void Model::setPosistion(osg::Vec3f newPos) {
	this->PAT->setPosition(convertToSytemAxis(newPos));
}


// return the real positon of x,y,z
osg::Vec3f Model::getPosistion() {
	return convertToRealAxis(this->PAT->getPosition());
}


// setting the scale of matrixTransforms
void Model::setScale(osg::Matrix scale) {
	this->matrixTransform->setMatrix(scale);
}

// return the PAT

osg::PositionAttitudeTransform* Model::getPAT() {
	return this->PAT.get();
}


// retunr the matrixTransform function
osg::MatrixTransform* Model::getMatrixTransform() {
	return this->matrixTransform.get();
}


// convert to a system Axis x,y,z 
osg::Vec3f Model::convertToSytemAxis(osg::Vec3f aVector) {
	return (osg::Vec3f(aVector.y(), aVector.z(), aVector.x()));
}


// convert to a Real Axis x,y,z
osg::Vec3f Model::convertToRealAxis(osg::Vec3f aVector) {
	return (osg::Vec3f(aVector.z(), aVector.x(), aVector.y()));
}






