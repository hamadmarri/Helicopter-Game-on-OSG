//
//  Observer.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
// pure abstract class Observer . This class mostly will be used as an abstract class to observe events from other class. Thedesign we had decided to choose is observer design.

#ifndef testOsg_Observer_h
#define testOsg_Observer_h

#include "Event.h"


class Observer {
public:
    virtual void Observe(Event event) = 0;
};

#endif
