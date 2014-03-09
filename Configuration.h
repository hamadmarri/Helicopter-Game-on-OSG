//
//  Configuration.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID: 200288569
//


// Singleton class Configuration has been implemented. 

#ifndef testOsg_Configuration_h
#define testOsg_Configuration_h


#include <osg/GraphicsContext>
#include <fstream>

struct KeySettings {
	char resetJoystick, zeroRotorSpeed,
	decreaseRotorSpeed, increaseRotorSpeed,  neutralRotorMode;
};


class Configuration{
public:
    // static (singelton)
    static Configuration* getInstance();

    
};


#endif
