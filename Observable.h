//
//  Observable.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
//

#ifndef testOsg_Observable_h
#define testOsg_Observable_h

#include "Observer.h"

class Observable {
public:
	virtual void AddObserver(Observer *observer) = 0;
    virtual void RemoveObserver(Observer *observer) = 0;
    virtual void NotifyAll(char event) = 0;
};

#endif
