//
//  main.cpp
//
//  Created by Hamad Almarri on 3/2/2014.
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
	
//	SimulatorTest t;
//	
//	t.run();
	
	Game game;
	
	game.initialize();
//	game.run(parseArgs(argc, argv, "--script").c_str());
	game.run();
	

	
	return 0;
}