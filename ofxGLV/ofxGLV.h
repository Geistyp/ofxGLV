//  [GeistYp]
// http://mat.ucsb.edu/glv/

#pragma once

#include "glv.h"
using namespace glv;

class ofxGLV
{
public:

	ofxGLV(){
		mGLV = NULL;
	}

	~ofxGLV(){
		if (mGLV) mGLV->broadcastEvent(Event::Quit);
	}

	//-- convert to glv
	void modToGLV(GLV* g)
	{
		if (g){
			const_cast<Keyboard *>(&g->keyboard())->alt(ofGetKeyPressed(OF_KEY_ALT));
			const_cast<Keyboard *>(&g->keyboard())->ctrl(ofGetKeyPressed(OF_KEY_CONTROL));
			const_cast<Keyboard *>(&g->keyboard())->shift(ofGetKeyPressed(OF_KEY_SHIFT));
		}
	}

	void keyToGLV(GLV* g, unsigned int key, bool down){
		if (g)
		{
			bool special = false;
#define CS(oF, glv) case OF_KEY_##oF: key = Key::glv; special = true; break;
			switch (key)
			{
				CS(LEFT, Left) CS(UP, Up) CS(RIGHT, Right) CS(DOWN, Down)
					CS(PAGE_UP, PageUp) CS(PAGE_DOWN, PageDown)
					CS(HOME, Home) CS(END, End) CS(INSERT, Insert)

					CS(F1, F1) CS(F2, F2) CS(F3, F3) CS(F4, F4)
					CS(F5, F5) CS(F6, F6) CS(F7, F7) CS(F8, F8)
					CS(F9, F9) CS(F10, F10)	CS(F11, F11) CS(F12, F12)
			}
#undef CS
			if (!special)
			{
				// useless ?
#define MAP(i,o) case i: key=o; break
#undef MAP
			}
			down ? g->setKeyDown(key) : g->setKeyUp(key);
			modToGLV(g);
			g->propagateEvent();
		}
	}

	void motionToGLV(GLV* g, int ax, int ay, glv::Event::t e){
		if (g){
			space_t x = (space_t)ax;
			space_t y = (space_t)ay;
			space_t relx = x;
			space_t rely = y;

			g->setMouseMotion(relx, rely, e);
			g->setMousePos((int)x, (int)y, relx, rely);
			g->propagateEvent();
		}
	}

	void MouseDown(GLV* g, int btn, int state, int ax, int ay){
		if (g){
			space_t x = (space_t)ax;
			space_t y = (space_t)ay;
			space_t relx = x;
			space_t rely = y;

			switch (btn){
			case OF_MOUSE_BUTTON_LEFT:		btn = Mouse::Left; break;
			case OF_MOUSE_BUTTON_MIDDLE:	btn = Mouse::Middle; break;
			case OF_MOUSE_BUTTON_RIGHT:		btn = Mouse::Right; break;
			default:					btn = Mouse::Extra;		// unrecognized button
			}

			g->setMouseDown(relx, rely, btn, 0);

			g->setMousePos((int)x, (int)y, relx, rely);
			modToGLV(g);
			g->propagateEvent();
		}
	}

	void MouseUp(GLV* g, int btn, int state, int ax, int ay){
		if (g){
			space_t x = (space_t)ax;
			space_t y = (space_t)ay;
			space_t relx = x;
			space_t rely = y;

			switch (btn){
			case OF_MOUSE_BUTTON_LEFT:		btn = Mouse::Left; break;
			case OF_MOUSE_BUTTON_MIDDLE:	btn = Mouse::Middle; break;
			case OF_MOUSE_BUTTON_RIGHT:		btn = Mouse::Right; break;
			default:					btn = Mouse::Extra;		// unrecognized button
			}

			g->setMouseUp(relx, rely, btn, 0);

			g->setMousePos((int)x, (int)y, relx, rely);
			modToGLV(g);
			g->propagateEvent();
		}
	}

	//- of event
	void RegisterEvents()
	{
		ofRegisterKeyEvents(this);
		ofRegisterMouseEvents(this);
	}
	void UnRegisterEvents()
	{
		ofUnregisterKeyEvents(this);
		ofUnregisterMouseEvents(this);
	}

	void keyPressed(ofKeyEventArgs & key){
		keyToGLV(mGLV, key.key, true);
	}
	void keyReleased(ofKeyEventArgs & key){
		keyToGLV(mGLV, key.key, false);
	}

	void mouseMoved(ofMouseEventArgs & mouse){
		motionToGLV(mGLV, mouse.x, mouse.y, Event::MouseMove);
	}
	void mouseDragged(ofMouseEventArgs & mouse){
		motionToGLV(mGLV, mouse.x, mouse.y, Event::MouseDrag);
	}
	void mousePressed(ofMouseEventArgs & mouse){
		MouseDown(mGLV, mouse.button, 0, mouse.x, mouse.y);
	}
	void mouseReleased(ofMouseEventArgs & mouse){
		MouseUp(mGLV, mouse.button, 0, mouse.x, mouse.y);
	}
	void mouseScrolled(ofMouseEventArgs & mouse){
		
	}

	//--
	void setup(int w, int h)
	{
		width = w;
		height = h;
		mGLV = new GLV(0, width, height);
		RegisterEvents();
	}

	void draw()
	{
		if (mGLV) mGLV->drawGLV(width, height, ofGetFrameRate());
	}

	//--
	GLV* operator()(){ return mGLV; }

	GLV *mGLV;
	int width;
	int height;
};