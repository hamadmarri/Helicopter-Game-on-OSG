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
			NotifyAll('\0');
			break;
	}
	
	return false;
}


void TimeHandler::AddObserver(Observer *observer) {
	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
	if (it == this->observers.end())
		this->observers.push_back(observer);
}


void TimeHandler::RemoveObserver(Observer *observer) {
	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
	if (it != this->observers.end())
		this->observers.erase(it);
}


void TimeHandler::NotifyAll(char event) {
	for (auto observer = this->observers.begin(); observer != this->observers.end(); observer++)
		(*observer)->Observe(event);
}