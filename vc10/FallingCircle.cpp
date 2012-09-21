#include "..\include\FallingCircle.h"


FallingCircle::FallingCircle(void)
{
	center.y = 10;
	center.x = (float) ((rand()%xMax) + xMin);
	speed = (float) ((rand()%maxSpeed) + minSpeed);
}


FallingCircle::~FallingCircle(void)
{
}

void FallingCircle::reset(void)
{
	center.y = 10;
	center.x = (float) ((rand()%xMax) + xMin);
	speed = (float) ((rand()%maxSpeed) + minSpeed);
}