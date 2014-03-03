/*
	Constants
		A singleton class for storing program constants that various classes need to 
	access.
		Reads attribute file and allows the file to overwrite the constants.
		Also calculates force of friction for use in physics.

		Credits: Tylor Froese, Karlee Stein

*/
#include "Constants.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <osg/PositionAttitudeTransform>

	Constants::Constants(void)
	{
		this->gravity = (float)9.81;
		this->helicopter = new HelicopterConfig();
		this->maxThrottle = 23;
		this->mouseDown = false;
		this->maxTheta = 15;
		this->frictionConstant = calculateFrictionConstant(maxTheta);
		this->baseThrottle = helicopter->mass*gravity/10;
		this->disableMouse = false;
		this->loggingOn = false;
	}

	void Constants::setConstantsFromFile(std::ifstream & infile)
	{
		if(infile.is_open())
		{
			std::string input;
			while(std::getline(infile,input))
			{
				std::vector<float> params;
				if(input[0] == '#') continue;
				std::string commandName = input.substr(0,input.find_first_of(" "));

				input = input.substr(input.find_first_of(" ")+1,input.length());
				while(input.length() > 0)
				{
					int spaceloc = input.find_first_of(" \n\0");
					std::string param = input.substr(0,(spaceloc>=0)?spaceloc:input.length());
					if(input[0] == '#') ;
					if(spaceloc == -1)
						input = "";
					else
						input = input.substr(spaceloc+1,input.length());
					char * charParam = new char[input.size()+1];
					strcpy(charParam,param.c_str());
					float parameter = (float)atof(charParam);
					params.push_back(parameter);
				}
			
				if(commandName == "G_ACCEL")
				{
					Constants::getInstance()->gravity = params[0];
				}
			}
		}
	}

	float Constants::calculateFrictionConstant(float theta)
	{
		return (helicopter->mass*gravity*tan(osg::DegreesToRadians(theta)))/pow(helicopter->maxAirspeed, 2);
	}

	Constants::~Constants(void)
	{
	}
