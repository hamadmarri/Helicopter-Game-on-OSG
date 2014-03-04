//
//  Controller.h
//  testOSG
//
//  Created by Hamad Almarri on 3/3/2014.
//


#ifndef __testOSG__Controller__
#define __testOSG__Controller__

#include <vector>
#include <algorithm> // find
#include <osgGA/GUIEventHandler>
#include "JoyStick.h"
#include "Game.h"
#include "Observable.h"

class Controller : public osgGA::GUIEventHandler, public Observable {
public:
	Controller(Game *g) : game(g) {
		joyStick.set_theta(0.0);
		joyStick.set_phi(0.0);
	}
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
	
	virtual void AddObserver(Observer *observer);
    virtual void RemoveObserver(Observer *observer);
    virtual void NotifyAll();
	
private:
	Joystick joyStick;
	Game *game;
	std::vector<Observer*> observers;
};

#endif /* defined(__testOSG__Controller__) */
