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

void Node::addAfter (Node* baseNode, Circle_NickVer* circleForNewNode)
{
	Node* nextNode = baseNode->next;
	Node* temp = new Node(nextNode, baseNode, circleForNewNode);
	baseNode->next = temp;
	nextNode->previous = temp;
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
	}
	else
	{
		swapTarget = nodeToMove->previous;
		nodeToMove->previous = swapTarget->previous;
		swapTarget->next = nodeToMove->next;
		nodeToMove->next = swapTarget;
		swapTarget->previous = nodeToMove;
	}
}

void Node::reverseList (Node* sentinel)
{
	Node* current = sentinel->previous;
	Node* temp;

	while(current->next != NULL && current->previous != NULL)
	{
	temp = current->next;
	current->next = current->previous;
	current->previous = temp;
	current = current->next;
	}
}
