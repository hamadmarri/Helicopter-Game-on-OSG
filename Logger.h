//
//  Logger.h
//
//	See main.cpp file header for credits
//
//	Logger is that class that takes care of logging objects information
//	it saves loggable objects in a vector and call toString function of them respectively.
//	It's also print the time information in form hh::mm::ss::ms::um (i.e. hours, minutes, seconds, milliseconds, and microseconds)
//
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
//


#ifndef __HelicopterProject__Logger_h__
#define __HelicopterProject__Logger_h__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include "Loggable.h"


class Logger {
public:
	
	// constructor
	Logger();
	
	// set file name for logging
	Logger(std::string fileName);
	
	// destructor
	~Logger();
	
	// set log file name
	void setFileName(std::string fileName);
	
	// to add logable in loggables vector
	void addLoggable(Loggable* loggable);
	
	// to remove logable from loggables vector
	void removeLoggable(Loggable* loggable);
	
	// need to call startLogging function
	// to enable logging
	void startLogging();
	
	// it disable logging even if
	// log function has been called,
	// will do nothing if logging is disabled
	void endLogging();
	
	// log all loggables
	void log();
	
	// return true if startLogging already, false if stopped
	bool isLoggingEnabled();
	
private:
	
	// open log file
	void openFile();
	
	// close log file
	void closeFile();
	
	// log time to log file
	void printTime();
	
	// to determine if logging is enabled or not
	bool loggingEnabled;
	
	// log file name
	std::string fileName;
	
	// output file object
	std::ofstream outFile;
	
	// a vector of loggables need to be logged
	std::vector<Loggable*> loggables;
	
	// start time is set wheneve startLogging function is called
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#endif
