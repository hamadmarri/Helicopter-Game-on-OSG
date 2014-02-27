// Vector2.cpp

#include "Vector2.h"

Vector2::Vector2(void)
{
}

Vector2::Vector2(float X, float Y){
	this->X = X;
	this->Y = Y;
}

// Returns the length of the vector
float Vector2::Length(){
	return sqrt(X * X + Y * Y);
}

// Normalizes the vector
Vector2 Vector2::Normalize(){
	Vector2 vector;
	float length = this->Length();

	if(length != 0){
		vector.X = X/length;
		vector.Y = Y/length;
	}

	return vector;
}

Vector2::~Vector2(void)
{
}
