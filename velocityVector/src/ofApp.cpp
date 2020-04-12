#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

    ofSetWindowTitle("D'f you just say?");
    //Basic Background and Rand Generators
    srand(time(NULL));
    ofBackground(0,0,0);



    //PLAYER 1 setting player initial position in the middle of the screen
    fullX = ofGetWidth();
    fullY = ofGetHeight();
    x = fullX/2;
    y = fullY/2;

    player1Color.set(0,0,255);
    player1.set(x,y,10,10);
    velX = 0;
    velY = 0;
}

//--------------------------------------------------------------
void ofApp::update()
{
    //PLAYER 1

    x += velX;
    y += velY;

    //Border Control
        //Player 1
    if(x<0)   x=0;
    if(y<0)   y=0;
    if(x>ofGetWidth()-25) x=ofGetWidth()-25;
    if(y>ofGetHeight()-25) y=ofGetHeight()-25;
}

//--------------------------------------------------------------
void ofApp::draw()
{
        //PLAYER 1: RED
    ofSetColor(255,0,0);
    ofRect(x,y,25,25);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    //PLAYER 1
    if (key == OF_KEY_LEFT)     velX = -1.5;
    if (key == OF_KEY_RIGHT)    velX = +1.5;
    if (key == OF_KEY_UP)       velY = -1.5;
    if (key == OF_KEY_DOWN)     velY = +1.5;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    //PLAYER 1

    if (key == OF_KEY_LEFT)     velX = 0;
	if (key == OF_KEY_RIGHT)    velX = 0;
	if (key == OF_KEY_UP)       velY = 0;
	if (key == OF_KEY_DOWN)     velY = 0;

	/*
	if (key == OF_KEY_LEFT)
    {
        if(velX <= 0) velX = velX + 0.01;
    }
	if (key == OF_KEY_RIGHT)
    {
        if(velX >= 0) velX = velX - 0.01;
    }
	if (key == OF_KEY_UP)
    {
        if(velY <=0)    velY = velY + 0.01;
    }
	if (key == OF_KEY_DOWN)
    {
        if(velY >=0)    velY = velX - 0.01;
    }
    */
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
