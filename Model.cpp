//
//  Model.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#include "Model.h"


Model::Model() {
	initializer();
}


Model::Model(const Model &B) {
	initializer();
}


void Model::initializer() {
	this->PAT = new osg::PositionAttitudeTransform();
	this->PAT->addChild(this->get());
}