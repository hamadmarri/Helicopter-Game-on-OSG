//
//  Controller.h
//
//  Created by Hamad Almarri on 3/3/2014.
// Edited by Alotaibi, Fares on 3/9/2014 .


#ifndef __HelicopterProject__Controller__
#define __HelicopterProject__Controller__

#include <vector>
#include <algorithm> // find
#include <osgGA/GUIEventHandler>
#include "Observable.h"
#include "Configuration.h"


class Controller : public osgGA::GUIEventHandler, public Observable {
public:
	Controller() {}
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
};

#endif
