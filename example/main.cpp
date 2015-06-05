#include "ofMain.h"
#include "ofApp.h"

#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){

	ofGLFWWindowSettings settings;
	settings.width = 1024;
	settings.height = 768;
	settings.setPosition(ofVec2f(340, 35));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	// gui window
	settings.width = 300;
	settings.height = 768;
	settings.setPosition(ofVec2f(20, 35));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
	guiWindow->setVerticalSync(false);

	shared_ptr<ofApp> mainApp(new ofApp);
	mainApp->setupGUI();
	ofAddListener(guiWindow->events().draw, mainApp.get(), &ofApp::drawGUI);

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();

}
