/*
	TimerHandler
		Handles the actions that need to be done on each frame
		Gets mouse coords and sends them to the force redirection function
		Calls updateGamePlay to calculate the physics and move the helicopter


			
		Credits: Karlee Stein, Trevor Douglas (using lab code)

*/

#ifndef TIMERHANDLER_H
#define TIMERHANDLER_H
#include <osgGA/GUIEventHandler>
#include "Render.h"

class TimerHandler : public osgGA::GUIEventHandler
{
public:
	TimerHandler(Render * render) : gameRender(render), _count(0) {}
	//TimerHandler() : _count(0){}


	virtual bool handle( const osgGA::GUIEventAdapter& ea,
		                       osgGA::GUIActionAdapter& aa );

	Render * gameRender;
protected:
	
	unsigned int _count;
};

#endif
