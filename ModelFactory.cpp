//
//  ModelFactory.cpp
//
//	See main.cpp file header for credits
//


#include "ModelFactory.h"


ModelFactory::ModelFactory(Game *game) {
	this->game = game;
}



Model* ModelFactory::create(ModelsTypes modelType) {
	
	if (modelType == ModelsTypes::HELICOPTER)
		return new Helicopter(game);
	else if (modelType == ModelsTypes::TERRAIN)
		return new Terrain(game);
	else if (modelType == ModelsTypes::SKY)
		return new Sky(game);
	else if (modelType == ModelsTypes::EIFFEL_TOUR) {
		Obstacle *eiffel = new Obstacle(game, osgDB::readNodeFile("320/tour-eiffel-ba.ac"));
		eiffel->setPosistion(osg::Vec3f (0.0f, 150.0f, -9.0f));
		return eiffel;
	}
	else if (modelType == ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE) {
		Obstacle *building = new Obstacle(game, osgDB::readNodeFile("2705/large-residential-highrise.ac"));
		building->setPosistion(osg::Vec3f (100.0f, 50.0f, -4.0f));
		return building;
	}
	else if (modelType == ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE_ORANGE) {
		Obstacle *building = new Obstacle(game, osgDB::readNodeFile("2706/large-residential-highrise-orange.ac"));
		building->setPosistion(osg::Vec3f (200.0f, 0.0f, 11.0f));
		return building;
	}
	else if (modelType == ModelsTypes::TARGET) {
		Obstacle *targetMdl = new Obstacle(game);
		
		// ********************************************
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










