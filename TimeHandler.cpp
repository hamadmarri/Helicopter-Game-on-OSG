//
//  TimeHandler.cpp
//  testOSG
//
//  Created by Hamad Almarri on 3/3/2014.
//

#include "TimeHandler.h"



bool TimeHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	switch (ea.getEventType()) {
		case osgGA::GUIEventAdapter::FRAME:
//			game->render();
			break;
	}
	
	return false;
}