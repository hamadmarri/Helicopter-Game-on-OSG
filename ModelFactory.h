//
//  ModelFactory.h
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#ifndef __HelicopterProject__ModelFactory__
#define __HelicopterProject__ModelFactory__

#include <map>
#include <string>
#include "Model.h"
#include "Helicopter.h"
#include "Terrain.h"
#include "Sky.h"
#include "Obstacle.h"


#define HELICOPTER_NAME "helicopter"
#define TERRAIN_NAME "terrain"
#define SKY_NAME "sky"
#define OBSTACLE_NAME "obstacle"


class ModelFactory {
public:
	static ModelFactory* getInstance();
	static Model* get(const std::string name);
	
private:
	ModelFactory() {};
	ModelFactory(const ModelFactory&);
	void operator=(const ModelFactory&);
};


#endif /* defined(__HelicopterProject__ModelFactory__) */