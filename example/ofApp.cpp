#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofDrawBitmapString("Press '1-9' to save preset", 10, 12);
	ofDrawBitmapString("Press Alt + '1-9' to load preset", 10, 24);
	ofDrawBitmapString("Press 's' to save and 'l' to load", 10, 36);

	//ofDrawBitmapString(textbox->getValue(), 100, 100);
	//ofDrawBitmapString(ofToString(numbox->getValue()), 100, 120);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key >= '1' && key <= '9')
	{
		int k = key - '1';
		if (!ofGetKeyPressed(OF_KEY_ALT))
			myGLV.saveSnapshot("preset" + ofToString(k));
		else
		{
			if (!myGLV.loadSnapShot("preset" + ofToString(k)))
			{
				ofLogError() << "preset" + ofToString(k) << " not exist ";
			}
		}
	}
	if (key == 's') myGLV.saveToFile("glv.txt");		// save snapshot first
	if (key == 'l') myGLV.loadFromFile("glv.txt");

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

// update slider label
void ntSetLabel(const Notification& n){
	Label& l = *n.receiver<Label>();
	Slider& s = *n.sender<Slider>();
	l.setValue("Slider Value:" + s.data().toString());
}

//////////////////////////////////////////////////////////////////////////
/*
 *	Don't use space in ui widget's name, will cause save snapshot error
 *	eg 
 *		wrong: textbox->name("Text Box") 
 *		right: textbox->name("TextBox")
 */
void ofApp::setupGUI()
{
	// style
	glv::Style::standard().color.set(StyleColor::SmokyGray);

	// 
	myGLV.setup(300, 768);

	// create layout
	mylayout = Placer(*myGLV(), Direction::S, Place::TL, 10, 10);

	// create element
	{
		textbox = shared_ptr<TextView>(new TextView(glv::Rect(250, 16)));
		textbox->setValue("this is a text box").name("TextBox");
	}
	{
		numbox = shared_ptr<NumberDialer>(new NumberDialer(4, 4, 9999, -9999));
		numbox->setValue(50.0).name("NumBox");
	}
	{
		sliderLabel = shared_ptr<Label>(new Label("SliderValue:"));
		slider = shared_ptr<Slider>(new Slider(glv::Rect(200, 20)));
		slider->attach(ntSetLabel, Update::Value, &*sliderLabel);
		sliderLabel->name("SliderValue");
		slider->name("Slider");
	}
	{
		checkbox = shared_ptr<Button>(new Button(glv::Rect(50, 20), false));
		checkbox->name("CheckBox");
	}
	{
		selector = shared_ptr<Buttons>(new Buttons(glv::Rect(80), 2, 2, false, true));
		selector->name("Selector");
	}
	{
		button = shared_ptr<ofxGLVButton>(new ofxGLVButton(glv::Rect(80, 30)));
		ofAddListener(button->buttonEvent, this, &ofApp::buttonHitted);
		// we dont need to save button state in preset
		//button->name("Button"); 
	}

	// assign to layout
	mylayout << new Label("Text:") << *textbox
		<< new Label("Number Dialer:") << *numbox
		<< *sliderLabel << *slider
		<< new Label("Check box:") << *checkbox
		<< new Label("Selector:") << *selector
		<< new Label("Button:") << *button;

	myGLV.refresh();
}

void ofApp::drawGUI(ofEventArgs & args)
{
	myGLV.draw();
}

void ofApp::buttonHitted(void)
{
	//cout << "button press" << endl;
}