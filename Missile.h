
#ifndef __HelicopterProject__Missile_h__
#define __HelicopterProject__Missile_h__


#include <osg/ShapeDrawable>
#include <cmath>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Model.h"
#include "Helicopter.h"
#include "EulerPhysics.h"
#include "RK4.h"
#include "Observer.h"
#include "Configuration.h"
#include "WorldConstants.h"
#include "Hud.h"
#include "Collidable.h"


class Game;
class Helicopter;

class Missile : public Model, public Observer, public Collidable {
public:
	
	Missile(Game *game, Helicopter *helicopterOwenMe);
	~Missile();
	
	void Update(Event event);
	
	void fire();
	void incrementInclinationAngle();
	void decrementInclinationAngle();
	void incrementIintialSpeed();
	void decrementIintialSpeed();
	void setInclinationAngle(float inclinationAngle);
	float getInclinationAngle();
	void setFuel(unsigned int fuel);
	void setInitialSpeed(unsigned int initialSpeed);
	unsigned int getInitialSpeed();
	
	osg::BoundingSphere getBound();
	void collide();
	
private:
	void checkTimeout();
	
	std::chrono::time_point<std::chrono::system_clock> startTime;
	std::chrono::time_point<std::chrono::system_clock> endTime;
	
	
	// missile shape
	osg::ref_ptr<osg::ShapeDrawable> missileShape;
	
	// from -85 to +85 degrees
	float inclinationAngle;
	
	// to determine if missle has been fired or not
	bool fired;
	
	unsigned int minInitialSpeed;
	unsigned int maxInitialSpeed;
	unsigned int initialSpeed;
	unsigned int fuel;
	unsigned int maxFuel;
	
	
	osg::Vec3f force;
	
	Helicopter *helicopterOwenMe;
	
	Motion *motion;
	
	Hud *missileSpeedHud;
};


#include "Game.h"
#endif 


