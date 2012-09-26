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

//What is this method used for? Is there a way to reuse code to not have this function?
Node::~Node(void)
{
}

void Node::addAfter (Node* baseNode, Circle_NickVer* circleForNewNode)
{
	Node* nextNode = baseNode->next;
	Node* temp = new Node(nextNode, baseNode, circleForNewNode);
	baseNode->next = temp;
	nextNode->previous = temp;
	//should there be a "delete temp;" here to avoid taking up space?
}

void Node::addBefore (Node* baseNode, Circle_NickVer* circleForNewNode)
{
	Node* prevNode = baseNode->previous;
	Node* temp = new Node(baseNode, prevNode, circleForNewNode);
	baseNode->previous = temp;
	prevNode->next = temp;
}

void Node::swapNodes (Node* nodeToMove, bool isMovingUp)
{
	Node* swapTarget;
	if (isMovingUp)
	{
		swapTarget = nodeToMove->next;
		nodeToMove->next = swapTarget->next;
		swapTarget->previous = nodeToMove->previous;
		nodeToMove->previous = swapTarget;
		swapTarget->next = nodeToMove;
		nodeToMove->next->previous = nodeToMove;
		swapTarget->previous->next = swapTarget;
	}
	else
	{
		swapTarget = nodeToMove->previous;
		nodeToMove->previous = swapTarget->previous;
		swapTarget->next = nodeToMove->next;
		nodeToMove->next = swapTarget;
		swapTarget->previous = nodeToMove;
		nodeToMove->previous->next = nodeToMove;
		swapTarget->next->previous = swapTarget;
	}
}

void Node::reverseList (Node* sentinel)
{
	Node* current = sentinel;
	Node* temp;

	do
	{
	temp = current->next;
	current->next = current->previous;
	current->previous = temp;
	current = current->next;
	} while(current != sentinel);
}
