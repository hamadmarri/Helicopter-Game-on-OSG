//
//  Loggable.h
//
//	See main.cpp file header for credits
//
//	Loggable is an interface that can be implemented by any object that need to be logged.
//	The toString function is pure, which returns a string. The object that implements this function
//	suppose to return a string of information of itself so the Logger class will call toString function
//	if the object has been added to loggables vector properly
//


#ifndef __HelicopterProject_Loggable_h__
#define __HelicopterProject_Loggable_h__

#include <string>

class Loggable {
public:
	virtual std::string toString() = 0;
};

#endif
