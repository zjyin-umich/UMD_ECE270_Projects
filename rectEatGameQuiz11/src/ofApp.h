#pragma once

#include "ofMain.h"
#define MAX_NUM_FOOD 100

class ofApp : public ofBaseApp{

	public:

		ofSoundPlayer sound1;


        float count1=1.5;

		int i;
        int playersize;
        ofRectangle player;
        ofRectangle food[100];
        int foodsize[100];
        ofColor foodcolor[100];
        ofColor playercolor;
        int isVisible[100];
        int playerX = 500;
        int playerY = 500;
        int height = 10;
        int width = 10;



		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

};
