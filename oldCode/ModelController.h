/*
	ModelController
		Sets up key events for the helicopter to increase and decrease rotation.
		Uses modified lab code to call our functions

		Credits: Tylor Froese, Brian Schwietzer, Trevor Douglas (using lab code)

*/


#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osgGA/GUIEventHandler>
#include "Render.h"


class ModelController : public osgGA::GUIEventHandler
{

public:
	ModelController( osg::PositionAttitudeTransform * node , Render * render )
		: _model(node), gameRender(render) // This class variable _model will be initialized to node
	{}

	virtual bool handle( const osgGA::GUIEventAdapter& ea,
		                       osgGA::GUIActionAdapter& aa );
	//A protected nonstatic base class member can be accessed by members and 
	//friends of any classes derived from that base class
protected:
	osg::ref_ptr<osg::PositionAttitudeTransform> _model;
	Render * gameRender;
};


#endif