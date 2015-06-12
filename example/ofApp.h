#pragma once

#include "ofMain.h"
#include "ofxGLV.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void setupGUI();
		void drawGUI(ofEventArgs & args);

		void buttonHitted(void);

		//--
		ofxGLV myGLV;

		Placer mylayout;

		shared_ptr<TextView>		textbox;
		shared_ptr<NumberDialer>	numbox;
		shared_ptr<Slider>			slider;
		shared_ptr<Label>			sliderLabel;
		shared_ptr<Button>			checkbox;
		shared_ptr<Buttons>			selector;
		shared_ptr<ofxGLVButton>	button;
		shared_ptr<ColorPicker>		colorPicker;
		shared_ptr<ColorSliders>    colorSlider;
		glv::Color					vColor;
		shared_ptr<DropDown>		dropdown;
		int							selectedItem;
};
