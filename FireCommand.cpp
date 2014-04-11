
#include "FireCommand.h"


FireCommand::FireCommand(Helicopter *helicopter) {
	this->helicopter = helicopter;
}



bool FireCommand::execute() {
	this->helicopter->fire();
	return true;
}

