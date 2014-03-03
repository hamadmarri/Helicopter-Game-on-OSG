/*
	Logger
		Singleton Logger that allows a string to be logged to a file with a timestamp

		Credits: Tylor Froese, Brian Schwietzer

*/

#ifndef LOGGER_H
#define LOGGER_H

#include "Render.h"
#include <fstream>

using namespace std;

class Logger
{
private:
	static Logger* instance;
	FILE * logFile;
	string logFileName;
	bool loggingOn;
public:
	static Logger* getInstance(){
		static Logger *instance = NULL;
		if(instance == NULL){
			instance = new Logger();
		}
		return instance;
	}
	void setFileName(string);
	void openLog();
	void closeLog();
	void log(string data);
	void toggleLogging();
	Logger();
};
#endif