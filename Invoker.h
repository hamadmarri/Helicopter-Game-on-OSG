//
//	Invoker is a class that is responsible for
//	adding/removing/executing commands objects
//	commands are added in queue, so execute all will
//	execute them one by one in FIFO way
//
//	pattern:	command
//	See main.cpp file header for credits
//
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
//

#ifndef __HelicopterProject__Invoker_h__
#define __HelicopterProject__Invoker_h__

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
	 Adding a command to the queue and execute.
	 
	 Notice here that not necessarily this command
	 will be executed in this call, since it will
	 be pushed to the end of the queue and the execution 
	 will be for the very early command that has been pushed.
	 
	 This command will be executed only and only if
	 the queue was empty before adding this command,
	 otherwise, it will wait in the queue until its turn comes.
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


#endif
