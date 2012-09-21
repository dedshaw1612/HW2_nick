/*
*	Represents the blocks that fall from the ceiling of the window that the user must dodge.
*	@author Nicholas Uth
*/

#pragma once
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace cinder;

class FallingBlock
{
public:
	// standard constructor. All blocks are practically the same (except for their random X coordinate).
	FallingBlock(void);
	~FallingBlock(void);

	//kept public for sake of ease
	Rectf* rect;

private:
	// constant values designating size and position
	static const int xMin = 10;
	static const int xMax = 1000;
	static const int width = 100;
	static const int height = 100;
};
