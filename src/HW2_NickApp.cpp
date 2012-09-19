#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "HW2_Nick.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW2_NickApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HW2_NickApp::setup()
{
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
}

CINDER_APP_BASIC( HW2_NickApp, RendererGl )
