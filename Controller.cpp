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
//					this->joyStick.set_theta(45.0);
//					this->joyStick.set_phi(90.0);
					break;
				case 'w': case 'W':
					NotifyAll('w');
//					this->joyStick.set_theta(45.0);
//					this->joyStick.set_phi(0.0);
					break;
				case 'd': case 'D':
					NotifyAll('d');
//					this->joyStick.set_theta(45.0);
//					this->joyStick.set_phi(270);
					break;
				case 's': case 'S':
					NotifyAll('s');
//					this->joyStick.set_theta(45.0);
//					this->joyStick.set_phi(180.0);
					break;
			}
			break;
		case osgGA::GUIEventAdapter::KEYUP:
			NotifyAll('0');
//			this->joyStick.set_theta(0.0);
//			this->joyStick.set_phi(0.0);
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










