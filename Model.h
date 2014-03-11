//
//  Model.h
//  HelicopterProject
//
//	Purpose:	Model class is inherited from osg::Group, it
//				on top of that some functionalities that is useful
//				for this project, such as setPosition and scale.
//				Also, the most important thing is to encapsulate
//				the model as one object without caring of the actual
//				osg nodes' hierarchy within the model object
//
//  Created by Hamad Almarri on 3/2/2014.
//

#ifndef __HelicopterProject__Model__
#define __HelicopterProject__Model__

#include <osgDB/ReadFile>
#include <osg/PositionAttitudeTransform>
#include <osg/MatrixTransform>
#include "Observer.h"
#include "Motion.h"

class Model : public osg::Group {
public:
	// default constructor
	Model();
	
	// copy constructor
	Model(const Model &B);
	
	void setPosistion(osg::Vec3f newPos);
	void setScale(osg::Matrix scale);
    
	osg::Group* getNode();
	osg::PositionAttitudeTransform* getPAT();
	osg::MatrixTransform* getMatrixTransform();
	
protected:
	osg::ref_ptr<osg::Group> node;
	osg::ref_ptr<osg::PositionAttitudeTransform> PAT;
	osg::ref_ptr<osg::MatrixTransform> matrixTransform;
	
private:
	void initializer();
};


#endif /* defined(__HelicopterProject__Model__) */
