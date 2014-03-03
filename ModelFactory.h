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

#endif /* defined(__HelicopterProject__ModelFactory__) */


class ModelFactory {
public:
	static ModelFactory* getInstance();

	static void addModel(const std::string name, Model *m);
	static Model* getModel(const std::string name);
	
private:
	std::map<std::string, Model*> models;
	
	ModelFactory();
	ModelFactory(const ModelFactory&);
	void operator=(const ModelFactory&);
};