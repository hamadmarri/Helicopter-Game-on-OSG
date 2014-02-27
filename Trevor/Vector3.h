#pragma once

#include <math.h>

class Vector3
{
public:
	Vector3(void);
	Vector3(float X, float Y, float Z);
	~Vector3(void);
	float Length();
	Vector3 Normalize();
	float X,Y,Z;
};

