//
//  Configuration.h
//
//	See main.cpp file header for credits
//
//	Configuration saves all game configuration by reading settings.txt file and fill
//	up KeySettings struct. Configuration gets the screen size also.
// 


#ifndef __HelicopterProject__Configuration_h__
#define __HelicopterProject__Configuration_h__


#include <osg/GraphicsContext>
#include <fstream>


// KeySettings struct holds all key settings as chars
struct KeySettings {
	char movingForward, movingRight, movingLeft, movingBackward,
	resetJoystick, zeroRotorSpeed,
	decreaseRotorSpeed, increaseRotorSpeed, neutralRotorMode,
	rotateLeft, rotateRight,
	fire, incrementInclinationAngle, decrementInclinationAngle,
	incrementMissileInitialSpeed, decrementMissileInitialSpeed,
	frictionEnable, frictionDisable,
	updateKeySettings, showPopupHelpScreen, hidePopupHelpScreen;
};



class Configuration{
public:

	Configuration();
	unsigned int getScreenWidth();
	unsigned int getScreenHeight();

	bool isMouseControl();
	bool isAutoCamera();
	void activateFriction();
	void disactivateFriction();
	bool isFrictionActive();
	bool isMissilesWithInitialVelocity();
	
	void initKeySettings();
	KeySettings getKeySettings();
    
	
private:
	
	void initialize();
	void initScreanSizeSettings();
	
	unsigned int screenWidth;
	unsigned int screenHeight;
	
	KeySettings keySettings;
    
	bool mouseControl;
	bool autoCamera;
	bool friction;
	

	bool missilesWithInitialVelocity;
    
};


#endif
