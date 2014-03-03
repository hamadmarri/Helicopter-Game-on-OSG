//
//  Model.h
//  HelicopterProject
//
//  Created by Hamad Almarri on 3/2/2014.
//

#ifndef __HelicopterProject__Model__
#define __HelicopterProject__Model__

#include <osgDB/ReadFile>
#include <osg/PositionAttitudeTransform>

class Model : public osg::Group {
public:
	// default constructor
	Model();
	
	// copy constructor
	Model(const Model &B);
	
protected:
//	osg::ref_ptr<osg::Node> node;
	osg::ref_ptr<osg::PositionAttitudeTransform> PAT;
	
private:
	void initializer();
};


#endif /* defined(__HelicopterProject__Model__) */
