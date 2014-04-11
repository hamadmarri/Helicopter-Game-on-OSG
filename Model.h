//
//  Model.h
//
//	See main.cpp file header for credits
//
//	Purpose:	Model class is inherited from osg::Group, it
//				on top of that some functionalities that is useful
//				for this project, such as setPosition and scale.
//				Also, the most important thing is to encapsulate
//				the model as one object without caring of the actual
//				osg nodes' hierarchy within the model object
//

#ifndef __HelicopterProject__Model_h__
#define __HelicopterProject__Model_h__

#include <osgDB/ReadFile>
#include <osg/PositionAttitudeTransform>
#include <osg/MatrixTransform>


class Game;


class Model : public osg::Group {
public:
	// default constructor
	Model(Game *game);
	
	virtual ~Model() { };
	
	// copy constructor
	Model(const Model &B);
	
	void setPosistion(osg::Vec3f newPos);
	osg::Vec3f getPosistion();
	void setScale(osg::Matrix scale);
    
	osg::Group* getNode();
	osg::PositionAttitudeTransform* getPAT();
	osg::MatrixTransform* getMatrixTransform();
	
protected:
	// to convert to regular x, y, z axis
	osg::Vec3f convertToRealAxis(osg::Vec3f aVector);
	
	// to convert to system x, y, z axis
	osg::Vec3f convertToSytemAxis(osg::Vec3f aVector);
	
	osg::ref_ptr<osg::Group> node;
	osg::ref_ptr<osg::PositionAttitudeTransform> PAT;
	osg::ref_ptr<osg::MatrixTransform> matrixTransform;
	
	Game *game;
private:
	void initializer();
};


#include "Game.h"
#endif








