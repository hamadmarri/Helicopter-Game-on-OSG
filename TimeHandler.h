//
//  TimeHandler.h
//
//  Created by Hamad Almarri on 3/3/2014.
//
// Ediated By Alotaibi, Fares on 3/9/2014


#ifndef __HelicopterProject__TimeHandler__
#define __HelicopterProject__TimeHandler__

#include <osgGA/GUIEventHandler>
#include "Observable.h"


class TimeHandler : public osgGA::GUIEventHandler, public Observable {
public:
	TimeHandler() {}
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
};


#endif
