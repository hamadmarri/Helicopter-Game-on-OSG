//
//  Joystick.cpp
//
//	See main.cpp file header for credits
//
//	This the implementation of joystick class.
//	It will handle the theta and phi by using setter and getter functions.
//

#include "Joystick.h"


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


// update the set_theta function to 15.0 degree or 0
void Joystick::set_theta(double theta) {
    if(theta >15.0)
        theta = 15.0;
    if(theta < 0)
        theta =0;
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

