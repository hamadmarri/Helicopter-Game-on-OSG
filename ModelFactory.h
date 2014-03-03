//
//  ModelFactory.h
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#ifndef __HelicopterProject__ModelFactory__
#define __HelicopterProject__ModelFactory__

#include <map>
#include "Model.h"

#endif /* defined(__HelicopterProject__ModelFactory__) */


class ModelFactory {
public:
	static ModelFactory* getInstance();
	
	int i;
private:
	ModelFactory();
	ModelFactory(const ModelFactory&);
	void operator=(const ModelFactory&);
};