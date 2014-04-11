//
//  Helicopter.cpp
//
//	See main.cpp file header for credits
//
//	Credit: http://scenemodels.flightgear.org/objectview.php?id=3303278
//			http://hyperphysics.phy-astr.gsu.edu/hbase/airfri.html
//
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//


#include "Helicopter.h"


// constructor of the helicopter from the model class
// here we will display the helicopter to the use once the constructor called.
Helicopter::Helicopter(Game *game) : Model(game) {
	
	this->orientation = -1e-2;
	this->motion = nullptr;
    this->joystick = new Joystick();
	this->mainRotor = new Rotor(0.1);
	this->tailRotor = new Rotor(0.05);
	
    this->node->addChild(osgDB::readNodeFile("3124/EC-135_Douane.ac"));
    
    reset();
	
	
	// initialize huds
	initializeHuds();
	
	
	this->missile = nullptr;
	addMissile();
}



void Helicopter::initializeHuds() {
	this->positionHud = game->getHudsManager()->createHud(HudAlignment::LEFT);
	this->groundSpeedAndBearingHud = game->getHudsManager()->createHud(HudAlignment::LEFT);
	this->verticalSpeedHud = game->getHudsManager()->createHud(HudAlignment::LEFT);
	this->liftHud = game->getHudsManager()->createHud(HudAlignment::LEFT);
	this->thrustAndBearingHud = game->getHudsManager()->createHud(HudAlignment::LEFT);
	this->helicopterOrientationHud = game->getHudsManager()->createHud(HudAlignment::LEFT);
	this->missileInclinationHud = game->getHudsManager()->createHud(HudAlignment::LEFT);
	
	this->missileInitialSpeedHud = nullptr;
	if (this->game->getConfiguration()->isMissilesWithInitialVelocity())
		this->missileInitialSpeedHud = game->getHudsManager()->createHud(HudAlignment::LEFT);
}



Helicopter::~Helicopter() {
	if (this->motion)
		delete this->motion;
	
	if (this->joystick)
		delete this->joystick;
	
	if (this->mainRotor)
		delete this->mainRotor;
	
	if (this->tailRotor)
		delete this->tailRotor;
	
	if (this->positionHud)
		delete this->positionHud;
	
	if (this->groundSpeedAndBearingHud)
		delete this->groundSpeedAndBearingHud;
	
	if (this->verticalSpeedHud)
		delete this->verticalSpeedHud;
	
	if (this->liftHud)
		delete this->liftHud;
	
	if (this->thrustAndBearingHud)
		delete this->thrustAndBearingHud;
	
	if (this->helicopterOrientationHud)
		delete this->helicopterOrientationHud;
	
	if (this->missileInclinationHud)
		delete this->missileInclinationHud;
	
	if (this->missileInitialSpeedHud)
		delete this->missileInitialSpeedHud;
}



void Helicopter::addMissile() {
	Missile *oldMissle = this->missile;
	this->missile = new Missile(this->game, this);
	
	if (oldMissle) {
		this->missile.get()->setInclinationAngle(osg::RadiansToDegrees(oldMissle->getInclinationAngle()));
		this->missile.get()->setInitialSpeed(oldMissle->getInitialSpeed());
	}
	
	this->missile.get()->setPosistion(osg::Vec3f(0, 0, 0));
	this->missile.get()->setFuel(700); // 8s
	this->matrixTransform->addChild(this->missile.get());
	
	game->getTimeHandler()->AddObserver(missile.get());
}



void Helicopter::fire() {
	
	osg::ref_ptr<osg::PositionAttitudeTransform> pat2 = new osg::PositionAttitudeTransform(*this->PAT);
	pat2.get()->removeChildren(0, 1);
	pat2.get()->addChild(this->missile.get());
	this->matrixTransform->removeChild(this->missile.get());
	
	game->getRoot()->addChild(pat2.get());
	
	this->missile->fire();
	game->getCollision()->addCollidable(this->missile.get());
	addMissile();
}



void Helicopter::setPosistion(osg::Vec3f newPos) {
	Model::setPosistion(newPos);
	
	if (this->motion)
		delete this->motion;
	// using RK4 calculation as concrete class
    //	this->motion = new RK4(this->getPosistion());
	this->motion = new EulerPhysics(this->getPosistion());
}



void Helicopter::Update(Event event) {
	
	if (event.getEventType() != EventType::UPDATE_POSITION)
		return;
    
	updatePosition(event.dt());
	updateOrientation();
	updateHuds();
	checkIfCrashed();
}



void Helicopter::updatePosition(float dt) {
	osg::Vec3f viscousResistance = this->motion->getCurrentVelocityVector().operator*(0);
	
	if (this->game->getConfiguration()->isFrictionActive()) {
        //		viscousResistance = this->motion->getCurrentVelocity();
        //		viscousResistance.operator*(viscousResistance);
        //		viscousResistance.operator*(0.0006);
		
		viscousResistance = this->motion->getCurrentVelocityVector().operator*(6 * WORLD_PI * 0.001 * 4);
	}
		
	
	// adjust joystick based on helicopter orientation
	this->joystick->set_phi(this->joystick->get_phi() + this->orientation);
	
	
	this->motion->setNetForce(
							  this->joystick->getForce().operator*(this->mainRotor->getMagnitude())
							  + osg::Vec3f(0.0, 0.0, -1).operator*(WORLD_GRAVITY)
							  - viscousResistance
							  );
	
	// reset joystick
	this->joystick->set_phi(this->joystick->get_phi() - this->orientation);
	
	osg::Vec3f nextPosition = this->motion->calculate_position_at(dt);
    Model::setPosistion(nextPosition);
}



void Helicopter::updateOrientation() {
	this->orientation += this->tailRotor->getMagnitude() - WORLD_GRAVITY;
	
	if (this->orientation >= 360.0f)
		this->orientation -= 360.0f;
	else if (this->orientation <= -360.0f)
		this->orientation += 360.0f;
	
	this->PAT->setAttitude(
						   osg::Quat(
									 osg::DegreesToRadians(
														    (cos(osg::DegreesToRadians(this->orientation)) *
															this->joystick->get_theta()
															 )
														   * cos(osg::DegreesToRadians(this->joystick->get_phi() + this->orientation))
														   ),osg::Vec3f(1,0,0),
									 
									 osg::DegreesToRadians(this->orientation),osg::Vec3f(0,1,0),
									 
									 osg::DegreesToRadians(
														   this->joystick->get_theta()
														   * -1 * sin(osg::DegreesToRadians(this->joystick->get_phi() + this->orientation))
														   ),osg::Vec3f(0,0,1)
									 )
						   );
}



void Helicopter::updateHuds() {
	int orientationBearingDegree = -1 * (int)(this->orientation - 360) % 360;
	int thrustBearingDegree = -1 * (int)(this->joystick->get_phi() - 360) % 360;
	std::string orientationBearingSymbol = getBearingSymbol(orientationBearingDegree);

	
	this->positionHud->setText("x: " + fixPrecision(std::to_string(this->getPosistion().x() + X_REFERENCE)) + 'm'
							   + " | y: " + fixPrecision(std::to_string(this->getPosistion().y() + Y_REFERENCE)) + 'm'
							   + " | Altitude: " + fixPrecision(std::to_string(this->getPosistion().z())) + 'm');

	
	this->groundSpeedAndBearingHud->setText("ground speed: " + fixPrecision(std::to_string(motion->getGroundSpeed())) + "m/s");
	
	this->verticalSpeedHud->setText("vertical speed: " +
									fixPrecision(std::to_string(motion->getCurrentVelocityVector().z())) + "m/s");
	
	this->liftHud->setText("lift: " +
						   std::to_string( (cos(osg::DegreesToRadians(this->joystick->get_theta()))
											* this->mainRotor->getMagnitude())
										  / WORLD_GRAVITY)
						   + 'g');
	
	this->thrustAndBearingHud->setText("thrust: " +
									   std::to_string( (sin(osg::DegreesToRadians(this->joystick->get_theta()))
														* this->mainRotor->getMagnitude())
													  / WORLD_GRAVITY)
									   + "g | " +
									   "bearing: " + std::to_string(thrustBearingDegree));
	
	this->helicopterOrientationHud->setText("orientation: " +
											std::to_string(orientationBearingDegree) + " " + orientationBearingSymbol);
	
	this->missileInclinationHud->setText("missile inclination: " +
										 std::to_string((int)osg::RadiansToDegrees(this->missile->getInclinationAngle())) + "°");
	
	
	if (this->game->getConfiguration()->isMissilesWithInitialVelocity())
		this->missileInitialSpeedHud->setText("missile initial speed: " +
				std::to_string(this->missile.get()->getInitialSpeed()) + "m/s");
	
}



std::string Helicopter::fixPrecision(std::string s) {
	u_int8_t precision = 1;
	if (s[0] == '-')
		precision++;
	
	if (s.find('.') > precision)
		return  s.substr(0, s.find('.'));
	else
		return s.substr(0, s.find('.') + 3);
}



std::string Helicopter::getBearingSymbol(int degree) {
	// set orientationBearingSymbol
	if (degree > 337 || degree < 23)
		return "N";
	else if (degree > 22 && degree < 67)
		return "N|E";
	else if (degree > 66 && degree < 112)
		return "E";
	else if (degree > 111 && degree < 157)
		return "S|E";
	else if (degree > 156 && degree < 202)
		return "S";
	else if (degree > 201 && degree < 247)
		return "S|W";
	else if (degree > 246 && degree < 292)
		return "W";
	else if (degree > 291 && degree < 338)
		return "N|W";
	
	return "";
}


void Helicopter::reset() {
	setPosistion(osg::Vec3f(-1 * X_REFERENCE, 0.0, WORLD_GROUND));
}



osg::Vec3f Helicopter::getVelocity() {
	return this->motion->getCurrentVelocityVector();
}



osg::Vec3f Helicopter::getAcceleration() {
	return (this->joystick->getForce().operator*(this->mainRotor->getMagnitude())
			+ osg::Vec3f(0.0, 0.0, -1).operator*(WORLD_GRAVITY));
}



Joystick* Helicopter::getJoystick() {
	return this->joystick;
}



Rotor* Helicopter::getMainRotor() {
	return this->mainRotor;
}


Rotor* Helicopter::getTailRotor() {
	return this->tailRotor;
}



Missile* Helicopter::getMissile() {
	return this->missile;
}



osg::BoundingSphere Helicopter::getBound() {
	return osg::BoundingSphere(this->PAT->getBound());
}



void Helicopter::collide() {
	this->node->addChild(osgDB::readNodeFile("SmokeBox.osgt"));
}



void Helicopter::checkIfCrashed() {
	if (this->getPosistion().z() <= 0 && this->motion->getCurrentVelocityVector().z() < -1.1)
		collide();
}



std::string Helicopter::toString() {
	std::string helicopterInfo = "";
	
	helicopterInfo += "Helicopter: \n";
	
	// position
	helicopterInfo += "\tp(" + std::to_string(this->getPosistion().x() + X_REFERENCE) + ", "
						+ std::to_string(this->getPosistion().y() + Y_REFERENCE) + ", "
						+ std::to_string(this->getPosistion().z()) + ") m\n";
	
	// velocity
	helicopterInfo += "\tv(" + std::to_string(this->motion->getCurrentVelocityVector().x()) + ", "
	+ std::to_string(this->motion->getCurrentVelocityVector().y()) + ", "
	+ std::to_string(this->motion->getCurrentVelocityVector().z()) + ") m/s\n";
	
	
	// netforce
	helicopterInfo += "\ta(" + std::to_string(this->motion->getCurrentNetForceVector().x()) + ", "
	+ std::to_string(this->motion->getCurrentNetForceVector().y()) + ", "
	+ std::to_string(this->motion->getCurrentNetForceVector().z()) + ") m/s^2\n";
	
	// joystick
	helicopterInfo += '\t' + this->joystick->toString();

	// main rotor
	helicopterInfo += "\tmain " + this->mainRotor->toString();
	
	// tail rotor
	helicopterInfo += "\ttail " + this->tailRotor->toString();
	
	return helicopterInfo;
}





