

#include "Logger.h"


Logger::Logger() {
	this->fileName = "log.txt";
	openFile();
}



Logger::Logger(std::string fileName) {
	this->fileName = fileName;
	openFile();
}



Logger::~Logger() {
	closeFile();
}



void Logger::openFile() {
	this->outFile.open(this->fileName.c_str());
}



void Logger::closeFile() {
	this->outFile.close();
}



void Logger::addLoggable(Loggable* loggable) {
	this->loggables.push_back(loggable);
}



void Logger::removeLoggable(Loggable* loggable) {
	this->loggables.erase(std::remove(this->loggables.begin(), this->loggables.end(), loggable), this->loggables.end());
}



void Logger::startLogging() {
	this->loggingEnabled = true;
	this->outFile << "========== START LOGGING ==========" << std::endl;
	this->startTime = std::chrono::high_resolution_clock::now();
}



void Logger::endLogging() {
	this->loggingEnabled = false;
	this->outFile << "========== END  LOGGING ==========" << std::endl;
}



void Logger::log() {
	if (!this->loggingEnabled)
		return;
	
	printTime();
	
	// log all loggables
	for (auto loggable = this->loggables.begin(); loggable != this->loggables.end(); loggable++)
		this->outFile << (*loggable)->toString() << std::endl;
}



void Logger::printTime() {
	using namespace std::chrono;
	
	duration<double> elapsedTime = high_resolution_clock::now() - this->startTime;
	microseconds us(duration_cast<microseconds>(elapsedTime).count());
	
	// split into hours, minutes, seconds, milliseconds, and microseconds
	hours h = duration_cast<hours>(us);
	minutes m = duration_cast<minutes>(us % hours(1));
	seconds s = duration_cast<seconds>(us % minutes(1));
	milliseconds ms = duration_cast<milliseconds>(us % seconds(1));
	us = us % milliseconds(1);
	
	this->outFile	<< "[" << h.count() << "::" << m.count() << "::" << s.count()
					<< "::" << ms.count() << "::" << us.count() << "]" << std::endl;
}





