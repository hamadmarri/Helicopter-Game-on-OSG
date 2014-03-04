//
//  Controller.cpp
//  testOSG
//
//  Created by Hamad Almarri on 3/3/2014.
//


#include "Controller.h"


bool Controller::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	switch (ea.getEventType()) {
		case osgGA::GUIEventAdapter::KEYDOWN:
			switch(ea.getKey()) {
				case 'a': case 'A':
					NotifyAll('a');
					break;
				case 'w': case 'W':
					NotifyAll('w');
					break;
				case 'd': case 'D':
					NotifyAll('d');
					break;
				case 's': case 'S':
					NotifyAll('s');
					break;
			}
			break;
		case osgGA::GUIEventAdapter::KEYUP:
			NotifyAll('0');
			break;
	}
	return false;
}


void Controller::AddObserver(Observer *observer) {
	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
	if (it == this->observers.end())
		this->observers.push_back(observer);
}


void Controller::RemoveObserver(Observer *observer) {
	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
	if (it != this->observers.end())
		this->observers.erase(it);
}


void Controller::NotifyAll(char event) {
	for (auto observer = this->observers.begin(); observer != this->observers.end(); observer++)
		(*observer)->Observe(event);
}










