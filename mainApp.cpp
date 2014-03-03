/*
	mainApp
		Lab code runner with our function in it

		Credits: Trevor Douglas (using lab code)

*/


/// ldjfhglkjdhlgkjdfhlgsdjk


#include "Render.h"
#include "Logger.h"
#include <osg/ArgumentParser>
#include <iostream>
#include <fstream>
#include "Constants.h"
#include "ScriptRunner.h"
#include <OpenThreads\Thread>

int main(int argc, char** argv)
{
	Render render;
	ScriptRunner * sr = ScriptRunner::getInstance();
	Logger * logger = Logger::getInstance();
	osg::ArgumentParser parser = osg::ArgumentParser(&argc, argv);
	if(parser.containsOptions()){
		int sLoc = parser.find("-s");
		int aLoc = parser.find("-a");
		int lLoc = parser.find("-l");
		if(sLoc > 0){
			if(parser.isString(sLoc+1)){
				std::ifstream infile;
				infile.open(parser[sLoc+1]);
				sr->setActions(sr->parseScript(infile));
				std::cout << parser[sLoc+1] << std::endl;
			 }
		}
		if(aLoc > 0){
			if(parser.isString(aLoc+1)){
				std::cout << parser[aLoc+1] << std::endl;
				std::ifstream infile;
				infile.open(parser[aLoc+1]);
				Constants::setConstantsFromFile(infile);
				std::cout << Constants::getInstance()->gravity << std::endl;
			 }
		}
		if(lLoc > 0)
		{
			if(parser.isString(lLoc+1))
			{
				logger->setFileName(parser[lLoc+1]);
			}
		}
		else
			{
				logger->setFileName("helicopterLog.txt");
			}
	}

	render.Game_Play();
	return 0;
}