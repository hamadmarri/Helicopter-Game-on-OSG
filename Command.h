//	See main.cpp file header for credits

#ifndef HelicopterProject_Command_h
#define HelicopterProject_Command_h

class Command {
public:
	virtual ~Command() { };
	virtual bool execute() = 0;
};


#endif
