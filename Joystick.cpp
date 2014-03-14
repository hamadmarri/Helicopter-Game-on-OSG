//
//  Joystick.cpp
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
// some modification has been added to the
// This the implementation of joystick class. It will handle the theta and phi by using setter and getter functions.
//

#include "Joystick.h"

// constructor
Joystick::Joystick() {
    this->theta = 0;
    this->phi = 0;
}



Joystick::Joystick(Joystick &B) {
    this->theta = B.theta;
    this->phi = B.phi;
}



Joystick::Joystick(double theta, double phi) {
    this->theta = theta;
    this->phi = phi;
}



void Joystick::set_theta(double theta) {
    this->theta = theta;
}



void Joystick::set_phi(double phi) {
    this->phi = phi;
}



double Joystick::get_theta() const {
    return this->theta;
}



double Joystick:: get_phi() const {
    return this->phi;
}



/*
 calculate the unit vector from the two angles(theta and phi)
 */
osg::Vec3f Joystick:: getForce() {
    osg::Vec3f F;
    F.x() = sin(toRadian(get_theta())) * cos(toRadian(get_phi()));
    F.y() = sin(toRadian(get_theta())) * sin(toRadian(get_phi()));
    F.z() = cos(toRadian(get_theta()));
    return F;
}



double Joystick::toRadian(double degree) {
    return (degree * WORLD_PI) / 180;
}



// observe function basic implementation , here the modification of Observe(Event event)
void Joystick::Update(Event event) {
    
	float yCartesian = (Configuration::getScreenHeight() / 2) - event.getY();
	float xCartesian = (Configuration::getScreenWidth() / 2) - event.getX();
	float magnitude = int(sqrt((float) (pow(xCartesian, 2.0) + pow(yCartesian, 2.0))) / 100) % 15;
	
	
    switch(event.getEventType()) {
		case EventType::MOUSE_MOVEMENT:
            this->set_theta(magnitude);
            this->set_phi(atan2(xCartesian, -1 * yCartesian) * 180 / WORLD_PI);
            break;
        case EventType::MOVE_LEFT:
            this->set_theta(15.0);
            this->set_phi(90.0);
            break;
        case EventType::MOVE_FORWARD:
            this->set_theta(15.0);
            this->set_phi(0.0);
            break;
        case EventType::MOVE_RIGHT:
            this->set_theta(15.0);
            this->set_phi(270);
            break;
        case EventType::MOVE_BACKWARD:
            this->set_theta(15.0);
            this->set_phi(180.0);
            break;
        case EventType::CENTER:
            this->set_theta(0.0);
            this->set_phi(0.0);
            break;
        default:
            break;
            
    } // switch
}

