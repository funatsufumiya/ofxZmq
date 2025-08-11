#include "ofApp.h"


ofxZmqRequest req;

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
	// start client
//	req.bind("tcp://*:9999");
    req.connect("tcp://127.0.0.1:9999");
	
	// start client
//	req.connect("tcp://rpi3.local:9999");
}

//--------------------------------------------------------------
void ofApp::update()
{
	while (req.hasWaitingMessage())
	{
		ofBuffer data;
        req.getNextMessage(data);
		
        ofLog() << "RECEIVED from REP: " << data;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    if(req.isConnected())
    {
        if(ofGetFrameNum() % 100 == 0)
        {
            string message  = "Hello From REQ: " + ofToString(ofGetFrameNum());
            if (!req.send(message))
            {
                ofLogError() << "SEND FAILED message: " << message;
            }else
            {
                ofLog() << "SENT message: " << message;
                
            }
        }
    }else
    {
        ofLog() << "NOT CONNECTED";
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
