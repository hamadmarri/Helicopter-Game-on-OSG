//
//  GameController.cpp
//
//	See main.cpp file header for credits
//
//
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
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
	
	
	// check if the event is key down
	// and based on the key pressed by user,
	// will add proper command to the invoker to
	// be executed at the end of the function
	if (e == osgGA::GUIEventAdapter::KEYDOWN) {
		
		// if move forward key pressed and mouse control disabled
		if (k == this->game->getConfiguration()->getKeySettings().movingForward && !this->game->getConfiguration()->isMouseControl())
			this->commandsInvoker.addCommand(new JoystickMoveForward(this->helicopter->getJoystick()));
		
		// if move right key pressed and mouse control disabled
		if (k == this->game->getConfiguration()->getKeySettings().movingRight && !this->game->getConfiguration()->isMouseControl())
			this->commandsInvoker.addCommand(new JoystickMoveRight(this->helicopter->getJoystick()));
		
		// if move left key pressed and mouse control disabled
		if (k == this->game->getConfiguration()->getKeySettings().movingLeft && !this->game->getConfiguration()->isMouseControl())
			this->commandsInvoker.addCommand(new JoystickMoveLeft(this->helicopter->getJoystick()));
		
		// if move backward key pressed and mouse control disabled
		if (k == this->game->getConfiguration()->getKeySettings().movingBackward && !this->game->getConfiguration()->isMouseControl())
			this->commandsInvoker.addCommand(new JoystickMoveBackward(this->helicopter->getJoystick()));
			
		// if rotate left key pressed
        if (k == this->game->getConfiguration()->getKeySettings().rotateLeft)
			this->commandsInvoker.addCommand(new RotorIncrease(this->helicopter->getTailRotor()));
		
		// if rotate right key pressed
		if (k == this->game->getConfiguration()->getKeySettings().rotateRight)
			this->commandsInvoker.addCommand(new RotorDecrease(this->helicopter->getTailRotor()));
		
        // if reset joystick key pressed
        if (k == this->game->getConfiguration()->getKeySettings().resetJoystick)
			this->commandsInvoker.addCommand(new JoystickCenter(this->helicopter->getJoystick()));
        
		// if make rotor speed zero key pressed
        if (k == this->game->getConfiguration()->getKeySettings().zeroRotorSpeed)
			this->commandsInvoker.addCommand(new RotorSwitchOff(this->helicopter->getMainRotor()));
        
		// if decrease rotor speed key pressed
		if (k == this->game->getConfiguration()->getKeySettings().decreaseRotorSpeed)
			this->commandsInvoker.addCommand(new RotorDecrease(this->helicopter->getMainRotor()));
        
		// if increase rotor speed key pressed
        if (k == this->game->getConfiguration()->getKeySettings().increaseRotorSpeed)
			this->commandsInvoker.addCommand(new RotorIncrease(this->helicopter->getMainRotor()));
        
		// if make rotor speed neutral key pressed
        if (k == this->game->getConfiguration()->getKeySettings().neutralRotorMode)
			this->commandsInvoker.addCommand(new RotorNeutral(this->helicopter->getMainRotor()));
		
		// if fire key pressed
		if (k == this->game->getConfiguration()->getKeySettings().fire)
			this->commandsInvoker.addCommand(new FireCommand(this->helicopter));
		
		// if increment missile's inclination angle key pressed
		if (k == this->game->getConfiguration()->getKeySettings().incrementInclinationAngle)
			this->commandsInvoker.addCommand(new MissileCommand(this->helicopter->getMissile(),
																MissileCommandType::INCREMENT_INCLINATION_ANGLE));
		
		// if decrement missile's inclination angle key pressed
		if (k == this->game->getConfiguration()->getKeySettings().decrementInclinationAngle)
			this->commandsInvoker.addCommand(new MissileCommand(this->helicopter->getMissile(),
																MissileCommandType::DECREMENT_INCLINATION_ANGLE));
		
		// if increment missile's initial speed key pressed
		if (k == this->game->getConfiguration()->getKeySettings().incrementMissileInitialSpeed)
			this->commandsInvoker.addCommand(new MissileCommand(this->helicopter->getMissile(),
																MissileCommandType::INCREMENT_INITIAL_SPEED));
		
		// if decrement missile's initial speed key pressed
		if (k == this->game->getConfiguration()->getKeySettings().decrementMissileInitialSpeed)
			this->commandsInvoker.addCommand(new MissileCommand(this->helicopter->getMissile(),
																MissileCommandType::DECREMENT_INITIAL_SPEED));
		
		// if enable friction key pressed
		if (k == this->game->getConfiguration()->getKeySettings().frictionEnable)
			this->commandsInvoker.addCommand(new ActivateFrictionCommand(this->game));
		
		// if disable friction key pressed
		if (k == this->game->getConfiguration()->getKeySettings().frictionDisable)
			this->commandsInvoker.addCommand(new DeactivateFrictionCommand(this->game));
		
		// if startLogging
		if (k == this->game->getConfiguration()->getKeySettings().startLogging && !this->game->getLogger()->isLoggingEnabled())
			this->commandsInvoker.addCommand(new StartLoggingCommand(this->game));
		
		// if stopLogging
		if (k == this->game->getConfiguration()->getKeySettings().stopLogging && this->game->getLogger()->isLoggingEnabled())
			this->commandsInvoker.addCommand(new StopLoggingCommand(this->game));
		
		// if update key settings key pressed
		if (k == this->game->getConfiguration()->getKeySettings().updateKeySettings)
			this->commandsInvoker.addCommand(new UpdateKeySettingsCommand(this->game));

		// if show pop up help screen key pressed
		if (k == this->game->getConfiguration()->getKeySettings().showPopupHelpScreen)
			this->commandsInvoker.addCommand(new ShowHelpScreenCommand(this->game));
		
		// if hide pop up help screen key pressed
		if (k == this->game->getConfiguration()->getKeySettings().hidePopupHelpScreen)
			this->commandsInvoker.addCommand(new HideHelpScreenCommand(this->game));
	}
	
	
	// Detect a mouse movement
	if (e == osgGA::GUIEventAdapter::MOVE && this->game->getConfiguration()->isMouseControl()) {
		this->commandsInvoker.addCommand(new JoystickMouseMovement(this->game, this->helicopter->getJoystick(), ea.getX(), ea.getY()));
	}
    
	
	// execute all commands on queue
	this->commandsInvoker.executeAll();
	
	
	// if return true, mouse cannot change camera position
    return false;
}




