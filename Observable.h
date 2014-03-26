//
//  Observable.h
//
//	See main.cpp file header for credits
//

#ifndef __HelicopterProject__Observable_h__
#define __HelicopterProject__Observable_h__

#include <vector>
#include "Observer.h"
#include "Event.h"


class Observable {
public:
	void AddObserver(Observer *observer);
    void RemoveObserver(Observer *observer);
    void NotifyAll(Event event);

protected:
	std::vector<Observer*> observers;
};


#endif
