/* 
*	This class exists to represent the circles in the window.
*	@author Nicholas Uth
*/

#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Circle_NickVer
{
public:
	// null constructor
	Circle_NickVer(void);
	// Main constructor. Allows the user to set the center's coordinates (floats), the radius (float),
	// and the color (floats).
	Circle_NickVer(float centerX, float centerY, float radius, float r, float g, float b);
	~Circle_NickVer(void);
	// takes a coordinate point and determines if it falls within the circle's area
	bool isInside (float x, float y);

	// leaving these public for sake of ease
	Vec2f center;
	float radius;
	Color8u color;
};
