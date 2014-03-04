//
//  Joystick.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
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
    return (degree * 3.14159265) / 180;
}


// observe function basic implementation 
void Joystick:: Observe(char event){
    
    
    switch(event) {
        case 'a': case 'A':
            this->set_theta(45.0);
            this->set_phi(90.0);
            break;
        case 'w': case 'W':
            this->set_theta(45.0);
            this->set_phi(0.0);
            break;
        case 'd': case 'D':
            this->set_theta(45.0);
            this->set_phi(270);
            break;
        case 's': case 'S':
            this->set_theta(45.0);
            this->set_phi(180.0);
            break;
        case '0':
            this->set_theta(0.0);
            this->set_phi(0.0);
            break;
        default:
            break;
            
    }
    

}

