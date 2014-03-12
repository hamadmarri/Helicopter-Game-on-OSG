//
//  TimeHandler.h
//  testOSG
//
//  Created by Hamad Almarri on 3/3/2014.
//
// Ediated By Alotaibi, Fares on 3/9/2014
// void NotifyAll(Event event) has been modified from me, and I will modify the
// implementation for it.

#ifndef __testOSG__TimeHandler__
#define __testOSG__TimeHandler__

#include <osgGA/GUIEventHandler>
#include "Game.h"
#include "Observable.h"


class TimeHandler : public osgGA::GUIEventHandler, public Observable {
public:
	TimeHandler() {}
	
	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*);
	
	void AddObserver(Observer *observer);
	void RemoveObserver(Observer *observer);
    // here is the change 
	void NotifyAll(Event event);
	
private:
	std::vector<Observer*> observers;
};


#endif /* defined(__testOSG__TimeHandler__) */
