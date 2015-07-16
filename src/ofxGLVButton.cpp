#include "ofxGLVButton.h"

namespace glv {

	ofxGLVButton::ofxGLVButton(const Rect& r /*= Rect()*/, SymbolFunc on /*= draw::rectangle*/, SymbolFunc off /*= 0*/)
	: Widget(r, 3, true, false, true), mSymOff(off), mSymOn(on)
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
	float padx = paddingX();
	float pady = paddingY();
	color(colors().fore);

	// TODO: small buttons hard to see when not antialiased
	//glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	//draw::enable(PolygonSmooth);

	draw::stroke(1);

	float x = padx;
	float y = pady;
	if (getValue())
	{
		if (mSymOn) 
			mSymOn(x, y, x + xd - padx * 2, y + yd - pady * 2);
	}
	else
	{
		if (mSymOff) 
			mSymOff(x, y, x + xd - padx * 2, y + yd - pady * 2);
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