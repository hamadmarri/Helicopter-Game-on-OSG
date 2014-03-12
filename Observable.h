//
//  Observable.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
//
//  Obserable class to add observer - remove observer - and to notify event. It is abstract class. 
#ifndef testOsg_Observable_h
#define testOsg_Observable_h

#include "Observer.h"
#include "Event.h"
class Observable {
public:
	virtual void AddObserver(Observer *observer) = 0;
    virtual void RemoveObserver(Observer *observer) = 0;
    virtual void NotifyAll(Event event) = 0;
};

#endif
