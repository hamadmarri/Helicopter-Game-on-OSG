//
//  ScriptRunner.h
//
//	See main.cpp file header for credits
//
//  ScriptRunner class that will read from a file some instruction  and pass it to a Helicopter class. Then,
// depends on the instructions read from the file, the helicopter will set the joystick, throttle.Also, parse
// a delay.

#ifndef __HelicopterProject__ScriptRunner_h__
#define __HelicopterProject__ScriptRunner_h__
#include <fstream>
#include <string>
#include <osg/Notify>
#include "Invoker.h"
#include "AllCommands.h"
#include "Helicopter.h"

class ScriptRunner {
public:
    
    ScriptRunner(const char *fileName, Helicopter *helicopter);   // constructor passing ifstream pointer and a pointer of Helicopter
	
	~ScriptRunner();  // deconstructor
	
	void Run();      // run the script
    
    
private:
                    // private member functions that will do the work for
    void parse_set_joystick();
	void parse_throttle();
	void parse_delay();
                    // three parameters Inovker, ifstream, and Helicopter
	Invoker commands;
	std::ifstream inFile;
	Helicopter *helicopter;
    
};


#endif
