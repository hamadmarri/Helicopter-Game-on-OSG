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


void ModelFactory::add(const std::string name, Model *m) {
	ModelFactory::getInstance()->models[name] = m;
}


Model* ModelFactory::get(const std::string name) {
	if (ModelFactory::getInstance()->models.find(name) == ModelFactory::getInstance()->models.end()) {
		create(name);
	}
	
	return ModelFactory::getInstance()->models[name];
}


Model* ModelFactory::create(const std::string name) {
	
	Model *model;
	
	if (name == "helicopter") {
		model = new Helicopter();
		ModelFactory::getInstance()->models[HELICOPTER_NAME] = model;
	} else if (name == "terrain") {
		model = new Terrain();
		ModelFactory::getInstance()->models[TERRAIN_NAME] = model;
	}  else if (name == "sky") {
		model = new Sky();
		ModelFactory::getInstance()->models[SKY_NAME] = model;
	} else {
		return nullptr;
	}
	
	return model;
}










