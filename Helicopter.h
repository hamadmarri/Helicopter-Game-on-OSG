//
//  Helicopter.h
//
//	See main.cpp file header for credits
//
//	a Helicopter class inhereted from a Model class and implement Observer, collidable, loggable interfaces.
//	The helicopter has joystick, rotor, and it has a motion.
//


#ifndef __HelicopterProject__Helicopter_h__
#define __HelicopterProject__Helicopter_h__


#include <iostream>
#include <cmath>
#include <string>
#include <osgViewer/Viewer>
#include "Configuration.h"
#include "Model.h"
#include "Joystick.h"
#include "Rotor.h"
#include "Missile.h"
#include "Observer.h"
#include "RK4.h"
#include "EulerPhysics.h"
#include "WorldConstants.h"
#include "Hud.h"
#include "Collidable.h"
#include "Loggable.h"


// definition of Game and Missiles
class Game;
class Missile;


class Helicopter : public Model, public Observer, public Collidable, public Loggable {
public:
    Helicopter(Game *game);
    ~Helicopter();
    void Update(Event event);
    
    // override
	void setPosistion(osg::Vec3f newPos);
	void reset();
	
	void initializeHuds();
	
	void addMissile();
	void fire();
	
	osg::Vec3f getVelocity();
	osg::Vec3f getAcceleration();
	
	Joystick* getJoystick();
	Rotor* getMainRotor();
	Rotor* getTailRotor();
	Missile* getMissile();
	
	osg::BoundingSphere getBound();
	void collide();
	
	std::string toString();
	
private:
	void updatePosition(float dt);
	void updateOrientation();
	void updateHuds();
	std::string getBearingSymbol(int degree);
	void checkIfCrashed();
	
	std::string fixPrecision(std::string s);
	
	float orientation;
	Joystick *joystick;
    Rotor *mainRotor;
	Rotor *tailRotor;
	osg::ref_ptr<Missile> missile;
    Motion *motion;
	
	Hud *positionHud;
	Hud *groundSpeedAndBearingHud;
	Hud *verticalSpeedHud;
	Hud *liftHud;
	Hud *thrustAndBearingHud;
	Hud *helicopterOrientationHud;
	Hud *missileInclinationHud;
	Hud *missileInitialSpeedHud;
};


#include "Game.h"
#endif
