//
//  ScriptRunner.cpp
//
//	See main.cpp file header for credits
//
// 

#include "ScriptRunner.h"

ScriptRunner::ScriptRunner(const char *fileName, Helicopter *helicopter) {
	this->inFile.open(fileName);
	if (!this->inFile.is_open()) {
		osg::notify(osg::WARN) << "ScriptRunner: Invalid file name '" << fileName << "'" << std::endl;
	}
	
	this->helicopter = helicopter;
}



ScriptRunner::~ScriptRunner() {
	if (this->inFile.is_open())
		this->inFile.close();
}


void ScriptRunner::Run() {
	std::string word = "";
	
	// prime reading
	this->inFile >> word;
	
	while (this->inFile || word != "end") {
		// check if comment
		if (word[0] == '#') {
			this->inFile.ignore(500, '\n');
		}
		else if (word == "set_joystick") {
			parse_set_joystick();
		}
		else if (word == "centre_joystick") {
			this->commands.addCommand(new JoystickCenter(this->helicopter->getJoystick()));
		}
		else if (word == "throttle") {
			parse_throttle();
		}
		else if (word == "delay") {
			parse_delay();
		}
		
		// next reading
		this->inFile >> word;
	} // end while
	
	
	// execute all commands
	commands.executeAll();
}


void ScriptRunner::parse_set_joystick() {
	std::string word;
	float theta, bearing;
	
	// read theta
	this->inFile >> word;
	
	// ignore "theta=" part
	word = word.substr(std::string("theta=").length());
	theta = atof(word.c_str());
	
	// read bearing
	this->inFile >> word;
	
	// ignore "bearing=" part
	word = word.substr(std::string("bearing=").length());
	bearing = -1 * atof(word.c_str());
	
	this->commands.addCommand(new JoyStickSetManually(this->helicopter->getJoystick(), theta, bearing));
}




void ScriptRunner::parse_throttle() {
	std::string word;
	float percentage;
	
	// read position
	this->inFile >> word;
	
	// ignore "position=" part
	word = word.substr(std::string("position=").length());
	
	percentage = atof(word.c_str());
	
	this->commands.addCommand(new RotorPercentage(this->helicopter->getMainRotor(), percentage));
}



void ScriptRunner::parse_delay() {
	std::string word;
	float seconds;
	
	// read seconds
	this->inFile >> word;
	
	// ignore "seconds=" part
	word = word.substr(std::string("seconds=").length());
	
	seconds = atof(word.c_str());
	
	this->commands.addCommand(new DelayCommand(seconds));
}

