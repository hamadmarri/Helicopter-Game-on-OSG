
#include "Hud.h"

#include <osg/Camera>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>

Hud::Hud()
{
    camera = new osg::Camera;
    hudGeode = new osg::Geode;
    camera->setClearMask( GL_DEPTH_BUFFER_BIT);
    camera->setProjectionMatrixAsOrtho2D(0,1280,0,1024);
    camera->setViewMatrix(osg::Matrix::identity());
    camera->setRenderOrder( osg::Camera::POST_RENDER );
    camera->setReferenceFrame( osg::Camera::ABSOLUTE_RF );
}



Hud::~Hud() {
}



void Hud::initializeHudText()
{
    //initialize our text pointer;
    text = new osgText::Text;
	text->setDataVariance(osg::Object::DataVariance::DYNAMIC);
    text->setFont(osgText::readFontFile("fonts/Vera.ttf"));
    text->setColor(osg::Vec4(255, 255, 255,1.0f));
    text->setCharacterSize(18.0f);
    text->setLayout( osgText::Text::LEFT_TO_RIGHT );
    text->setText("Heads Up Display");
    text->setPosition(osg::Vec3(0,50,0));

    hudGeode->addDrawable(text);

    camera->addChild(hudGeode);

}

osg::Camera * Hud::getHudCamera()
{
    return camera;
}

osg::Geode * Hud::getHudGeode()
{
    return hudGeode;
}


void Hud::setText(const std::string& hudText)
{
    text->setText(hudText);
}

void Hud::setPosition(osg::Vec3d position)
{
    text->setPosition(position);
}


osg::Vec3d Hud::getPosition() {
	return text->getPosition();
}



void Hud::hide() {
	this->hudGeode->setNodeMask(0x0);
}



void Hud::show() {
	this->hudGeode->setNodeMask(0x0 - 1);
}



