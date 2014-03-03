/*
	Logger
		Singleton Logger that allows a string to be logged to a file with a timestamp

		Credits: Tylor Froese, Brian Schwietzer

*/

#include "Logger.h"
#include "Render.h"
#include <fstream>
#include <stdio.h>

using namespace std;


void Logger::log(string data){
	if(loggingOn){
//		SYSTEMTIME time;
//		GetLocalTime(&time);
//		fprintf(logFile,"%04d-%02d-%02d %02d:%02d:%02d.%04d: %s \n",
//			time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds, data.c_str());
	}
}
void Logger::openLog()
{
	char * charLog;
	charLog = new char[logFileName.size()+1];
	strcpy(charLog, logFileName.c_str());
	logFile = fopen(charLog,"a");
}
void Logger::closeLog()
{
	fclose(logFile);
}
void Logger::setFileName(string name)
{
	logFileName = name;
}

void Logger::toggleLogging(){
	if(loggingOn)
	{
		closeLog();
		loggingOn = false;
	}
	else
	{
		openLog();
		loggingOn = true;
	}
}

Logger::Logger(){
	loggingOn = false;
}
