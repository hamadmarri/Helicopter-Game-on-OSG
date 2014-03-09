//
//  Configuration.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID: 200288569
//

#include "Configuration.h"

Configuration* Configuration::getInstance(){
    static Configuration *instance = nullptr;
    if(instance == nullptr){
        instance = new Configuration();
        instance->initialize();
    }
    return instance;
}

void Configuration::initialize(){
    // get screen size
    initScreanSizeSettings();
    // get ket settings
    initKeySettings();
}

// 

void Configuration::initScreanSizeSettings() {
	osg::GraphicsContext::WindowingSystemInterface* wsi =
	osg::GraphicsContext::getWindowingSystemInterface();
	if (!wsi) {
		osg::notify(osg::NOTICE)<<"Error, no WindowSystemInterface available, cannot create windows."<<std::endl;
	} else {
		
		wsi->getScreenResolution(osg::GraphicsContext::ScreenIdentifier(0),
								 Configuration::getInstance()->screenWidth, Configuration::getInstance()->screenHeight);
	}
}



void Configuration::initKeySettings() {
	std::ifstream inFile;
    // open the file we provided 
	inFile.open("settings.txt");
	
	inFile.get(Configuration::getInstance()->keySettings.resetJoystick);
	inFile.ignore(500, '\n');
    
	inFile.get(Configuration::getInstance()->keySettings.zeroRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(Configuration::getInstance()->keySettings.decreaseRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(Configuration::getInstance()->keySettings.increaseRotorSpeed);
	inFile.ignore(500, '\n');
	
	inFile.get(Configuration::getInstance()->keySettings.neutralRotorMode);
	
	inFile.close();
}



unsigned int Configuration::getScreenWidth() {
	return Configuration::getInstance()->screenWidth;
}



unsigned int Configuration::getScreenHeight() {
	return Configuration::getInstance()->screenHeight;
}


KeySettings Configuration::getKeySettings() {
	return Configuration::getInstance()->keySettings;
}
