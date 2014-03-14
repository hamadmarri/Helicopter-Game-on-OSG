//
//  Sky.cpp
//
//  Created by Fares Alotaibi on 2014-03-02.
//  SID: 200288569
//

#include "Sky.h"


// constructor to display the skydome in some position
Sky::Sky() : Model() {
    this->node->addChild(osgDB::readNodeFile("skydome.osgt"));
	this->matrixTransform->setMatrix(osg::Matrix::translate(-25000.0f, -25000.0f, -5000.0f)
				   * osg::Matrix::rotate(osg::DegreesToRadians(90.0f),osg::Vec3f(1,0,0),
										 osg::DegreesToRadians(0.0f),osg::Vec3f(0,1,0),
										 osg::DegreesToRadians(180.0f),osg::Vec3f(0,0,1)
										 )
				   );

}
