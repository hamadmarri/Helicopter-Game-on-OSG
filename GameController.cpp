//
//  GameController.cpp
//
//	See main.cpp file header for credits
//
//

#include "GameController.h"


GameController::GameController(Game *game, Helicopter *helicopter) {
	this->game = game;
	this->helicopter = helicopter;
}



bool GameController::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object*, osg::NodeVisitor*) {
	
	// e for event type
	auto e = ea.getEventType();
	
	// k for key
	auto k = tolower(ea.getKey());
	
	if (e == osgGA::GUIEventAdapter::KEYDOWN) {
		
		if (k == this->game->getConfiguration()->getKeySettings().movingForward && !this->game->getConfiguration()->isMouseControl())
			this->commandsInvoker.addCommand(new JoystickMoveForward(this->helicopter->getJoystick()));
		
		if (k == this->game->getConfiguration()->getKeySettings().movingRight && !this->game->getConfiguration()->isMouseControl())
			this->commandsInvoker.addCommand(new JoystickMoveRight(this->helicopter->getJoystick()));
		
		if (k == this->game->getConfiguration()->getKeySettings().movingLeft && !this->game->getConfiguration()->isMouseControl())
			this->commandsInvoker.addCommand(new JoystickMoveLeft(this->helicopter->getJoystick()));
		
		if (k == this->game->getConfiguration()->getKeySettings().movingBackward && !this->game->getConfiguration()->isMouseControl())
			this->commandsInvoker.addCommand(new JoystickMoveBackward(this->helicopter->getJoystick()));
			
        if (k == this->game->getConfiguration()->getKeySettings().rotateLeft)
			this->commandsInvoker.addCommand(new RotorIncrease(this->helicopter->getTailRotor()));
		
		if (k == this->game->getConfiguration()->getKeySettings().rotateRight)
			this->commandsInvoker.addCommand(new RotorDecrease(this->helicopter->getTailRotor()));
		
		if (k == osgGA::GUIEventAdapter::KEY_Up)
			this->commandsInvoker.addCommand(new JoystickMoveForward(this->helicopter->getJoystick()));

        if (k == osgGA::GUIEventAdapter::KEY_Down)
			this->commandsInvoker.addCommand(new JoystickMoveBackward(this->helicopter->getJoystick()));
        
        if (k == this->game->getConfiguration()->getKeySettings().resetJoystick)
			this->commandsInvoker.addCommand(new JoystickCenter(this->helicopter->getJoystick()));
        
        if (k == this->game->getConfiguration()->getKeySettings().zeroRotorSpeed)
			this->commandsInvoker.addCommand(new RotorSwitchOff(this->helicopter->getMainRotor()));
        
		if (k == this->game->getConfiguration()->getKeySettings().decreaseRotorSpeed)
			this->commandsInvoker.addCommand(new RotorDecrease(this->helicopter->getMainRotor()));
        
        if (k == this->game->getConfiguration()->getKeySettings().increaseRotorSpeed)
			this->commandsInvoker.addCommand(new RotorIncrease(this->helicopter->getMainRotor()));
        
        if (k == this->game->getConfiguration()->getKeySettings().neutralRotorMode)
			this->commandsInvoker.addCommand(new RotorNeutral(this->helicopter->getMainRotor()));
		
		if (k == this->game->getConfiguration()->getKeySettings().fire)
			this->helicopter->fire();
		
		if (k == this->game->getConfiguration()->getKeySettings().incrementInclinationAngle)
			this->commandsInvoker.addCommand(new MissileCommand(this->helicopter->getMissile(),
																MissileCommandType::INCREMENT_INCLINATION_ANGLE));
		
		if (k == this->game->getConfiguration()->getKeySettings().decrementInclinationAngle)
			this->commandsInvoker.addCommand(new MissileCommand(this->helicopter->getMissile(),
																MissileCommandType::DECREMENT_INCLINATION_ANGLE));
		
		if (k == this->game->getConfiguration()->getKeySettings().incrementMissileInitialSpeed)
			this->commandsInvoker.addCommand(new MissileCommand(this->helicopter->getMissile(),
																MissileCommandType::INCREMENT_INITIAL_SPEED));
		
		if (k == this->game->getConfiguration()->getKeySettings().decrementMissileInitialSpeed)
			this->commandsInvoker.addCommand(new MissileCommand(this->helicopter->getMissile(),
																MissileCommandType::DECREMENT_INITIAL_SPEED));
		
		if (k == this->game->getConfiguration()->getKeySettings().frictionEnable)
			this->game->getConfiguration()->activateFriction();
		
		if (k == this->game->getConfiguration()->getKeySettings().frictionDisable)
			this->game->getConfiguration()->disactivateFriction();
		
		if (k == this->game->getConfiguration()->getKeySettings().updateKeySettings) {
			this->game->getConfiguration()->initKeySettings();
			game->initializePopupHelpScreen();
			game->initializeCamera();
			delete game->hudsManager;
			game->hudsManager = new HudsManager(game, 0);
			helicopter->initializeHuds();
		}

		if (k == this->game->getConfiguration()->getKeySettings().showPopupHelpScreen)
			game->popupHelpScreen->show();
		
		if (k == this->game->getConfiguration()->getKeySettings().hidePopupHelpScreen)
			game->popupHelpScreen->hide();
	}
	
	if (e == osgGA::GUIEventAdapter::KEYUP) {
//		this->commandsInvoker.addCommand(new JoystickCenter(this->helicopter->getJoystick()));
//		this->commandsInvoker.executeAll();
	}
	
	//Detect a mouse movement
	if (e == osgGA::GUIEventAdapter::MOVE && this->game->getConfiguration()->isMouseControl()) {
		this->commandsInvoker.addCommand(new JoystickMouseMovement(this->game, this->helicopter->getJoystick(), ea.getX(), ea.getY()));
//		this->commandsInvoker.executeAll();
	}
    
	this->commandsInvoker.executeAll();
	
    return false;
}