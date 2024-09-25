# ofxZmq

## Usage

```cpp
ofxZmqSubscriber subscriber;
ofxZmqPublisher publisher;

void ofApp::setup()
{
	// start server
	publisher.bind("tcp://*:9999");
	
	// start client
	subscriber.connect("tcp://localhost:9999");
}

void ofApp::update()
{
	while (subscriber.hasWaitingMessage())
	{
		ofBuffer data;
		subscriber.getNextMessage(data);
		
		cout << "received data: " << data << endl;
	}
}

void ofApp::keyPressed(int key)
{
	if (!publisher.send("this is a test"))
	{
		cout << "send failed" << endl;
	}
}
```