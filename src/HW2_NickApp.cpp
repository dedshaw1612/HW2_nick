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
	Node* sentinelNode;

	//Width and height of the screen
	static const int kAppWidth=800;
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
}

void HW2_NickApp::mouseDown( MouseEvent event )
{
}

void HW2_NickApp::update()
{
	
	
}

void HW2_NickApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 

	// Test run at drawing a circle
	Vec2f center;
	center.x = 100;
	center.y = 150;
	gl::color(0,250,250,250); //changes the color of the circle drawn
	gl::drawSolidCircle(center, 70, 0); //draws a circle
}

CINDER_APP_BASIC( HW2_NickApp, RendererGl )
