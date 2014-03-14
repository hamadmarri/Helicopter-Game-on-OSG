//
//  Controller.cpp
//
//  Created by Hamad Almarri on 3/3/2014.
//
// Edited and Modified by Alotaibi, Fares on 3/9/2014


#include "Controller.h"

bool Controller::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	
	// e for event type
	auto e = ea.getEventType();
	
	// k for key 
	auto k = tolower(ea.getKey());
	
	if (e == osgGA::GUIEventAdapter::KEYDOWN) {
        if (k == osgGA::GUIEventAdapter::KEY_Left)
            NotifyAll(Event(EventType::MOVE_LEFT));
		
        else if (k == osgGA::GUIEventAdapter::KEY_Up)
            NotifyAll(Event(EventType::MOVE_FORWARD));
        
        else if (k == osgGA::GUIEventAdapter::KEY_Right)
            NotifyAll(Event(EventType::MOVE_RIGHT));
        
        else if (k == osgGA::GUIEventAdapter::KEY_Down)
            NotifyAll(Event(EventType::MOVE_BACKWARD));
        
        else if (k == Configuration::getInstance()->getKeySettings().resetJoystick)
            NotifyAll(Event(EventType::CENTER));
        
        else if (k == Configuration::getInstance()->getKeySettings().zeroRotorSpeed)
            NotifyAll(Event(EventType::SWITCH_OFF));
        
        else if (k == Configuration::getInstance()->getKeySettings().decreaseRotorSpeed)
            NotifyAll(Event(EventType::DECREASE));
        
        else if (k == Configuration::getInstance()->getKeySettings().increaseRotorSpeed)
            NotifyAll(Event(EventType::INCREASE));
        
        else if (k == Configuration::getInstance()->getKeySettings().neutralRotorMode)
            NotifyAll(Event(EventType::STAY_NEUTRAL));
	}
	else if (e == osgGA::GUIEventAdapter::KEYUP) {
		NotifyAll(Event(EventType::CENTER));
	}
	//Detect a mouse movement
	else if ( e == osgGA::GUIEventAdapter::MOVE) {
		NotifyAll(Event(EventType::MOUSE_MOVEMENT, ea.getX(), ea.getY()));
	}
    
    return false;
}






