//
//  main.cpp
//
//	Credits:
//				Authors:			Fares Alotaibi, Hamad Almarri
//				Incorporated code from heli-alternate project by Krim Naqvi
//				Original authors:	Brian Schweitzer, Karlee Stein, Tylor Froese, Trevor Douglas
//


#include <string>
#include "Game.h"
#include "tests/RealTimeTest.h"
#include "tests/SimulatorTest.h"



std::string parseArgs(int argc, char** argv, std::string command) {
	std::string value;
	osg::ArgumentParser args(&argc, argv);
	args.read(command, value );
	return value;
}



int main(int argc, char** argv) {
	
	// game object
	Game game;
	
	// to hold singe command at a time
	std::string command = "";
	
	// initialize game
	game.initialize();
	
	// check for script
	command = parseArgs(argc, argv, "--script");
	
	// check if script
	if (!command.empty())
		game.run(command.c_str());
	else if (parseArgs(argc, argv, "--test") == "r") {
		RealTimeTest realTimeTest;
		realTimeTest.run();
	} else if (parseArgs(argc, argv, "--test") == "s") {
		SimulatorTest simulatorTest;
		simulatorTest.run();
	}

	else
		game.run();
	

	
	return 0;
}