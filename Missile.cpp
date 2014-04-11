// This is the implementation of Missile class. It has many getter functions and setter funcitons to set initial speed,
// set fueld, get initial speed, get fuel, checking the time elapsed of a missile, increment and decrement the angle
// of the missile, get boundary, and determine if the missile has collide or not.

#include "Missile.h"

// a constructor to set the missile
Missile::Missile(Game *game, Helicopter *helicopterOwenMe) : Model(game) {

	this->helicopterOwenMe = helicopterOwenMe;
	this->motion = new EulerPhysics(this->getPosistion());
	this->inclinationAngle = 0;
	// setting the missile shape
	this->missileShape  = new osg::ShapeDrawable;
	this->missileShape->setShape(new osg::Sphere(osg::Vec3(0.0f, 0.0f,0.0f), 0.5f));  // sphere shape
	this->missileShape->setColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));                       // red color
	osg::ref_ptr<osg::Geode> missileShapeNode = new osg::Geode;
	missileShapeNode->addDrawable(this->missileShape.get());
	
	this->node->addChild(missileShapeNode);
	this->node->setNodeMask(0x0);
	
	this->force = osg::Vec3f(0, 0, 0);
	this->fired = false;
	this->maxFuel = 900; // about 15s
	this->inclinationAngle = 20;
	this->fuel = this->maxFuel;
	this->minInitialSpeed = 5;
	this->initialSpeed = this->maxInitialSpeed = 40;
	
	this->missileSpeedHud = game->hudsManager->createHud(HudAlignment::RIGHT);
}



Missile::~Missile() {
	if (this->missileSpeedHud) {
		game->hudsManager->removeHud(this->missileSpeedHud);
//		delete this->missileSpeedHud;
	}
}



void Missile::Update(Event event) {
	
	// check if event type is update position
	if (event.getEventType() != EventType::UPDATE_POSITION)
		return;
	
	// check if not fired yet
	if (!this->fired)
		return;
	
	// initialize viscous resistance with zero
	osg::Vec3f viscousResistance = this->motion->getCurrentVelocityVector().operator*(0);
	
	// if friction is active, calculate viscous resistance
	if (this->game->getConfiguration()->isFrictionActive())
		viscousResistance = this->motion->getCurrentVelocityVector().operator*(6 * WORLD_PI * 0.01 * 4);
	
	// set the net force in motion
	this->motion->setNetForce(
							  this->force
							  + osg::Vec3f(0.0, 0.0, -1).operator*(WORLD_GRAVITY)
							  - viscousResistance
							  );
	
	
	// calculate position at dt
	osg::Vec3f nextPosition = this->motion->calculate_position_at(event.dt());
	
	// update the position
    Model::setPosistion(nextPosition);
	
	
	// update hud
	this->missileSpeedHud->setText("missile speed: " +
									std::to_string((long long)motion->getCurrentVelocityVector().length()) + "m/s");
	
	// update fuel
	if (this->fuel <= 0)
		this->force = osg::Vec3f(0, 0, 0);
	else
		this->missileShape->setColor(osg::Vec4(float(this->fuel--) / 480, 0.0f, 0.0f, 1.0f));
	
	
	checkTimeout();
}

// checkTimeout of a missile if it is more than 20 seconds , then remove the missile hud display

void Missile::checkTimeout() {
	this->endTime = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = this->endTime - this->startTime;
	
	if (elapsed_seconds.count() > 20) {             // check if it is more than 20 seconds
		game->hudsManager->removeHud(this->missileSpeedHud);
		delete this->missileSpeedHud;                   // here we remove it from the hud display
		this->fired = false;
		this->node->removeChild((unsigned int)0);
	}
}



void Missile::fire() {
	if (this->game->getConfiguration()->isMissilesWithInitialVelocity()) {
		this->force = osg::Vec3f(0, 0, 0);
		this->motion->setInitialVelocity(osg::Vec3f(this->initialSpeed, 0, 0));
	} else {
		this->motion->setInitialVelocity(osg::Vec3f(this->helicopterOwenMe->getVelocity().length(), 0, 0));
		this->force = osg::Vec3f(cosf(this->getInclinationAngle()), 0, sinf(this->getInclinationAngle())).operator*(29.2);
	}
	this->node->setNodeMask(0x0 - 1);
	this->fired = true;
	this->startTime = std::chrono::system_clock::now();
}


// increment the inclinatin angle by +1
void Missile::incrementInclinationAngle() {
	this->inclinationAngle += 1;
                                        // make sure it is not greater than 80 degree
	if (this->inclinationAngle > 80)
		this->inclinationAngle = 80;
}


// decrement by -1
void Missile::decrementInclinationAngle() {
	this->inclinationAngle -= 1;
	
	if (this->inclinationAngle < -80)       // make sure it is not less than -80 degree
		this->inclinationAngle = -80;
}


// increment initial missile speed by +1
void Missile::incrementIintialSpeed() {
	this->initialSpeed++;
	if (this->initialSpeed > this->maxInitialSpeed)     // makse sure it is not grator than the maximum initial speed
		this->initialSpeed = this->maxInitialSpeed;
}


// decrement the initial speed of a missile by -1
void Missile::decrementIintialSpeed() {
	this->initialSpeed--;
	if (this->initialSpeed < this->minInitialSpeed)     // make sure it is not less than the minimum initial speed
		this->initialSpeed = this->minInitialSpeed;
}


// getter function to reuturn the initial speed of a missile
unsigned int Missile::getInitialSpeed() {
	return this->initialSpeed;
}


// setter function to set the initial speed of a missile
void Missile::setInitialSpeed(unsigned int initialSpeed) {
	this->initialSpeed = initialSpeed;
}


// setter function to set the inclination angle of a missile
void Missile::setInclinationAngle(float inclinationAngle) {

	this->inclinationAngle = inclinationAngle;   // set the inclination angle
	
	if (this->inclinationAngle > 80)                // make sure it is not greator than 80, otherwise set it to 80 as max
		this->inclinationAngle = 80;
	else if (this->inclinationAngle < -80)          // make sure it is not less than -80 , otherwise set it to -80
		this->inclinationAngle = -80;
}


// getter function to return the inclination angle of a missile
float Missile::getInclinationAngle() {
	return osg::DegreesToRadians(this->inclinationAngle);
}


// setter function to set the fuel of a missile
void Missile::setFuel(unsigned int fuel) {
	this->fuel = fuel;              // set the fuel of a missile
	if (this->fuel > this->maxFuel)         // make sure that it is not greator than the max fuel, otherwise set it to the max fuel
		this->fuel = this->maxFuel;
}


// getter function to get the boundary of a missile
osg::BoundingSphere Missile::getBound() {
	return osg::BoundingSphere(this->getParent(0)->getBound());
}


// collide function, if the missile collide, intersect with other obstacle, then change the shape of the missile to
// more bigger red sphere. So, the user will notice that the missile has changed in the size once it's collide.
void Missile::collide() {
	this->missileShape->setShape(new osg::Sphere(osg::Vec3(0.0f, 0.0f,0.0f), 5.5f));  // here we make it bigger
	this->missileShape->setColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));               // set the color red
	this->fired = false;
	game->hudsManager->removeHud(this->missileSpeedHud);                // then remove it from the hud display 
//	delete this->missileSpeedHud;
}



