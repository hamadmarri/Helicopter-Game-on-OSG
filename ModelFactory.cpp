//
//  ModelFactory.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#include "ModelFactory.h"


ModelFactory::ModelFactory() {
	
}


ModelFactory* ModelFactory::getInstance() {
	
	static ModelFactory *instance = nullptr;
	
	if (instance == nullptr)
		instance = new ModelFactory();
	
	return instance;
}


void ModelFactory::addModel(const std::string name, Model *m) {
	ModelFactory::getInstance()->models[name] = m;
}


Model* ModelFactory::getModel(const std::string name) {
	return ModelFactory::getInstance()->models[name];
}