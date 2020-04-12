#include "basicParticle.h"



basicParticle::basicParticle()
{
	friction = 0.5;
	radius = 8;
	mass = radius;

}

basicParticle::~basicParticle()
{
}

void basicParticle::setFriction(float frictionAmnt)
{
	friction = frictionAmnt;
}

void basicParticle::setPosition(float x, float y)
{
	setPosition(ofPoint(x, y));
}
void basicParticle::setPosition(ofPoint newPos)
{
	pos = newPos;
}

void basicParticle::setVelocity(float x, float y)
{
	setVelocity(ofVec2f(x, y));
}
void basicParticle::setVelocity(ofVec2f velocity)
{
	vel = velocity;
}
void basicParticle::update()
{
	//vel *= friction;
	pos += vel;
}
void basicParticle::addForce(float x, float y)
{
	addForce(ofVec2f(x, y));
}
void basicParticle::addForce(ofVec2f force)
{
	vel += force;
}
void basicParticle::draw()
{
	//ofNoFill();
	ofCircle(pos.x, pos.y, radius);
}
void basicParticle::drawNoFill()
{	
		ofNoFill();
		ofCircle(pos.x, pos.y, radius);
}
void basicParticle::draw(ofImage particleImage)
{
	particleImage.draw(pos.x, pos.y, radius);
}

