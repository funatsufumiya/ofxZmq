#include "ofApp.h"


ofxZmqSubscriber client;

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
	// start client
//	client.bind("tcp://*:9999");
    client.connect("tcp://127.0.0.1:9999");
	
	// start client
//	client.connect("tcp://rpi3.local:9999");
}

//--------------------------------------------------------------
void ofApp::update()
{
	while (client.hasWaitingMessage())
	{
		ofBuffer data;
		client.getNextMessage(data);
		
        ofLog() << "client RECEIVED: " << data;
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
    if(ofGetFrameNum() % 100 == 0)
    {
        if(!client.isConnected())
        {
            ofLog() << "NOT CONNECTED";
        }
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
