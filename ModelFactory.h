//
//  ModelFactory.h
//  HelicopterProject
//
//	Purpuse:	this class takes care of creating Model instances to client class.
//
//	Type:		Singleton
//
//  Created by Hamad Almarri on 3/2/2014.
//

#ifndef __HelicopterProject__ModelFactory__
#define __HelicopterProject__ModelFactory__


#include "Helicopter.h"
#include "Terrain.h"
#include "Sky.h"
#include "Obstacle.h"


// enum for model children
enum class ModelsTypes {
	HELICOPTER,
	TERRAIN,
	SKY,
	EIFFEL_TOUR,
	LARGE_RESIDENTIAL_HIGHRISE,
	LARGE_RESIDENTIAL_HIGHRISE_ORANGE
};


class ModelFactory {
public:
	
	/*
	 it returns an instance of this class
	 it should be called whenever needs to
	 use the functionality of ModelFactory
	 
	 */
	static ModelFactory* getInstance();
	static Model* create(ModelsTypes modelType);
	
private:
	// empty constructor
	ModelFactory() {};
	
	// these methods are not implemented
	// in order to satisfy singleton properties
	ModelFactory(const ModelFactory&);
	void operator=(const ModelFactory&);
};


#endif /* defined(__HelicopterProject__ModelFactory__) */