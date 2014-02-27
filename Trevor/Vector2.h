#pragma once

#include <math.h>

class Vector2
{
public:
	Vector2(void);
	Vector2(float X, float Y);
	~Vector2(void);
	float Length();
	Vector2 Normalize();
	float X,Y;
};

