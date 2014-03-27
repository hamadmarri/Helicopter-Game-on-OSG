//
//  HelicopterController.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-26.
//
//

#include "HelicopterController.h"


HelicopterController::HelicopterController(Helicopter *helicopter) {
	this->helicopter = helicopter;
}

bool HelicopterController::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	
	// e for event type
	auto e = ea.getEventType();
	
	// k for key
	auto k = tolower(ea.getKey());
	
	if (e == osgGA::GUIEventAdapter::KEYDOWN) {
        if (k == osgGA::GUIEventAdapter::KEY_Left)
			this->commandsInvoker.addCommand(new JoystickMoveLeft(this->helicopter->getJoystick()));
		
        else if (k == osgGA::GUIEventAdapter::KEY_Up)
			this->commandsInvoker.addCommand(new JoystickMoveForward(this->helicopter->getJoystick()));
        
        else if (k == osgGA::GUIEventAdapter::KEY_Right)
			this->commandsInvoker.addCommand(new JoystickMoveRight(this->helicopter->getJoystick()));
        
        else if (k == osgGA::GUIEventAdapter::KEY_Down)
			this->commandsInvoker.addCommand(new JoystickMoveBackward(this->helicopter->getJoystick()));
        
        else if (k == Configuration::getInstance()->getKeySettings().resetJoystick)
			this->commandsInvoker.addCommand(new JoystickCenter(this->helicopter->getJoystick()));
        
        else if (k == Configuration::getInstance()->getKeySettings().zeroRotorSpeed)
			this->commandsInvoker.addCommand(new RotorSwitchOff(this->helicopter->getRotor()));
        
        else if (k == Configuration::getInstance()->getKeySettings().decreaseRotorSpeed)
			this->commandsInvoker.addCommand(new RotorDecrease(this->helicopter->getRotor()));
        
        else if (k == Configuration::getInstance()->getKeySettings().increaseRotorSpeed)
			this->commandsInvoker.addCommand(new RotorIncrease(this->helicopter->getRotor()));
        
        else if (k == Configuration::getInstance()->getKeySettings().neutralRotorMode)
			this->commandsInvoker.addCommand(new RotorNeutral(this->helicopter->getRotor()));
		
		this->commandsInvoker.executeAll();
	}
	else if (e == osgGA::GUIEventAdapter::KEYUP) {
		this->commandsInvoker.addCommand(new JoystickCenter(this->helicopter->getJoystick()));
		this->commandsInvoker.executeAll();
	}
	//Detect a mouse movement
	else if ( e == osgGA::GUIEventAdapter::MOVE) {
		this->commandsInvoker.addCommand(new JoystickMouseMovement(this->helicopter->getJoystick(), ea.getX(), ea.getY()));
		this->commandsInvoker.executeAll();
	}
    
	
    return false;
}