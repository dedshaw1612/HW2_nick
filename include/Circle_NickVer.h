#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
/* 
*	This class exists to represent the circles in the window.
*	@author Nicholas Uth
*/

using namespace ci;

class Circle_NickVer
{
public:
	// null constructor
	Circle_NickVer(void);
	// Main constructor.
	Circle_NickVer(float centerX, float centerY, float radius, float r, float g, float b, float alpha);
	// Unknown constructor, but I'm leaving it here just in case so nothing breaks. :P
	~Circle_NickVer(void);

private:
	Vec2f center;
	float radius;
	Color8u color;
};
