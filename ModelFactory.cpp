//
//  ModelFactory.cpp
//  This is the implementation of a ModelFactory class. It has two main function to set the game , and to create
//  any model passed to the creation function.
//	See main.cpp file header for credits
//


#include "ModelFactory.h"

// copy constructor to set the game
ModelFactory::ModelFactory(Game *game) {
	this->game = game;
}


// model creation function , passing ModelsTypes object to check which model should the function create  to the client
Model* ModelFactory::create(ModelsTypes modelType) {
	
	if (modelType == ModelsTypes::HELICOPTER)           // if the passing parameter is HELICOPTER
		return new Helicopter(game);                    // create a new instance of it
	else if (modelType == ModelsTypes::TERRAIN)         // if terrain , then create new terrain
		return new Terrain(game);
	else if (modelType == ModelsTypes::SKY)             // also if sky , then create a new sky
		return new Sky(game);
	else if (modelType == ModelsTypes::EIFFEL_TOUR) {       // if model is eiffel_tour, then create this model by
		Obstacle *eiffel = new Obstacle(game, osgDB::readNodeFile("320/tour-eiffel-ba.ac"));  // upload the model
		eiffel->setPosistion(osg::Vec3f (0.0f, 150.0f, -9.0f));                     // set the model in a fix position
		return eiffel;
	}
	else if (modelType == ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE) {      // if it is large_residential_highrise model
		Obstacle *building = new Obstacle(game, osgDB::readNodeFile("2705/large-residential-highrise.ac")); // upload the model
		building->setPosistion(osg::Vec3f (100.0f, 50.0f, -4.0f));              // set it in a fixed position
		return building;
	}
	else if (modelType == ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE_ORANGE) {     // also here if it is large_residential_highise_orange model
		Obstacle *building = new Obstacle(game, osgDB::readNodeFile("2706/large-residential-highrise-orange.ac")); // upload the model
		building->setPosistion(osg::Vec3f (200.0f, 0.0f, 11.0f));     // set it in a fixed position
		return building;
	}
	else if (modelType == ModelsTypes::TARGET) {    // check if it a target, then create a sphere model
		Obstacle *targetMdl = new Obstacle(game);
		
		// ********************************************      // creation of a sphere using ShapeDrawable
		osg::ref_ptr<osg::ShapeDrawable> target;
		target  = new osg::ShapeDrawable;
		target->setShape(new osg::Sphere(osg::Vec3(0.0f, 0.0f,0.0f), 100.5f));      
		target->setColor(osg::Vec4(0.5f,0.5f,0.5f,1.0f));
		osg::ref_ptr<osg::Geode> targetNode = new osg::Geode;
		targetNode->addDrawable(target.get());
		targetMdl->getNode()->addChild(targetNode);
		// ********************************************
		
		targetMdl->setPosistion(osg::Vec3f (1000.0f, -30.0f, 100.0f));
		return targetMdl;
	}
	
	return nullptr;
}










