#include "..\include\FallingBlock.h"


FallingBlock::FallingBlock(void)
{
	rect = new Rectf();
	rect->x1 = (float)((rand() % xMax) + xMin);
	rect->x2 = (float) rect->x1 + width;
	rect->y1 = (float) 0;
	rect->y2 = (float) rect->y1 + height;
}


FallingBlock::~FallingBlock(void)
{
	delete rect;
}
