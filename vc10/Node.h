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
	Node(Node* next, Node* previous, Circle_NickVer* circle);
	// Unknown constructor, but I'm leaving it here just in case so nothing breaks. :P
	~Node(void);
	// adds a new node after the specified node.
	void addAfter (Node* baseNpde, Circle_NickVer* circleForNewNode);
	// adds a new node before the specified node.
	void addBefore (Node* baseNode, Circle_NickVer* circleForNewNode);
	// takes a node and, if bool == true, switches it's position in the list with the next node. Else,
	// it switches its position with the previous node.
	void swapNodes (Node* nodeToMove, bool isMovingUp);
	// recursively goes through the list and flips all of the next and previous pointers
	void reverseList ();

private:
	Node* next;
	Node* previous;
	Circle_NickVer* circle;
};

