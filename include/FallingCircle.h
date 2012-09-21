/*
*	Represents the blocks that fall from the ceiling of the window that the user must dodge.
*	@author Nicholas Uth
*/

#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace cinder;

class FallingCircle
{
public:
	// standard constructor. All are practically the same (except for their random X coordinate).
	FallingCircle(void);
	~FallingCircle(void);
	void reset(void);

	//kept public for sake of ease
	Vec2f center;
	static const int radius = 10;
	int speed;

private:
	// constant values designating size and position
	static const int xMin = 10;
	static const int xMax = 1090;
	static const int minSpeed = 1;
	static const int maxSpeed = 7;
};