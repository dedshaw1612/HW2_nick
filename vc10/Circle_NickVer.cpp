#include "..\include\Circle_NickVer.h"
#include <algorithm>

Circle_NickVer::Circle_NickVer(void)
{
}

Circle_NickVer::Circle_NickVer(float centerX, float centerY, float radius_in, float r, float g, float b)
{
	center.x = centerX;
	center.y = centerY;
	radius = radius_in;
	color.r = r;
	color.g = g;
	color.b = b;
}

Circle_NickVer::~Circle_NickVer(void)
{
}

bool Circle_NickVer::isInside (float x, float y)
{
	// if the distance from (x,y) to the center of the circle is less than the radius, it's inside the circle
	float dx = this->center.x - x;
	float dy = this->center.y - y;
	float dist = sqrt((pow(dx,2)) + (pow(dy,2)));
	return (dist <= radius);
}