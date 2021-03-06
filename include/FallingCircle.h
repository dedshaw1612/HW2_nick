/*
*	Represents the blocks that fall from the ceiling of the window that the user must dodge.
*	@author Nicholas Uth
*/

//it maybe easier to have it implemented like this, but have you considered or attempted 
//extending circle or maybe even just adding extra stuff to Circle instead of
//making a sepearate class?
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
	// recycles the falling circle by randomizing it's X value and it's speed while sending 
	// it back to the top of the screen. no need to delete it this way, and it gives the game
	// more challenge progression
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