/*
	Command
		Executes the command with the given parameters

		Credits: Tylor Froese, Brian Schwietzer

*/

#include <vector>
#include "Render.h"
#include <osg/Timer>
#include "SleepThread.h"

using namespace std;
#ifndef COMMAND_H
#define COMMAND_H

enum COMMAND_TYPE {set_joystick, delay, centre_joystick,throttle,error};

class Command
{
private:
	COMMAND_TYPE commandName;
	vector<float> params;
	double timeStamp;
	SleepThread * sleepThread;
public:
	Command(COMMAND_TYPE,vector<float>);
	bool executeCommand(Render *);
	bool wait(SleepThread *);
};

#endif
