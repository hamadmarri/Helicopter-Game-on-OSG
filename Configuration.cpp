//
//  Configuration.cpp
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID: 200288569
// This is a configuration class to congigure our screen and file data. 

#include "Configuration.h"


// singelton design , getInstance function to ensure the only instance we are dealing with

Configuration* Configuration::getInstance(){
    static Configuration *instance = nullptr;
    if(instance == nullptr){
        instance = new Configuration();
        instance->initialize();
    }
    return instance;
}
// we initialize our sceen

void Configuration::initialize(){
    // get screen size
    initScreanSizeSettings();
	
    // get ket settings
    initKeySettings();
}


// screen setting
void Configuration::initScreanSizeSettings() {
	osg::GraphicsContext::WindowingSystemInterface *wsi = osg::GraphicsContext::getWindowingSystemInterface();
	
	if (!wsi)
		osg::notify(osg::NOTICE) << "Error, no WindowSystemInterface available, cannot create windows." << std::endl;
	else
		wsi->getScreenResolution(osg::GraphicsContext::ScreenIdentifier(0),
								 Configuration::getInstance()->screenWidth, Configuration::getInstance()->screenHeight);
	
}


// our key settings will be read from a file called settings.txt. It will read each line on the file

void Configuration::initKeySettings() {
	std::ifstream inFile;
	
    // open the file we provided
	inFile.open("settings.txt");
	// read first line
	inFile.get(Configuration::getInstance()->keySettings.resetJoystick);
	inFile.ignore(500, '\n');
    // secon line from the file
    
	inFile.get(Configuration::getInstance()->keySettings.zeroRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(Configuration::getInstance()->keySettings.decreaseRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(Configuration::getInstance()->keySettings.increaseRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(Configuration::getInstance()->keySettings.neutralRotorMode);
	
	inFile.close();
}

// getter functions of our singelton class 

unsigned int Configuration::getScreenWidth() {
	return Configuration::getInstance()->screenWidth;
}



unsigned int Configuration::getScreenHeight() {
	return Configuration::getInstance()->screenHeight;
}


KeySettings Configuration::getKeySettings() {
	return Configuration::getInstance()->keySettings;
}
