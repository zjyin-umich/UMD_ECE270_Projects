#pragma once
#include "ofMain.h"
#include "ofVectorMath.h"
class basicParticle
{
public:
	basicParticle();
	~basicParticle();

	ofPoint pos;
	ofVec2f  vel;


	float mass;
	float friction;
	float radius;
	
	void setFriction(float frictionAmnt);

	void setVelocity(float x, float y);
	void setVelocity(ofVec2f velocity);

	void setPosition(float x, float y);
	void setPosition(ofPoint newPos);

	void update();

	void addForce(float x, float y);
	void addForce(ofVec2f force);

	void draw();
	void draw(ofImage particleImage);
	void drawNoFill();



};

