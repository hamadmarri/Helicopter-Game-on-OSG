#include "HelicopterConfig.h"

HelicopterConfig::HelicopterConfig(void)
{
	this->mass = 9000;
	this->maxAirspeed = 66.6667;
	this->maxTakeoffWeight = 21000;
}

HelicopterConfig::HelicopterConfig(float maxAirspeed, float mass, float maxTakeoffWeight)
{
	this->mass = mass;
	this->maxAirspeed = maxAirspeed;
	this->maxTakeoffWeight = maxTakeoffWeight;
}


HelicopterConfig::~HelicopterConfig(void)
{
}
