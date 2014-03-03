#pragma once
class HelicopterConfig
{
public:
	float maxAirspeed;
	float mass;
	float maxTakeoffWeight;
	HelicopterConfig(void);
	HelicopterConfig(float maxAirspeed, float mass, float maxTakeoffWeight);
	~HelicopterConfig(void);
};

