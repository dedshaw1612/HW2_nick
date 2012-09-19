#pragma once

/* 
*	This class exists to represent the various nodes in a Circular-never-empty-Doubly-Linked List.
*	@author Nicholas Uth
*/

class Node
{
public:
	// Blank constructor
	Node(void);
	// TODO: The valid constructor... needs a shape to hold
	Node(Node* next, Node* previous);
	// Unknown constructor, but I'm leaving it here just in case so nothing breaks. :P
	~Node(void);

private:
	Node* next;
	Node* previous;
	
};

