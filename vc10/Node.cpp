#include "Node.h"
#include "Circle_NickVer.h"

Node::Node(void)
{
	next = NULL;
	previous = NULL;
}

Node::Node(Node* next_in, Node* previous_in, Circle_NickVer* circle_in)
{
	next = next_in;
	previous = previous_in;
	circle = circle_in;
}

Node::~Node(void)
{
}

void Node::addAfter (Node* baseNpde, Circle_NickVer* circleForNewNode)
{
}
void Node::addBefore (Node* baseNode, Circle_NickVer* circleForNewNode)
{
}
void Node::swapNodes (Node* nodeToMove, bool isMovingUp)
{
}
void Node::reverseList ()
{
}