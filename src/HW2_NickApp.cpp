/*	
*	Homework #2 -- Putting stuff on top of each other.
*	
*	@author Nicholas Uth
*	Written for CSE 274 on Sept 19, 2012.
*	
*	
*/

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Node.h"
#include "Circle_NickVer.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW2_NickApp : public AppBasic {
  public:
	void setup();
	// mouse click selects a node if it's within the appropriate circle's radius
	void mouseDown( MouseEvent event );	
	void keyDown (KeyEvent event);
	void update();
	void draw();
	void prepareSettings(Settings* settings);

  private:
	Surface* mySurface_;
	Node* sentinelNode; // the sentinel node
	Node* loopNode; //current node of a loop
	Node* selectedNode; //user's currently selected node

	int numCircles;
	Circle_NickVer* circles;

	//interaction helper variables
	float mouseX;
	float mouseY;
	static const int movementInterval = 15; //the number of pixels a circle moves when prompted
			//NOTE!! --> must be cast as a float when used in circle functions

	//Width and height of the screen
	static const int kAppWidth=1100;
	static const int kAppHeight=600;
	static const int kTextureSize=1024; // must be power of 2
};

void HW2_NickApp::prepareSettings(Settings* settings)
{
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);
}

void HW2_NickApp::setup()
{
	mySurface_ = new Surface(kTextureSize,kTextureSize,false);

	// set up the linked list by creating the sentinel
	sentinelNode = new Node();
	sentinelNode->next = sentinelNode; //done so that the add before and after methods will work properly
	sentinelNode->previous = sentinelNode;

	//set up the circles
	numCircles = 6;
	circles = new Circle_NickVer[numCircles];
	circles[0] = Circle_NickVer(300, 300, 45, 255, 0, 0);
	circles[1] = Circle_NickVer(400, 300, 45, 0, 255, 0);
	circles[2] = Circle_NickVer(500, 300, 45, 0, 0, 255);
	circles[3] = Circle_NickVer(600, 300, 45, 100, 100, 0);
	circles[4] = Circle_NickVer(700, 300, 45, 100, 0, 100);
	circles[5] = Circle_NickVer(800, 300, 45, 0, 100, 100);
	
	// set up the linked list nodes
	for (int i = 0; i < numCircles; i++)
	{
		sentinelNode->addBefore(sentinelNode, &(circles[i]));
	}
}

void HW2_NickApp::mouseDown( MouseEvent event )
{
	// on mouse click, get mouse coords (as float) run loop through all nodes' circles and check if isInside
	// if true, then set it as the selected node.
	mouseX = (float) event.getX();
	mouseY = (float) event.getY();
	Node* temp = sentinelNode->next;
	while (temp != sentinelNode)
	{
		if (temp->circle->isInside(mouseX, mouseY))
		{
			selectedNode = temp;
			return;
		}
		temp = temp->next;
	}
	selectedNode = NULL;
}

void HW2_NickApp::keyDown(KeyEvent event)
{
	//TODO: '?' brings up help bar/window

	//if a node == selected, then can do the following
	if (selectedNode != NULL)
	{
		//arrow keys change the center's X,Y coords
		if (event.getCode() == event.KEY_UP)
		{
			selectedNode->circle->center.y -= (float) movementInterval; //decrement because of +Y being 'downward'
		}
		if (event.getCode() == event.KEY_DOWN)
		{
			selectedNode->circle->center.y += (float) movementInterval; //increment because of +Y being 'downward'
		}
		if (event.getCode() == event.KEY_LEFT)
		{
			selectedNode->circle->center.x -= (float) movementInterval;
		}
		if (event.getCode() == event.KEY_RIGHT)
		{
			selectedNode->circle->center.x += (float) movementInterval;
		}
		//Z sends it back 1 lv
		if (event.getCode() == event.KEY_z)
		{
			selectedNode->swapNodes(selectedNode, false);
		}
		// X sends it forward 1 lv
		if (event.getCode() == event.KEY_x)
		{
			selectedNode->swapNodes(selectedNode, true);
		}
		//TODO: C flips the list
	}
}

void HW2_NickApp::update()
{
	
	
}

void HW2_NickApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 

	//start @ sentinel node... loop BACKWARDS till you get back to it and draw each node along the way
	loopNode = sentinelNode->next;
	while(loopNode->next != sentinelNode->next)
	{
		gl::color(loopNode->circle->color);
		gl::drawSolidCircle(loopNode->circle->center, loopNode->circle->radius, 0);
		loopNode = loopNode->next;
	}
}

CINDER_APP_BASIC( HW2_NickApp, RendererGl )
