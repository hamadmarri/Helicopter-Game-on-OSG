/*
	TimerHandler
		Handles the actions that need to be done on each frame
		Gets mouse coords and sends them to the force redirection function
		Calls updateGamePlay to calculate the physics and move the helicopter


			
		Credits: Karlee Stein, Trevor Douglas (using lab code)

*/

#include "TimerHandler.h"
#include "ScriptRunner.h"

bool TimerHandler::handle( const osgGA::GUIEventAdapter& ea,
		                       osgGA::GUIActionAdapter& aa )
{
	
	switch ( ea.getEventType())
	{
	case osgGA::GUIEventAdapter::FRAME:
		//std::cout << "MouseButton mask: " << ea.getButtonMask() << std::endl;
		if(ea.getButtonMask() == 0)
			Constants::getInstance()->mouseDown = false;
		else if (ea.getButtonMask() == 1)
			Constants::getInstance()->mouseDown = true;
		float x = ea.getX();
		float y = ea.getY();
		//std::cout << "X:  " << x << std::endl;
		//std::cout << "Y:  " << y << std::endl;
		if(Constants::getInstance()->mouseDown == false || Constants::getInstance()->disableMouse == false || ScriptRunner::getInstance()->isRunning == false) gameRender->updateDirection(x, y);
		gameRender->updateGamePlay();
		_count++;
		break;
	}

	return false;



}
