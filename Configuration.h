//
//  Configuration.h
//
//	See main.cpp file header for credits
//
//	Singleton class Configuration has been implemented.
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
    // new functions
    static void activateFriction();
	static void disactivateFriction();
	static bool isFrictionActive();
    
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
    bool friction;

    
};


#endif
