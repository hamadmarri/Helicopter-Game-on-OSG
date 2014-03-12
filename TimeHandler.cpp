//
//  TimeHandler.cpp
//  
//
//  Created by Hamad Almarri on 3/3/2014.
//
//  Modified by Alotaibi, Fares on 3/9/2014
// NotifyAll (Event event) has been modified here

#include "TimeHandler.h"


// we are handling eventyType 
bool TimeHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	if (ea.getEventType() == osgGA::GUIEventAdapter::FRAME)
        NotifyAll(Event(EventType::UPDATE_POSITION));
	
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


void TimeHandler::NotifyAll(Event event) {
	for (auto observer = this->observers.begin(); observer != this->observers.end(); observer++)
		(*observer)->Update(event);
}