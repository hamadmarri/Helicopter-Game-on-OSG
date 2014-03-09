//
//  ModelFactory.cpp
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#include "ModelFactory.h"


ModelFactory* ModelFactory::getInstance() {
	
	static ModelFactory *instance = nullptr;
	
	if (instance == nullptr)
		instance = new ModelFactory();
	
	return instance;
}



Model* ModelFactory::get(const std::string name) {
	
	if (name == HELICOPTER_NAME)
		return new Helicopter();
	else if (name == TERRAIN_NAME)
		return new Terrain();
	else if (name == SKY_NAME)
		return new Sky();
	else if (name == OBSTACLE_NAME)
		return new Obstacle();
	
	return nullptr;
}










