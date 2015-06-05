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

		//--
		ofxGLV myGLV;

		Placer mylayout;

		ofPtr<TextView>		textbox;
		ofPtr<NumberDialer>	numbox;
		ofPtr<Slider>		slider;
		ofPtr<Label>		sliderLabel;
		ofPtr<Button>		checkbox;
		ofPtr<Buttons>		selector;
};
