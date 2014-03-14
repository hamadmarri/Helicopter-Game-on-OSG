//
//  TimeHandler.cpp
//  
//
//  Created by Hamad Almarri on 3/3/2014.
//
//  Modified by Alotaibi, Fares on 3/9/2014


#include "TimeHandler.h"



bool TimeHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	if (ea.getEventType() == osgGA::GUIEventAdapter::FRAME)
        NotifyAll(Event(EventType::UPDATE_POSITION));
	
	return false;
}
