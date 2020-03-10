#pragma once

#include "ofMain.h"
#include "Note.h"
#include "ofxMidi.h"
#include "ofxImageSequenceRecorder.h"


class ofApp : public ofBaseApp, public ofxMidiListener {
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // recording
    void toggleRecording();
    void captureScreen();
    
    // MIDI
    void newMidiMessage(ofxMidiMessage& eventArgs);
private:
    ofMesh cube;
    ofEasyCam cam;
    ofShader sphereShader;
    vector<Note> notes;
    
    //32 bits red, 32 bits green, 32 bits blue, from 0 to 1 in 'infinite' steps
    ofFbo rgbaFboFloat; // with alpha
    
    // recording
    ofxImageSequenceRecorder recorder;
    bool recording;
    ofImage screenCapture;
    
    // midi
    ofxMidiIn midiIn;
    
    
};


