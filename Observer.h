//
//  Observer.h
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
//

#ifndef __HelicopterProject__Observer_h__
#define __HelicopterProject__Observer_h__

#include "Event.h"


class Observer {
public:
    virtual void Update(Event event) = 0;
};


#endif
