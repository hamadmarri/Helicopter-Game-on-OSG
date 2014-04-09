
#ifndef __HelicopterProject__Logger__
#define __HelicopterProject__Logger__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include "Loggable.h"


class Logger {
public:
	Logger();
	Logger(std::string fileName);
	~Logger();
	
	void addLoggable(Loggable* loggable);
	void removeLoggable(Loggable* loggable);
	
	
	void startLogging();
	void endLogging();
	void log();
private:
	void openFile();
	void closeFile();
	void printTime();
	
	bool loggingEnabled;
	std::string fileName;
	std::ofstream outFile;
	std::vector<Loggable*> loggables;
	
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
};

#endif /* defined(__HelicopterProject__Logger__) */
