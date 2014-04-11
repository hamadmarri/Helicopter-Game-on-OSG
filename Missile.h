// This is Missile class inheritaed from Model class, Observer, and Collidable class.
// Purpose : The main purpose of this class is handle the firing from a helicopter. The firing
// has some constrains in angles and speed. The shape of the firring has been initialized as a
// sphere and it can be two type of firing, firing by fule or by it's speed velocity. The client can
// either choose between using a fuel firing or speed firing. 
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

// define game class, Helicopter class
class Game;
class Helicopter;
// inhertitance public from Model, Observer, Collidable
class Missile : public Model, public Observer, public Collidable {
public:
	
	Missile(Game *game, Helicopter *helicopterOwenMe);          // constructor
	~Missile();                                                 // deconstructor
	// member function
	void Update(Event event);               // handling events if fire or not and other events
	
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
	
private:                // private members
	void checkTimeout();
	
	std::chrono::time_point<std::chrono::system_clock> startTime;           // chrono librirary to get startTime , endTime 
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


