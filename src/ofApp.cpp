#include "ofApp.h"

float startTime = -1.0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofIcoSpherePrimitive tempCube;
    cube = tempCube.getMesh();
    ofLog(ofLogLevel::OF_LOG_NOTICE, ofToString(cube.getVertices()));
    ofLog(ofLogLevel::OF_LOG_NOTICE, ofToString(cube.getIndices()));
    ofLog(ofLogLevel::OF_LOG_NOTICE, ofToString(cube.getMode()));
    sphereShader.load("shaders/shader1Vert.c", "shaders/shader1Frag.c");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    sphereShader.begin();
    sphereShader.setUniform1f("ellapsedTime", ofGetElapsedTimef());
    sphereShader.setUniform1f("startTime", startTime);
    
    cube.drawWireframe();
//    cube.draw();
    sphereShader.end();
    
    ofSpherePrimitive temp;
    temp.setRadius(1);
    temp.setPosition(100, 100, 100);
    temp.draw();
    
    cam.end();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofLog(ofLogLevel::OF_LOG_NOTICE, ofToString(key));
    startTime = ofGetElapsedTimef();
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
