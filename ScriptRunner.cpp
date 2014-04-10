//
//  ScriptRunner.cpp
//
//	See main.cpp file header for credits
//
//  This is an implementation of ScriptRunner class that will read from a file and check if there is set_joystick,centre_joystick, throttle, delay. If these words have been detected, then we process the next word
// beside it and set it to the class related to it, and so one.

#include "ScriptRunner.h"

// in the constructor , it will read the passing argument of char, and open that file, if it fails, then display message.
// also setting our instance of helicopter to the passing argument of Helicopter
ScriptRunner::ScriptRunner(const char *fileName, Helicopter *helicopter) {
	this->inFile.open(fileName);
	if (!this->inFile.is_open()) {
		osg::notify(osg::WARN) << "ScriptRunner: Invalid file name '" << fileName << "'" << std::endl;
	}
	
	this->helicopter = helicopter;   // set our instance to the passing arguments of *helicopter
}


// the deconstructor will close the file we have open
ScriptRunner::~ScriptRunner() {
	if (this->inFile.is_open())
		this->inFile.close();
}

// run() funciton will do the hall work from reading the instructions and pass
void ScriptRunner::Run() {
	std::string word = "";
	
	// prime reading
	this->inFile >> word;
	
	while (this->inFile || word != "end") {
		// check if comment has been written from the file
		if (word[0] == '#') {
			this->inFile.ignore(500, '\n');
		}
        // check if set_joystick has been read from the file
		else if (word == "set_joystick") {
			parse_set_joystick();
		}
        // check if centre_joystick has been read from the file
		else if (word == "centre_joystick") {
			this->commands.addCommand(new JoystickCenter(this->helicopter->getJoystick()));
		}
        // check if throttle has been read from the file
		else if (word == "throttle") {
			parse_throttle();
		}
        // check if delay instrciton has been read from the file
		else if (word == "delay") {
			parse_delay();
		}
		
		// next reading
		this->inFile >> word;
	} // end while
	
	
	// execute all commands
	commands.executeAll();
}

// parse_set_joystick function to set the theta and bearing, once the function called, then we know that we have found
// set_joystick in the file. Then we process the next word beside it to set theta and bearing.
void ScriptRunner::parse_set_joystick() {
	std::string word;
	float theta, bearing;
	
	// read theta
	this->inFile >> word;
	
	// ignore "theta=" part
	word = word.substr(std::string("theta=").length());
    // then we save the value in theta
	theta = atof(word.c_str());
	
	// read bearing
	this->inFile >> word;
	
	// ignore "bearing=" part
	word = word.substr(std::string("bearing=").length());
    // then we take the value and store it in bearing
	bearing = -1 * atof(word.c_str());
	// after that we pass it to the commands that will pass it to the helicopter and set theta and bearing to joystick
	this->commands.addCommand(new JoyStickSetManually(this->helicopter->getJoystick(), theta, bearing));
}



// parse_throttle function to read the position written in the file. Once the function has called , then we know that
// throttle has been read from the file. Then we continue reading the next word beside it to set the position.
void ScriptRunner::parse_throttle() {
	std::string word;
	float percentage;
	
	// read position
	this->inFile >> word;
	
	// ignore "position=" part
	word = word.substr(std::string("position=").length());
	
	percentage = atof(word.c_str());
	//
	this->commands.addCommand(new RotorPercentage(this->helicopter->getMainRotor(), percentage));
}


// pars_delay function to set the seconds. Once the function has been called , then we know that we found
// delay word in the file. The main purpose of this function to set the seconds beside that written in the file
// beside the delay and set the seconds.

void ScriptRunner::parse_delay() {
	std::string word;
	float seconds;
	
	// read seconds
	this->inFile >> word;
	
	// ignore "seconds=" part
	word = word.substr(std::string("seconds=").length());
	// store it in seconds now
	seconds = atof(word.c_str());
	// after that pass the value to the commands that will pass it to DelayCommand class ans set the seconds.
	this->commands.addCommand(new DelayCommand(seconds));
}

