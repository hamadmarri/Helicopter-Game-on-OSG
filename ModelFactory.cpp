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



Model* ModelFactory::get(ModelsTypes modelType) {
	
	if (modelType == ModelsTypes::HELICOPTER)
		return new Helicopter();
	else if (modelType == ModelsTypes::TERRAIN)
		return new Terrain();
	else if (modelType == ModelsTypes::SKY)
		return new Sky();
	else if (modelType == ModelsTypes::EIFFEL_TOUR) {
		Obstacle *eiffel = new Obstacle();
		eiffel->set(osgDB::readNodeFile("320/tour-eiffel-ba.ac"));
		eiffel->setPosistion(osg::Vec3f (200.0f, -3080.0f, -600.0f));
		return eiffel;
	}
	else if (modelType == ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE) {
		Obstacle *building = new Obstacle();
		building->set(osgDB::readNodeFile("2705/large-residential-highrise.ac"));
		building->setPosistion(osg::Vec3f (500.0f, -3080.0f, -200.0f));
		return building;
	}
	else if (modelType == ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE_ORANGE) {
		Obstacle *building = new Obstacle();
		building->set(osgDB::readNodeFile("2706/large-residential-highrise-orange.ac"));
		building->setPosistion(osg::Vec3f (0.0f, -3080.0f, -400.0f));
		return building;
	}
	
	return nullptr;
}










