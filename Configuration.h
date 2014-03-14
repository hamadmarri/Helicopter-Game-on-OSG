//
//  Configuration.h
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID: 200288569
//


// Singleton class Configuration has been implemented.
// 

#ifndef __HelicopterProject__Configuration_h__
#define __HelicopterProject__Configuration_h__


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
    static unsigned int getScreenWidth();
	static unsigned int getScreenHeight();
	KeySettings getKeySettings();
    
private:
	Configuration() {};
	Configuration(const Configuration&);
	void operator=(const Configuration&);
	
	void initialize();
	void initScreanSizeSettings();
	void initKeySettings();
	
	unsigned int screenWidth;
	unsigned int screenHeight;
	
	KeySettings keySettings;

    
};


#endif
