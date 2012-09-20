/* 
*	This class exists to represent the various nodes in a Circular-never-empty-Doubly-Linked List.
*	@author Nicholas Uth
*/

#pragma once
#include "Circle_NickVer.h"

class Node
{
public:
	// Blank constructor. Constructs a sentinel node.
	Node(void);
	// The main constructor. Has two pointers (next and previous) and a shape.
	Node(Node* next, Node* previous, Circle_NickVer circle);
	// Unknown constructor, but I'm leaving it here just in case so nothing breaks. :P
	~Node(void);
	//
	void addAfter (Node* nodeToAdd);
	//
	void addBefore (Node* nodeToAdd);
	//

private:
	Node* next;
	Node* previous;
	Circle_NickVer circle;
};

