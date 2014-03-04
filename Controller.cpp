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
					this->joyStick.set_theta(45.0);
					this->joyStick.set_phi(90.0);
					break;
				case 'w': case 'W':
					this->joyStick.set_theta(45.0);
					this->joyStick.set_phi(0.0);
					break;
				case 'd': case 'D':
					this->joyStick.set_theta(45.0);
					this->joyStick.set_phi(270);
					break;
				case 's': case 'S':
					this->joyStick.set_theta(45.0);
					this->joyStick.set_phi(180.0);
					break;
			}
			break;
		case osgGA::GUIEventAdapter::KEYUP:
			this->joyStick.set_theta(0.0);
			this->joyStick.set_phi(0.0);
			break;
	}
	
	game->joyStick = this->joyStick;

	return false;
}









