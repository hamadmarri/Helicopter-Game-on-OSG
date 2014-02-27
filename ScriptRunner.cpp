/*
	ScriptRunner
		Parses the script given through an istream and creates a list of actions to execute.
		Also tells the command to execute itself

		Credits: Tylor Froese, Brian Schwietzer

*/

#include "ScriptRunner.h"
#include "Command.h"
#include "Render.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "SleepThread.h"

using namespace std;

ScriptRunner::ScriptRunner(void)
{
	isRunning = false;
}

void ScriptRunner::setRender(Render * render)
{
	gameRender = render;
}

void ScriptRunner::setActions(vector<Command> newActions)
{
	actions = newActions;
}

vector<Command> ScriptRunner::parseScript(ifstream & script)
{
	bool endFound = false;
	vector<Command> actionList;
	while(!endFound)
	{
		if(script.is_open())
		{
			vector<float> params;
			string input;
			getline(script,input);
			if(input.empty() ||input[0] == '#' ) continue;
			string commandName = input.substr(0,input.find_first_of(" "));
			if(commandName == "end")
			{
				endFound = true;
				cout << "finished reading file\n";
				break;
			}
			input = input.substr(input.find_first_of(" ") +1,input.length());
			while(input.length() > 0)
			{
				if(input[0] == '#') break;
				int spaceloc = input.find_first_of(" \n");
				string param = input.substr(0,(spaceloc>=0)?spaceloc:input.length());
				if(spaceloc == -1)
						input = "";
				else
					input = input.substr(spaceloc+1,input.length());
				char * charParam = new char[param.size()+1];
				strcpy(charParam,param.c_str());
				float parameter = (float)atof(charParam);
				params.push_back(parameter);
			}
			COMMAND_TYPE commandType = error;
			if(commandName == "set_joystick")
			{
				commandType = set_joystick;
			}
			else if(commandName == "delay")
			{
				commandType = delay;
			}
			else if(commandName == "centre_joystick")
			{
				commandType = centre_joystick;
			}
			else if(commandName == "throttle")
			{
				commandType = throttle;
			}
			if(commandType != error)
			{
				Command command = Command(commandType,params);
				actionList.push_back(command);
			}
		}
	}
	return actionList;
}

void ScriptRunner::runScripts()
{
	for each(Command c in actions)
	{
		cactions.push_back(c);
	}
	isRunning = true;
	doCommand();
}

void ScriptRunner::doCommand()
{
	if(cactions.size() >0){
		bool erase = cactions.front().executeCommand(gameRender);
		if(erase)
		{
			cactions.erase(cactions.begin());
		}
	} else {
		isRunning = false;
	}
}

bool ScriptRunner::getStatus()
{
	return isRunning;
}

ScriptRunner::~ScriptRunner(void)
{
}