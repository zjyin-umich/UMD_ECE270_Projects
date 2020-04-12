#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:

        int numSamples,i,n;
		float xmin,xmax,ymin, ymax, step, alpha, w;
		float x[1000], y[1000],xPix[1000],yPix[1000];

		float yGrid[16],xGrid[19],xGridSize, yGridSize;
		const char *xAxis[19] = {"2/8/17","2/9","2/13","2/14","2/15","2/16","2/17","2/21","2/22","2/23","2/24","2/25","2/26","2/27","3/1","3/2","3/3","3/6","3/7/17"};
		const char *yAxis[16]={"45.0","45.1","45.2","45.3","45.4","45.5","45.6","45.7","45.8","45.9","46.0","46.1","46.2","46.3","46.4","46.5"};
        //char xAxis[21];
        //char yAxis[9];
        void printMyArray(int n, float x[], char label[]);
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
