#include "ofApp.h"


ofxZmqReply rep;

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel(OF_LOG_VERBOSE);
    
	// start server
    rep.bind("tcp://*:9999");

}

//--------------------------------------------------------------
void ofApp::update()
{
	while (rep.hasWaitingMessage())
	{
		ofBuffer data;
        rep.getNextMessage(data);
		
        ofLog() << "REQ RECEIVED: " << data;
        
        if(rep.isConnected())
        {
            string response  = "Response Message From REP";
            if (!rep.send(response))
            {
                ofLogError() << "SEND FAILED message: " << response;
            }else
            {
                ofLog() << "SENT message: " << response;
                
            }
        }else
        {
            ofLogError() << "REQ/REP NOT CONNECTED: " << data;

        }
        
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
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
