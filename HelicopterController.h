//
//  HelicopterController.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-26.
//
// HelilcopterController class.
//

#ifndef testOsg_HelicopterController_h
#define testOsg_HelicopterController_h

#include <vector>
#include <algorithm> // find
#include <osgGA/GUIEventHandler>
#include "Helicopter.h"
#include "Observable.h"
#include "Invoker.h"
#include "JoystickCommands.h"
#include "RotorCommands.h"
#include "Configuration.h"


class HelicopterController : public osgGA::GUIEventHandler{
public:
	
	HelicopterController(Helicopter *helicopter);
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
private:
	Helicopter *helicopter;
	Invoker commandsInvoker;
};

#endif
