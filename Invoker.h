
#ifndef __HelicopterProject__Invoker__
#define __HelicopterProject__Invoker__

#include <queue>
#include "Command.h"

class Invoker {
public:
	
	/*
	 constructor
	 */
	Invoker();
	
	
	
	/*
	 deconstructor
	 */
	~Invoker();
	
	
	/*
	 adding a command to the queue
	 */
	void addCommand(Command *cmd);
	
	
	/*
	 adding a command to the queue and execute it
	 */
	bool addAndExecuteCommand(Command *cmd);
	
	
	/*
	 execute one command only that at top of the queue 
	 and remove it from queue
	 
	 return:	if executing a command is failed,
				then returns false
	 */
	bool execute();
	
	
	
	/*
	 execute all commands in queue
	 
	 return:	if executing a command is failed,
	 then returns false
	 */
	bool executeAll();
	
	
	
private:
	std::queue <Command*> commands;
	
};


#endif /* defined(__HelicopterProject__Invoker__) */
