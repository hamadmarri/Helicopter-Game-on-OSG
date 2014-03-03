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


#define HELICOPTER_NAME "helicopter"
#define TERRAIN_NAME "terrain"
#define SKY_NAME "sky"


class ModelFactory {
public:
	static ModelFactory* getInstance();

	static void add(const std::string name, Model *m);
	static Model* get(const std::string name);
	
private:
	ModelFactory();
	ModelFactory(const ModelFactory&);
	void operator=(const ModelFactory&);
	
	static Model* create(const std::string name);

	
	std::map<std::string, Model*> models;
};


#endif /* defined(__HelicopterProject__ModelFactory__) */