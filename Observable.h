//
//  Observable.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#ifndef testOsg_Observable_h
#define testOsg_Observable_h

class Observable {
public:
	virtual void AddObserver(Observer observer) = 0;
    virtual void RemoveObserver(Observer observer) = 0;
    virtual void NotifyAll(Observer.EventTypes event) = 0;
}

#endif
