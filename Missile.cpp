

#include "Missile.h"


Missile::Missile(Game *game, Helicopter *helicopterOwenMe) : Model(game) {

	this->helicopterOwenMe = helicopterOwenMe;
	this->motion = new EulerPhysics(this->getPosistion());
	this->inclinationAngle = 0;
	
	this->missileShape  = new osg::ShapeDrawable;
	this->missileShape->setShape(new osg::Sphere(osg::Vec3(0.0f, 0.0f,0.0f), 0.5f));
	this->missileShape->setColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));
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
	
	this->missileSpeedHud = game->getHudsManager()->createHud(HudAlignment::RIGHT);
}



Missile::~Missile() {
	if (this->missileSpeedHud) {
		game->getHudsManager()->removeHud(this->missileSpeedHud);
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



void Missile::checkTimeout() {
	this->endTime = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = this->endTime - this->startTime;
	
	if (elapsed_seconds.count() > 20) {
		game->getHudsManager()->removeHud(this->missileSpeedHud);
		delete this->missileSpeedHud;
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



void Missile::incrementInclinationAngle() {
	this->inclinationAngle += 1;
	
	if (this->inclinationAngle > 80)
		this->inclinationAngle = 80;
}



void Missile::decrementInclinationAngle() {
	this->inclinationAngle -= 1;
	
	if (this->inclinationAngle < -80)
		this->inclinationAngle = -80;
}



void Missile::incrementIintialSpeed() {
	this->initialSpeed++;
	if (this->initialSpeed > this->maxInitialSpeed)
		this->initialSpeed = this->maxInitialSpeed;
}



void Missile::decrementIintialSpeed() {
	this->initialSpeed--;
	if (this->initialSpeed < this->minInitialSpeed)
		this->initialSpeed = this->minInitialSpeed;
}



unsigned int Missile::getInitialSpeed() {
	return this->initialSpeed;
}



void Missile::setInitialSpeed(unsigned int initialSpeed) {
	this->initialSpeed = initialSpeed;
}



void Missile::setInclinationAngle(float inclinationAngle) {

	this->inclinationAngle = inclinationAngle;
	
	if (this->inclinationAngle > 80)
		this->inclinationAngle = 80;
	else if (this->inclinationAngle < -80)
		this->inclinationAngle = -80;
}



float Missile::getInclinationAngle() {
	return osg::DegreesToRadians(this->inclinationAngle);
}



void Missile::setFuel(unsigned int fuel) {
	this->fuel = fuel;
	if (this->fuel > this->maxFuel)
		this->fuel = this->maxFuel;
}



osg::BoundingSphere Missile::getBound() {
	return osg::BoundingSphere(this->getParent(0)->getBound());
}



void Missile::collide() {
	this->missileShape->setShape(new osg::Sphere(osg::Vec3(0.0f, 0.0f,0.0f), 5.5f));
	this->missileShape->setColor(osg::Vec4(1.0f,0.0f,0.0f,1.0f));
	this->fired = false;
	game->getHudsManager()->removeHud(this->missileSpeedHud);
//	delete this->missileSpeedHud;
}



