#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    //sound1.loadSound( "johnCena.mp3" );
    //sound.setLoop( true );
    sound1.loadSound("quack.mp3");
    sound1.setMultiPlay(true);

    //soundLobby.play();
    //count1 = 1.0;
    sound1.setSpeed(count1);

    srand(time(NULL));
    ofBackground(255,255,255);
    playercolor.set(255,0,0);                                       //setting player initial color
    player.set(ofGetWidth()%2,ofGetHeight()%2,10,10);               //setting player initial position

    for(i=0;i<MAX_NUM_FOOD;i++)
    {
        food[i].set(rand()%ofGetWidth(),rand()%ofGetHeight(),10,10);    //generating food random position
        foodcolor[i].set(rand()%255,rand()%255,rand()%255);             // setting food color array to random RGB values
        isVisible[i] = 1;                                               //flag variable set to 1:visible, 0: not visible
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    bool intersect;                             //setting intersection flag variable for true/false
    player.set(playerX,playerY,width,height);   //setting player initial position X/Y grid position
    for(i=0;i<MAX_NUM_FOOD;i++)
    {
        intersect = player.intersects(food[i]);
        if(intersect == true && isVisible[i] ==1)   //increase player rectangle box size
        {

            sound1.play();
            count1 = count1 - 0.01;
            sound1.setSpeed(count1);
            printf("\n %f",count1);

            isVisible[i] = 0;
            width += 2;
            height += 2;
            player.set(playerX,playerY,width,height);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(playercolor);
    ofNoFill();
    ofRect(playerX,playerY,width,height);
    ofFill();
    for(i=0;i<MAX_NUM_FOOD;i++)
    {
        ofSetColor(foodcolor[i]);
        if(isVisible[i] ==1)
        {
            ofRect(food[i]);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//------------------------------------
void ofApp::mouseMoved(int x, int y)
{
    playerX = x;
    playerY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

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
