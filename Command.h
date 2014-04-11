//
//	Command is abstract class or interface that used for command pattern
//	the main functionallity is execute(), which is need to be implemented
//	by concrete classes
//
//	pattern:	command
//	See main.cpp file header for credits

#ifndef __HelicopterProject_Command_h__
#define __HelicopterProject_Command_h__

class Command {
public:
	virtual ~Command() { };
	virtual bool execute() = 0;
};


#endif
