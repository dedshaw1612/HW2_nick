#include "..\include\Circle_NickVer.h"

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

}