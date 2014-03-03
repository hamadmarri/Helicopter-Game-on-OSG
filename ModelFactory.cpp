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