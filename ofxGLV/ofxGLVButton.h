//  [GeistYp]

#pragma once

#include "ofEvents.h"

#include "glv_core.h"
#include "glv_icon.h"
#include "glv_widget.h"

namespace glv {

// Event trigger button
class ofxGLVButton : public Widget
{
public:
	ofxGLVButton(const Rect& r = Rect(),
		iconFunc on = draw::rectangle, iconFunc off = 0);
	~ofxGLVButton();

	/// Get off state icon
	const iconFunc& iconOff() const { return mIconOff; }

	/// Get on state icon
	const iconFunc& iconOn() const { return mIconOn; }

	/// Set off state icon
	ofxGLVButton& iconOff(const iconFunc& f){ mIconOff = f; return *this; }

	/// Set on state icon
	ofxGLVButton& iconOn(const iconFunc& f){ mIconOn = f; return *this; }

	virtual const char * className() const { return "EventButton"; }
	virtual void onDraw(GLV& g);
	virtual bool onEvent(Event::t e, GLV& g);

	bool getValue() const { return Widget::getValue<bool>(); }

	ofEvent<void> buttonEvent;

protected:
	iconFunc mIconOff, mIconOn;
	

};

} // glv::