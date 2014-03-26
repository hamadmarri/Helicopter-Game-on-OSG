//
//  TimeHandler.h
//
//	See main.cpp file header for credits
//


#ifndef __HelicopterProject__TimeHandler__
#define __HelicopterProject__TimeHandler__


#include <chrono>
#include <osgGA/GUIEventHandler>
#include "Observable.h"


class TimeHandler : public osgGA::GUIEventHandler, public Observable {
public:
	TimeHandler();
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
private:
	std::chrono::time_point<std::chrono::system_clock> previousTime;
	std::chrono::time_point<std::chrono::system_clock> nowTime;
};


#endif
