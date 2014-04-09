// Author: Karim Naqvi


#ifndef HUD_H
#define HUD_H

#include <osg/Camera>
#include <osgText/Text>
#include <osg/Geode>
#include <iostream>

class Hud {

private:
    osg::ref_ptr<osg::Camera> camera;
    osg::ref_ptr<osg::Geode> hudGeode;

    osgText::Text * text;

public:
    Hud();
	~Hud();
    void setText(const std::string& hudTest);

    void setPosition(osg::Vec3d position);
	osg::Vec3d getPosition();
	  
    osg::Camera * getHudCamera();
    osg::Geode * getHudGeode();
    void initializeHudText();

	void hide();
	void show();
};

#endif
