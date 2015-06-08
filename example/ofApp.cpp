#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
		textbox = ofPtr<TextView>(new TextView(Rect(250, 16)));
		textbox->setValue("this is a text box");
	}
	{
		numbox = ofPtr<NumberDialer>(new NumberDialer(4, 4, 9999, -9999));
		numbox->setValue(50.0);
	}
	{
		sliderLabel = ofPtr<Label>(new Label("Slider Value:"));
		slider = ofPtr<Slider>(new Slider(Rect(200, 20)));
		slider->attach(ntSetLabel, Update::Value, &*sliderLabel);
	}
	{
		checkbox = ofPtr<Button>(new Button(Rect(50, 20), false));
	}
	{
		selector = ofPtr<Buttons>(new Buttons(Rect(80), 2, 2, false, true));
	}
	{
		button = ofPtr<ofxGLVButton>(new ofxGLVButton(Rect(80, 30)));
		ofAddListener(button->buttonEvent, this, &ofApp::buttonHitted);
	}

	// assign to layout
	mylayout << new Label("Text:") << *textbox
		<< new Label("Number Dialer:") << *numbox
		<< *sliderLabel << *slider
		<< new Label("Check box:") << *checkbox
		<< new Label("Selector:") << *selector
		<< new Label("Button:") << *button;
}

void ofApp::drawGUI(ofEventArgs & args)
{
	myGLV.draw();
}

void ofApp::buttonHitted(void)
{
	//cout << "button press" << endl;
}