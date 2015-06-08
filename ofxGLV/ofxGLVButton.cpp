#include "ofxGLVButton.h"

namespace glv {

ofxGLVButton::ofxGLVButton(const Rect& r /*= Rect()*/, iconFunc on /*= draw::rectangle*/, iconFunc off /*= 0*/)
	: Widget(r, 3, true, false, true), mIconOff(off), mIconOn(on)
{
	data().resize(Data::BOOL, 1, 1);
	useInterval(false);
}

ofxGLVButton::~ofxGLVButton()
{

}

void ofxGLVButton::onDraw(GLV& g)
{
	Widget::onDraw(g);

	using namespace glv::draw;

	float xd = dx();
	float yd = dy();
	float p1 = padding();
	float p_2 = padding()*0.5;
	color(colors().fore);

	// TODO: small buttons hard to see when not antialiased
	//glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	//draw::enable(PolygonSmooth);

	float x = 0 + p_2;
	float y = 0 + p_2;
	if (getValue())
	{
		if (mIconOn) 
			mIconOn(x, y, x + xd - p1, y + yd - p1);
	}
	else
	{
		if (mIconOff) 
			mIconOff(x, y, x + xd - p1, y + yd - p1);
	}

	//draw::disable(PolygonSmooth);
}

bool ofxGLVButton::onEvent(Event::t e, GLV& g){
	Widget::onEvent(e, g);

	switch (e){
	case Event::MouseDown:
		if (g.mouse().left()){
			selectFromMousePos(g);
			setValue(true);
			return false;
		}
		break;
	case Event::MouseUp: 
		{
			setValue(false);
			ofNotifyEvent(buttonEvent, this);				// send of event
			return false;
		}

	default: break;
	}
	return true;
}

}