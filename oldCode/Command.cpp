/*
	Command
		Executes the command with the given parameters

		Credits: Tylor Froese, Brian Schwietzer

*/

#include "Command.h"
#include "Render.h"
#include <vector>
#include <iostream>
#include "SleepThread.h"

Command::Command(COMMAND_TYPE command, vector<float> parameters)
{
	commandName = command;
	params = parameters;
	timeStamp = 0;
	sleepThread = NULL;
}

bool Command::executeCommand(Render * render)
{
	bool done = false;
	switch(commandName)
	{
	case set_joystick:
		cout << printf("setting joystick to %f degrees, %f degrees\n", params[0],params[1]);
		render->setJoystick(params[0],params[1]);
		return true;
		break;
	case centre_joystick:
		cout << "centering the joystick\n";
		render->setJoystick(0,0);
		return true;
		break;
	case throttle:
		cout << "setting the throttle to" << params[0] << endl;
		render->setThrottle(params[0]);
		return true;
		break;
	case error:
		return true;
		break;
	case delay:
		if(sleepThread == NULL) {
			sleepThread = new SleepThread(params[0]);
			sleepThread->start();
		}
		done = wait(sleepThread);
		return done;
		break;
	}
}

bool Command::wait(SleepThread * sleepThread)
{
	if(sleepThread->isRunning())
	{
		return false;
	}
	delete sleepThread;
	return true;
}
