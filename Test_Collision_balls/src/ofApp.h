#pragma once

#include "ofMain.h"
#include "basicParticle.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
		//Imagees
		ofImage background;
		ofImage particle;
		ofImage particleWatta;
		//Sounds
		ofSoundPlayer crown;
		ofSoundPlayer calm;
		ofSoundPlayer wattaSoundFile;
		ofSoundPlayer saturn;
		ofSoundPlayer pop;
		//Graphical User Interface
		ofxPanel gui;
		ofParameter<int> numBalls;

		//tmpBall of basicParticle class generating balls in setup
		basicParticle tmpBall;
		//creating a vector of the ball class
		vector <basicParticle> balls;


		int i, k;
		//int numBalls;
		int height, width;


		//making the collision
		//calculate each particle with all other particles
		ofVec2f pDist;
		float pLen;
		float radiusTotal;
		//float amntOverlapped;

		//toggle color flag variables
		int isUsing;

		//mouse Repulsion Radius
		ofParameter<int> repulsionRadius;
		//int repulsionRadiusFlag;
		//int repulsionRadius;

		//mouse radius drawing
		ofParameter<int> mouseRadiusFlag;
		//int mouseRadiusFlag;
		int mousePosX, mousePosY;
		
};
