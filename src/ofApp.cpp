#include "ofApp.h"

float sphereStartTime = -1.0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofSetFrameRate(30);
    
    ofIcoSpherePrimitive tempCube;
    cube = tempCube.getMesh();
    ofLog(ofLogLevel::OF_LOG_NOTICE, ofToString(cube.getVertices()));
    ofLog(ofLogLevel::OF_LOG_NOTICE, ofToString(cube.getIndices()));
    ofLog(ofLogLevel::OF_LOG_NOTICE, ofToString(cube.getMode()));
    sphereShader.load("shaders/shader1Vert.c", "shaders/shader1Frag.c");
    
//#ifdef TARGET_OPENGLES
//    rgbaFboFloat.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA ); // with alpha, 8 bits red, 8 bits green, 8 bits blue, 8 bits alpha, from 0 to 255 in 256 steps
//    ofLogWarning("ofApp") << "GL_RGBA32F_ARB is not available for OPENGLES.  Using RGBA.";
//#else
    rgbaFboFloat.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); // with alpha, 32 bits red, 32 bits green, 32 bits blue, 32 bits alpha, from 0 to 1 in 'infinite' steps
//#endif
    
    rgbaFboFloat.begin();
    ofClear(0,0,0,255);
    rgbaFboFloat.end();
    
    //recording setup
    recorder.setPrefix(ofToDataPath("recording/frame_"));
    recorder.setNumberWidth(8);
    recorder.setFormat("png");
    recorder.startThread();
    
    // midi setup
    midiIn.openPort(0);
    midiIn.addListener(this);
}

//--------------------------------------------------------------
void ofApp::update(){
    // show the framerate on window title
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
    
    
    for (auto it = notes.begin(); it!=notes.end(); it++) {
        it->update();
    }
    
    
    
    rgbaFboFloat.begin();
    
    //1 - Fade Fbo
    int fadeAmnt = 40;
    //this is where we fade the fbo
    //by drawing a rectangle the size of the fbo with a small alpha value, we can slowly fade the current contents of the fbo.
    ofFill();
    ofSetColor(0,0,0, fadeAmnt);
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    //2 - Draw graphics
    
    ofNoFill();
    ofSetColor(255,255,255);
    
    //we draw a cube in the center of the fbo and rotate it based on time
    cam.begin();
    ofPushMatrix();
    ofRotateDeg(ofGetFrameNum()/2);
    sphereShader.begin();
    sphereShader.setUniform1f("ellapsedTime", ofGetElapsedTimef());
//    sphereShader.setUniform1f("startTime", sphereStartTime);
    cube.drawWireframe();
    sphereShader.end();
    
    ofSetColor(159, 245, 228);
    for (Note note : notes){
        note.draw();
    }
    
    ofPopMatrix();
    cam.end();
    
    
    rgbaFboFloat.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofClear(0,0,0,255);
    ofSetColor(255, 255, 255);
    rgbaFboFloat.draw(0, 0);
    
    // capture the image if recording is started
    // this can slow down the rendering by a lot, so be aware of the framerate...
    // if frames are skipped this is going to mess up the rendering when imported as a video
    if (recording){
        screenCapture.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        recorder.addFrame(screenCapture);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'q':
            sphereStartTime = ofGetElapsedTimef();
            break;
        case 'w':
            notes.push_back(Note(ofRandom(200) - 100, ofRandom(200) - 100, ofRandom(200) - 100, 1));
            break;
        case 'r':
            toggleRecording();
            break;
        default:
            break;
    }
}

void ofApp::exit(){
    recorder.waitForThread();
    recorder.stopThread();
}

void ofApp::newMidiMessage(ofxMidiMessage& eventArgs){
    // piano
    if (eventArgs.channel == 1){
        notes.push_back(Note(ofRandom(200) - 100, ofRandom(200) - 100, ofRandom(200) - 100, 1));
    }
}

void ofApp::toggleRecording(){
    recording = !recording;
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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


