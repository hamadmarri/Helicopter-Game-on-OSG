//	See main.cpp file header for credits


#include "Invoker.h"



Invoker::Invoker() {
	
}



Invoker::~Invoker() {
	while (!this->commands.empty()) {
		delete this->commands.front();
		this->commands.pop();
	}
}



void Invoker::addCommand(Command *cmd) {
	this->commands.push(cmd);
}



bool Invoker::addAndExecuteCommand(Command *cmd) {
	addCommand(cmd);
	return execute();
}



bool Invoker::execute() {
	Command *cmd = this->commands.front();
	
	if (!cmd->execute())
		return false;
	
	delete cmd;
	
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





