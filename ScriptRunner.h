//
//  ScriptRunner.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-25.
//
//  ScriptRunner that will read from a file. 

#ifndef testOsg_ScriptRunner_h
#define testOsg_ScriptRunner_h
#include <fstream>
#include <string>
#include <osg/Notify>
#include "Invoker.h"
#include "AllCommands.h"
#include "Helicopter.h"

class ScriptRunner {
public:
    ScriptRunner(const char *fileName, Helicopter *helicopter);
	
	~ScriptRunner();
	
	void Run();
    
    
private:
    void parse_set_joystick();
	void parse_throttle();
	void parse_delay();
	
	Invoker commands;
	std::ifstream inFile;
	Helicopter *helicopter;
    
};


#endif
