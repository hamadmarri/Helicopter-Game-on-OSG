//
//  main.cpp
//
//	Credits:
//				Authors:			Fares Alotaibi, Hamad Almarri
//				Incorporated code from heli-alternate project by Krim Naqvi
//				Models:				http://scenemodels.flightgear.org/objectview.php?id=3303278
//									http://scenemodels.flightgear.org/modelview.php?id=320
//				RK4:				http://gafferongames.com/game-physics/integration-basics/
//				Original authors:	Brian Schweitzer, Karlee Stein, Tylor Froese, Trevor Douglas
//


#include <iostream>
#include <string>
#include "Game.h"
#include "tests/RealTimeTest.h"
#include "tests/SimulatorTest.h"



bool isAskForHelp(int argc, char** argv) {
	for (int i = 1; i < argc; i++)
		if (strcmp(argv[1], "--help") == 0)
			return true;

	return false;
}



std::string parseArgs(int &argc, char** argv, std::string command) {
	std::string value;
	osg::ArgumentParser args(&argc, argv);
	args.read(command, value );
	return value;
}



int startProgram(int argc, char** argv) {
	// game object
	Game game;
	
	// to hold singe command at a time
	std::string command = "";
	
	
	if (isAskForHelp(argc, argv)) {
		
		// Print help screen
		std::cout << "--log: followed by log file name" << std::endl;
		std::cout << "--script: followed by script file name" << std::endl;
		std::cout << "--test: followed by r for real time test or s for simulator test" << std::endl;
		
		return 0;
	}
	
	
	// check log first
	if (!(command = parseArgs(argc, argv, "--log")).empty())
		// initialize game with given log file name
		game.initialize(command);
	else
		// initialize game normally with defaults
		game.initialize();
	
	
	// check if script
	if (!(command = parseArgs(argc, argv, "--script")).empty())
		game.run(command.c_str());
	else if ( (command = parseArgs(argc, argv, "--test")) == "r") {
		RealTimeTest realTimeTest;
		realTimeTest.run();
	} else if (command == "s") {
		SimulatorTest simulatorTest;
		simulatorTest.run();
	} else
		game.run();
	
	return 0;
}



int main(int argc, char** argv) {
	return startProgram(argc, argv);
}




