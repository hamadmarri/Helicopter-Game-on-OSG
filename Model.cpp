//
//  Model.cpp
//
//	See main.cpp file header for credits
//

#include "Model.h"


Model::Model() : osg::Group() {
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



osg::Group* Model::getNode() {
	return this->node.get();
}



void Model::setPosistion(osg::Vec3f newPos) {
	this->PAT->setPosition(convertToSytemAxis(newPos));
}



osg::Vec3f Model::getPosistion() {
	return convertToRealAxis(this->PAT->getPosition());
}



void Model::setScale(osg::Matrix scale) {
	this->matrixTransform->setMatrix(scale);
}



osg::PositionAttitudeTransform* Model::getPAT() {
	return this->PAT.get();
}



osg::MatrixTransform* Model::getMatrixTransform() {
	return this->matrixTransform.get();
}



osg::Vec3f Model::convertToSytemAxis(osg::Vec3f aVector) {
	return (osg::Vec3f(aVector.y(), aVector.z(), aVector.x()));
}



osg::Vec3f Model::convertToRealAxis(osg::Vec3f aVector) {
	return (osg::Vec3f(aVector.z(), aVector.x(), aVector.y()));
}






