#pragma once

#include "ofMain.h"
#include "CD.h"
#include "CDList.h"


class ofApp : public ofBaseApp{

	public:

        //CD OBJECT
		CD myCD;


        //CDLIST OBJECT
		CDList fav;
		int n;

		//DRAWING IMAGE
		int i,xPosition,yPosition;
		int count;
		//ofImage myImage[55];


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
