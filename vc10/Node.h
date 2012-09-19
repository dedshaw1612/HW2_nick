#pragma once
#include "Circle_NickVer.h"

/* 
*	This class exists to represent the various nodes in a Circular-never-empty-Doubly-Linked List.
*	@author Nicholas Uth
*/

class Node
{
public:
	// Blank constructor
	Node(void);
	// The main constructor. Has two pointers (next and previous) and a shape.
	Node(Node* next, Node* previous, Circle_NickVer circle);
	// Unknown constructor, but I'm leaving it here just in case so nothing breaks. :P
	~Node(void);

private:
	Node* next;
	Node* previous;
	Circle_NickVer circle;
	
};

