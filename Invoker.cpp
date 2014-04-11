//	See main.cpp file header for credits
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
//

#include "Invoker.h"



Invoker::Invoker() {
	
}



Invoker::~Invoker() {
	// clear the queue if not empty
	while (!this->commands.empty()) {
		delete this->commands.front();
		this->commands.pop();
	}
}



void Invoker::addCommand(Command *cmd) {
	// push to the queue
	this->commands.push(cmd);
}



bool Invoker::addAndExecuteCommand(Command *cmd) {
	addCommand(cmd);
	return execute();
}



bool Invoker::execute() {
	
	// get command from queue's top
	Command *cmd = this->commands.front();
	
	// executed
	if (!cmd->execute())
		return false;
	
	// delete it
	delete cmd;
	
	// pop its pointer from queue
	this->commands.pop();
	
	return true;
}



bool Invoker::executeAll() {
	while (!this->commands.empty()) {
		if(!execute())
			return false;
	}
	
	return true;
}





