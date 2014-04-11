//
//  Observable.h
//
//	See main.cpp file header for credits
//  Obserable class to add observer, remove observer, and a main function to notifyall event.
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//

#ifndef __HelicopterProject__Observable_h__
#define __HelicopterProject__Observable_h__

#include <vector>
#include "Observer.h"
#include "Event.h"


class Observable {
public:
	void AddObserver(Observer *observer);		// add observer
    void RemoveObserver(Observer *observer);    // delete observer
    void NotifyAll(Event event);                // notifyAll observers

protected:
	std::vector<Observer*> observers;           // a vector of observer class which an abstract class
};


#endif
