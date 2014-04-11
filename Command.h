//	See main.cpp file header for credits

#ifndef __HelicopterProject_Command_h__
#define __HelicopterProject_Command_h__

class Command {
public:
	virtual ~Command() { };
	virtual bool execute() = 0;
};


#endif
