/*
	Constants
		A singleton class for storing program constants that various classes need to 
	access.
		Reads attribute file and allows the file to overwrite the constants.
		Also calculates force of friction for use in physics.

		Credits: Tylor Froese, Karlee Stein

*/

#pragma once
#include <iostream>
#include <fstream>
#include "HelicopterConfig.h"
#include "SleepThread.h"

enum ATTR_TYPE {G_ACCEL};

class Constants
{
public:
	
	float gravity;
	float maxThrottle;
	bool mouseDown;
	bool disableMouse;
	bool loggingOn;
	float maxTheta;
	float frictionConstant;
	float baseThrottle;
	HelicopterConfig* helicopter;
	static Constants* getInstance(){
		static Constants *instance = 0;
		if(instance == 0){
			instance = new Constants();
		}
		return instance;
	}
	static void setConstantsFromFile(std::ifstream & infile);
	Constants(void);
	float calculateFrictionConstant(float theta);
	void setFrictionConstant(float theta);
	~Constants(void);

private:
	static Constants* instance;
};

