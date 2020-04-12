#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetWindowTitle("Dank Particle Alignment Physics");
	srand(time(NULL));
	ofSetFrameRate(120);
	//FLAG VARIABLES
	isUsing = 0;
	mouseRadiusFlag = 0;
	//repulsionRadiusFlag = 0;
	//GUI
	
	gui.setup();
	gui.add(numBalls.set("NULL", 40, 0, 300)); //DOSENT WORK(it doesnt link and regenerate)
	gui.add(repulsionRadius.set("Mouse Repulsion Radius", 150, 0, 350));
	
	//image drawing to background
	background.load("background.png");
	particle.load("particle.png");
	particleWatta.load("watta.png");
	//Sound File Names: crown,shootingStars,calm
	crown.load("nwsElectro.mp3");
	calm.load("calm.mp3");
	wattaSoundFile.load("shooting1.mp3");
	saturn.load("saturn.mp3");
	pop.load("pop.mp3");
	//-----------VOLUME-----------
	crown.setVolume(0.50f);	//Dvorak Syphony Number 9, New world
	calm.setVolume(0.50f);	//Astroneer ambient SoundTrack
	wattaSoundFile.setVolume(0.50f);	//Shooting Stars - Bag riders
	saturn.setVolume(0.50f);			//Apollo Cosmos
	pop.setVolume(0.50f);				//collision pop sound effect
	
	ofBackground(0,0,0);
	ofSetVerticalSync(true); //????????? syncronizes refresh rate of output screen -> monitor screen. Stops screen tearing??
	//numBalls = 60;
	//numBalls.set(60);
	
	height = ofGetWidth();
	width = ofGetWidth();
	
	for (i = 0; i < numBalls; i++)
	{

		tmpBall.setPosition(ofRandom(10, width), ofRandom(10, height));
		tmpBall.setVelocity(ofRandom(-1, 1), ofRandom(-1, 1));
		//tmpBall.setVelocity(2, 2);
		tmpBall.radius = ofRandom(6, 50);
		tmpBall.mass = tmpBall.radius;
		tmpBall.setFriction(1);


			//add new ball into our array(vectoring)
			balls.push_back(tmpBall);
	} 
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (i = 0; i < balls.size(); i++)
	{

		repulsionRadius = 150;
		
		ofVec2f mousePt(mouseX, mouseY);
		ofVec2f distVec = mousePt - balls[i].pos;
		//ofDrawCircle(mousePt, repulsionRadius);
		float straightDist = distVec.length();
		if (straightDist < repulsionRadius)
		{
			
			float pct = straightDist / repulsionRadius;
			float repulsionStrength = (1.0 - pct) * 0.8;
			ofVec2f repulVec = -distVec.normalized();
			repulVec *= ( repulsionStrength * 0.4);
			balls[i].vel += repulVec;
		}
	}

	for (i = 0; i < balls.size(); i++)
	{
		//making the collision
		//calculate each particle with all other particles
		pLen = 0;
		radiusTotal = 0;
		for (k = 0; k < i; k++)
		{
			//checks the collosion of current particle to all particles before it
			//MAKE SURE TO ONLY CHECK COLLISION **ONCE**
			pDist = balls[i].pos - balls[k].pos;

			//to see if they have collided, check if the straight line dist < radius1 + radius2
			radiusTotal = balls[i].radius + balls[k].radius;
			//plen returns line distance between objects
			pLen = pDist.length();

			//this calculates if true, then collision const
			if (pLen < radiusTotal)
			{
				ofPoint n, uN, uT;
				float mag;
				n = balls[i].pos - balls[k].pos;
				mag = n.length();

				uN = (1 / mag) * n;

				uT.set(-uN.y, uN.x);

				float v1n, v1t, v2n, v2t;
				//vector uN and vector balls[i]
				v1n = uN.dot(balls[i].vel);		//v1n
				v1t = uT.dot(balls[i].vel);		//v1t
				v2n = uN.dot(balls[k].vel);		//v2n
				v2t = uT.dot(balls[k].vel);		//v2t

				//new Tangent Velocities
				float v_1t, v_2t;
				v_1t = v1t;		//v'1t
				v_2t = v2t;		//v'2t

				//Normal Velocities
				float v_1n, v_2n;		//v'1n, v'2n
				v_1n = (v1n * (balls[i].mass - balls[k].mass) + (2 * balls[k].mass * v2n)) / (balls[i].mass + balls[k].mass);
				v_2n = (v2n * (balls[k].mass - balls[i].mass) + (2 * balls[i].mass * v1n)) / (balls[i].mass + balls[k].mass);

				//convert scalar normal and tangential velocities into vectors
				ofPoint v_1n_vec, v_1t_vec, v_2n_vec, v_2t_vec;
				//v'1n = v'1n * uN
				v_1n_vec = v_1n * uN;
				//v'1t = v'1t * uT
				v_1t_vec = v_1t * uT;

				//v'2n = v'2n * uN
				v_2n_vec = v_2n * uN;
				//v'2t = v'2t * uT
				v_2t_vec = v_2t * uT;

				//find FINAL VEL VECTOR by adding normal + tangential componenets of each object
				ofPoint v_1, v_2;
				v_1 = v_1n_vec + v_1t_vec;
				v_2 = v_2n_vec + v_2t_vec;

				//setting newly calculated velocity vector to ball velocity
				balls[i].vel = v_1;
				balls[k].vel = v_2;

				if (pLen < 0.5 * radiusTotal)
				{
					//cout << "\ninside line 126: pLen < 0.7 * radiusTotal";
				}

				//if collision happens plays sound(this got annoying after a while)
				/*
				//if isUsing is 1,2,3,4 then play collision sounds 
				if (isUsing == 1 || isUsing == 2 || isUsing == 3 || isUsing == 4)
				{
					int modNum;
					modNum = rand() %100;
					//modNum = 0;
					if (modNum == 0)
					{
						pop.play();
						pop.setMultiPlay(true);
					}
				} */

			}
		}
	}
	//calculations for collision on screen edges
	for (i = 0; i < balls.size(); i++)
	{
		//EDGE - RIGHT PANEL
		if (balls[i].pos.x + balls[i].radius > ofGetWidth())
		{
			balls[i].pos.x = ofGetWidth() - balls[i].radius;	//1. set position to edge
			balls[i].vel.x *= -1;								//2. reverse velocity in X direction
		}
		//EDGE - LEFT PANEL
		if (balls[i].pos.x - balls[i].radius < 0)
		{
			balls[i].pos.x = balls[i].radius;					//1. set position to edge
			balls[i].vel.x *= -1;								//2. reverse velocity in X direction
		}
		//EDGE - bottom rightY
		if (balls[i].pos.y + balls[i].radius > ofGetHeight())
		{
			balls[i].pos.y = ofGetHeight() - balls[i].radius;	//1. set position to edge
			balls[i].vel.y *= -1;								//2. reverse velocity in X direction
		}
		//EDGE - bottom leftY
		if (balls[i].pos.y - balls[i].radius < 0)
		{
			balls[i].pos.y = balls[i].radius;					//1. set position to edge
			balls[i].vel.y *= -1;								//2. reverse velocity in X direction
		}

		
		
		
		
		
		
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofFill();
	//------------------------------
	ofSetColor(255, 255, 255); //standard Set Backup color
	background.draw(0, 0);	//background color
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("----------INSTRUCTIONS----------", 30, 20);
	ofDrawBitmapString("Current Particle Alignment: " + ofToString(isUsing), 30, 40);
	ofSetColor(255, 130, 0);															//Line Color
	ofDrawBitmapString("--------------------------------", 30, 50);						//divider
	ofSetColor(0,0,255);
	ofDrawBitmapString("time: " + ofToString(ofGetElapsedTimef()), 30,60);
	ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 30, 80);
	ofDrawBitmapString("Frame Number: " + ofToString(ofGetFrameNum()), 30, 100);
	ofSetColor(255, 130, 0);															//Line Color
	ofDrawBitmapString("--------------------------------", 30, 110);					//divider
	ofSetColor(255, 255,0);
	ofDrawBitmapString("Press 0: to clear screen", 30, 120);
	ofDrawBitmapString("Press 1: to set partical alignment: DIP 'N DOTS", 30, 140);
	ofSetColor(255, 0, 0);
	ofDrawBitmapString("Press 2: to set partical alignment: PARTICLE FRAME DEBUG", 30, 160);
	ofSetColor(255, 255, 0);
	ofDrawBitmapString("Press 3: to set partical alignment: MICROWATTA", 30, 180);
	ofDrawBitmapString("Press 4: to set partical alignment: OSCILLATION", 30, 200);
	ofSetColor(255, 130, 0);															//Line Color
	ofDrawBitmapString("--------------------------------", 30, 210);					//divider
	ofSetColor(255,100,255);
	ofDrawBitmapString("Move mouse to increase particle velocity", 30, 220);
	ofDrawBitmapString("Move mouse to repel objects from mouse(radius = " + ofToString(repulsionRadius) + " pixel)", 30, 240);
	ofDrawBitmapString("Press LFT_MOUSE_BTN: to REVERSE action", 30, 260);
	ofDrawBitmapString("Press RGHT_MOUSE_BTN: to RESET velocity", 30, 280);
	ofSetColor(255,130, 0);																//Line Color
	ofDrawBitmapString("--------------------------------", 30, 290);					//divider

	//ofSetColor(255,255,255);
	ofFill();
	if (isUsing == 1)
	{
		for (i = 0; i < balls.size(); i++)
		{
			int r, b, g;
			r = ofRandom(0, 255);
			g = ofRandom(0, 255);
			b = ofRandom(0, 255);
			ofSetColor(r, b, g);
			balls[i].draw();
			//balls[i].draw(particle);
		}
	}

	if (isUsing == 2)
	{
		ofSetColor(255, 255, 255);
		for (i = 0; i < balls.size(); i++)
		{
			
			ofSetColor(0, 0, 200);
			balls[i].drawNoFill();
			//balls[i].draw(particle);
		}
	}

	if (isUsing == 3)
	{
		ofSetColor(255, 255, 255);
		for (i = 0; i < balls.size(); i++)
		{
			//balls[i].draw();
			balls[i].draw(particleWatta);
		}
	}
	if (isUsing == 4)
	{
		float value, value2, value3;
		float v, v2, v3;
		float time = ofGetElapsedTimef();

			value = sin(time * M_TWO_PI * 0.05);
			value2 = cos(time * M_TWO_PI * 0.05);
			value3 = -sin(time * M_TWO_PI * 0.05);

			v = ofMap(value, -1, 1, 0, 255);
			v2 = ofMap(value2, -1, 1, 0, 255);
			v3 = ofMap(value3, -1, 1, 0, 255);
		
		ofSetColor(v,v2,v3);
		for (i = 0; i < balls.size(); i++)
		{
			balls[i].draw();
			//balls[i].draw(particleWatta);
		}
	}


	//GUI DRAW
	//gui.draw();

	//Mouse Force repel Radius Draw
	ofNoFill();
	ofSetColor(0, 255, 0);
	ofCircle(mousePosX, mousePosY, repulsionRadius);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{	
	//SOUND FOR DIFFERENT ALIGNMENT OPTIONS
		if (key == '0')
		{
			calm.stop();
			wattaSoundFile.stop();
			saturn.stop();
			crown.stop();

			isUsing = 0;
			cout << "\nLine 253 - ofApp.cpp - keyPressed" << " SET: isUsing = 0";
		}
	
		if (key == '1')
		{
			calm.stop();
			wattaSoundFile.stop();
			saturn.stop();

			crown.play();
			crown.setLoop(true);

			isUsing = 1;
			cout << "\nLine 266 - ofApp.cpp - keyPressed" << " SET: isUsing = 1";
		}
		if (key == '2')
		{
			crown.stop();
			wattaSoundFile.stop();
			saturn.stop();

			calm.play();
			calm.setLoop(true);

			isUsing = 2;
			cout << "\nLine 278 - ofApp.cpp - keyPressed" << " SET: isUsing = 2";
		}
		if (key == '3')
		{
			calm.stop();
			crown.stop();
			saturn.stop();

			wattaSoundFile.play();
			wattaSoundFile.setLoop(true);

			isUsing = 3;
			cout << "\nLine 290 - ofApp.cpp - keyPressed" << " SET: isUsing = 3";
		}
		if (key == '4')
		{
			calm.stop();
			crown.stop();
			wattaSoundFile.stop();

			saturn.play();
			saturn.setLoop(true);

			isUsing = 4;
			cout << "\nLine 302 - ofApp.cpp - keyPressed" << " SET: isUsing = 4";
		}



		//screenshot
		if (key == 'x') //screenshot
		{
			//only needed  glReadBuffer on windows when using ofSetAutoBackground(false)
			glReadBuffer(GL_FRONT);
			ofSaveScreen("savedScreenshot_" + ofGetTimestampString() + ".png");
			cout << " Screenshot Taken" + ofGetTimestampString();
		}
		
		
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
	
	mouseRadiusFlag = 1;
	mousePosX = x;
	mousePosY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
	mousePosX = x;
	mousePosY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	//LEFT MSB: 0 | RIGHT MSB: 2 | MIDDLE MSB: 1
	if (button == 2)	//right mouse button
	{
		cout << "\n|Line 398|inside mousePressed '2' ";

		int i;
		for (i = 0; i < balls.size(); i++)
		{
			balls[i].vel.x = 0;
			balls[i].vel.y = 0;
		}
	}
	if (button == 0)	//middle button/scroll wheel press
	{
		cout << "\n|Line 409|inside mousePressed '0' ";

		int i;
		for (i = 0; i < balls.size(); i++)
		{
			balls[i].vel.x *= -1;
			balls[i].vel.y *= -1;
		}
	}

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
