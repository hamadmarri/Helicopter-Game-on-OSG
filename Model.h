//
//  Model.h
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#ifndef __HelicopterProject__Model__
#define __HelicopterProject__Model__

#include <osg/PositionAttitudeTransform>

class Model : public osg::ref_ptr<osg::Node> {
public:
	// default constructor
	Model();
	
	// copy constructor
	Model(const Model &B);
	
	
protected:
	osg::ref_ptr<osg::PositionAttitudeTransform> PAT;
	
private:
	void initializer();
};


#endif /* defined(__HelicopterProject__Model__) */
