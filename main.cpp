//
//  main.cpp
//
//	Credits:
//				Authors:			Fares Alotaibi, Hamad Almarri
//				Incorporated code from heli-alternate project by Krim Naqvi
//				Original authors:	Brian Schweitzer, Karlee Stein, Tylor Froese, Trevor Douglas
//


#include <iostream>
#include <string>
#include "Game.h"
#include "tests/RealTimeTest.h"
#include "tests/SimulatorTest.h"





bool askForHelp(int argc, char** argv) {
	std::string helpStr = "--help";
	
	for (int i = 1; i < argc; i++)
		if (argv[i] == helpStr.c_str())
			return true;

	return false;
}



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
	
	
	if (askForHelp(argc, argv)) {
		// Print help screen
		
		return 0;
	}
	
	
	// initialize game
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
//	else if ()
	} else
		game.run();
	

	
	return 0;
}




