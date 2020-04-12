#include "ofApp.h"

int rand_sign()
{
    int result;
    if (rand()%2==1) result=1;
    else result=-1;
    return(result);
}
//--------------------------------------------------------------
void ofApp::setup(){
    x=500;
    y=500;
    xnew=500;
    ynew=500;
    r=0;
    g=0;
    b=0;
    ofBackground(255,255,255,255);
    ofSetBackgroundAuto(FALSE);
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (rand()%2==0)
    {
    xnew=x+5*rand_sign();
    if (xnew > ofGetWidth()) xnew = ofGetWidth();
    if (xnew < 0) xnew = 0;
    }

    else
    {
        ynew=y+5*rand_sign();
        if(ynew > ofGetWidth()) ynew = ofGetWidth();
        if(ynew < 0) ynew = 0;
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
ofLine(x,y,xnew,ynew);
ofSetColor(r,g,b);
x=xnew;
y=ynew;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
if(key=='x')
{
    ofImage img;
    glReadBuffer(GL_FRONT);
    img.grabScreen(0,0,ofGetWidth(),ofGetHeight());
    img.saveImage("screenshot.png");
}
if(key=='a')
{
    r=rand()%255;
    g=rand()%255;
    b=rand()%255;
}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
