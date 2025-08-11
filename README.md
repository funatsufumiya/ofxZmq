# ofxZmq

Using zmq 4.1.3. ZeroMQ (ZMQ) Library for OpenFrameworks. Tested on 0.11.0 - 0.12.0

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

## License

- ofxZmq: [MIT License](./LICENSE)
- [cppzmq](https://github.com/zeromq/cppzmq): [MIT License](https://github.com/zeromq/cppzmq/blob/master/LICENSE)
- [libzmq](https://github.com/zeromq/libzmq): [Mozilla Public License 2.0](https://github.com/zeromq/libzmq/blob/master/LICENSE) (please also check [https://zeromq.org/license/](https://zeromq.org/license/))