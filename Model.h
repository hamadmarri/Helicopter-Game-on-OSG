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
#include <osg/MatrixTransform>


class Model : public osg::Group {
public:
	// default constructor
	Model();
	
	// copy constructor
	Model(const Model &B);
	
	void setPosistion(osg::Vec3f newPos);
	
	virtual osg::Group* get() = 0;
	osg::Group* operator()();
	osg::PositionAttitudeTransform* getPAT();
	osg::MatrixTransform* getMatrixTransform();
	
protected:
	osg::ref_ptr<osg::PositionAttitudeTransform> PAT;
	osg::ref_ptr<osg::MatrixTransform> matrixTransform;
	
private:
	void initializer();
};


#endif /* defined(__HelicopterProject__Model__) */
