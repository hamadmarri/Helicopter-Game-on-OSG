//
//  TimeHandler.h
//  testOSG
//
//  Created by Hamad Almarri on 3/3/2014.
//


#ifndef __testOSG__TimeHandler__
#define __testOSG__TimeHandler__

#include <osgGA/GUIEventHandler>
#include "Game.h"

class TimeHandler : public osgGA::GUIEventHandler {
public:
	TimeHandler(Game *g) : game(g) {}
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
private:
	Game *game;
};


#endif /* defined(__testOSG__TimeHandler__) */
