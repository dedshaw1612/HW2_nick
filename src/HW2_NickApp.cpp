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
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);

  private:
	Surface* mySurface_;
	Node* sentinelNode; // the sentinel node
	Node* selectedNode; //user's currently selected node

	Circle_NickVer* circle1;
	Circle_NickVer* circle2;
	Circle_NickVer* circle3;
	Circle_NickVer* circle4;
	Circle_NickVer* circle5;
	Circle_NickVer* circle6;

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

	//set up the circles
	circle1 = new Circle_NickVer(300, 300, 45, 255, 0, 0);
	circle2 = new Circle_NickVer(400, 300, 45, 0, 255, 0);
	circle3 = new Circle_NickVer(500, 300, 45, 0, 0, 255);
	circle4 = new Circle_NickVer(600, 300, 45, 100, 100, 0);
	circle5 = new Circle_NickVer(700, 300, 45, 100, 0, 100);
	circle6 = new Circle_NickVer(800, 300, 45, 0, 100, 100);
	
	// set up the linked list nodes
	(*sentinelNode).addAfter();

}

void HW2_NickApp::mouseDown( MouseEvent event )
{
	//TODO: mouse click selects a node

	//if a node == selected
	//TODO: arrow keys change the center's X,Y coords
	//TODO: Z sends it back 1 lv
	//TODO: X sends it forward 1 lv
}

void HW2_NickApp::update()
{
	
	
}

void HW2_NickApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 

	// Test run at drawing a circle
	//Vec2f center;
	//center.x = 100;
	//center.y = 150;
	//gl::color(0,250,250,250); //changes the color of the circle drawn
	//gl::drawSolidCircle(center, 70, 0); //draws a circle

	//Test --> checks out a-okay
	gl::color(circle1->color);
	gl::drawSolidCircle(circle1->center, circle1->radius, 0);
	gl::color(circle2->color);
	gl::drawSolidCircle(circle2->center, circle2->radius, 0);
	gl::color(circle3->color);
	gl::drawSolidCircle(circle3->center, circle3->radius, 0);
	gl::color(circle4->color);
	gl::drawSolidCircle(circle4->center, circle4->radius, 0);
	gl::color(circle5->color);
	gl::drawSolidCircle(circle5->center, circle5->radius, 0);
	gl::color(circle6->color);
	gl::drawSolidCircle(circle6->center, circle6->radius, 0);

	//TODO: start @ sentinel node... loop BACKWARDS till you get back to it and draw each node along the way
}

CINDER_APP_BASIC( HW2_NickApp, RendererGl )
