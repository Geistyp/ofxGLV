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
		SymbolFunc on = draw::rectangle, SymbolFunc off = 0);
	~ofxGLVButton();

	/// Get off state symbol
	const SymbolFunc& symbolOff() const { return mSymOff; }

	/// Get on state symbol
	const SymbolFunc& symbolOn() const { return mSymOn; }

	/// Set off state icon
	ofxGLVButton& symbol(const SymbolFunc& f){ mSymOff = f; return *this; }

	/// Set on state icon
	ofxGLVButton& symbolOn(const SymbolFunc& f){ mSymOn = f; return *this; }

	virtual const char * className() const { return "EventButton"; }
	virtual void onDraw(GLV& g);
	virtual bool onEvent(Event::t e, GLV& g);

	bool getValue() const { return Widget::getValue<bool>(); }

	ofEvent<void> buttonEvent;

protected:
	SymbolFunc mSymOff, mSymOn;
	

};

} // glv::