#include "ofApp.h"
#include "CD.h"
#include "CDList.h"



//--------------------------------------------------------------
void ofApp::setup()
{
    //Regular CD
    //myCD.parseCSVString("Avenged Sevenfold,Hail to the King,2013,Metal,4.0,Nathan Ozog,http://is1.mzstatic.com/image/thumb/Music4/v4/6f/10/ba/6f10ba0d-d62e-673c-ff28-92d089fe80b9/source/100x100bb.jpg");
    //myCD.print("myCD First Line");
    //CD List

    fav.n = fav.readCSVFile("query.txt");
    int index[fav.n];
    for(i=0;i<fav.n;i++)
    {
        index[i] = i;
    }
    //fav.print("File Read", index);
    //basic printing url to screen
    yPosition = 0;
    xPosition = 0;
    count = 0;
    cout<"\n\n\n";
    cout<<"---- LIST----";
    cout<"\n\n\n";

    fav.sortByTitle();
    //fav.print("Sorted",index);

    //cout<<"\nlist[0]: "<<fav.list[0].title;
    //cout<<"\nlist[49]: "<<fav.list[49].title;

    fav.loadImg(fav.n,fav.myImage);

    //artist: q
    //title: w
    //year: e
    //genre: r
    //rating: t
    //fan: y
    //screenshot: x
    cout<<"\nDefault Sort: TITLE";
    cout<<"\n-----Sort Key -----";
    cout<<"\nArtist: 'q'";
    cout<<"\nTitle: 'w'";
    cout<<"\nYear: 'e'";
    cout<<"\nGenre: 'r'";
    cout<<"\nrating: 't'";
    cout<<"\nfan: 'y'";
    cout<<"\nscreenshot: 'x'";
    cout<<"\n-------------------";



}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{

    //fav.myImage[0].draw(0,0);

    for (i=0; i<50; i++)
    {
        fav.myImage[i].draw(xPosition, yPosition);
        xPosition = xPosition + 100;
        if (xPosition == 1000)
        {
            xPosition = 0;
        }
        count++;
        if (count==10)
        {
            yPosition = yPosition + 100;
            count = 0;
        }
        if (yPosition ==500)
        {
            yPosition = 0;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    //artist: q
    //title: w
    //year: e
    //genre: r
    //rating: t
    //fan: y
    //screenshot: x
    if(key=='q') //artist
    {
        fav.sortByArtist();
        cout<"\n";
        cout<<"\n---- Sort By Artist----";
        cout<"\n";
    }
    if(key=='w') //title
    {
        fav.sortByTitle();
        cout<"\n";
        cout<<"\n---- Sort By Title----";
        cout<"\n";
    }
    if(key=='e') //Year
    {
        fav.sortByGenre();
        cout<"\n";
        cout<<"\n---- Sort By Year----";
        cout<"\n";
    }
    if(key=='r') //genre
    {
        fav.sortByGenre();
        cout<"\n";
        cout<<"\n---- Sort By Genre----";
        cout<"\n";
    }
    if(key=='t') //rating
    {
        fav.sortByRating();
        cout<"\n";
        cout<<"\n---- Sort By Rating----";
        cout<"\n";
    }
    if(key=='y') //fan
    {
        fav.sortByFan();
        cout<"\n";
        cout<<"\n---- Sort By Fan----";
        cout<"\n";
    }

    if (key == 'x') //screenshot
    {
        //only needed  glReadBuffer on windows when using ofSetAutoBackground(false)
        glReadBuffer(GL_FRONT);
        ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".png");
        cout<<" Screenshot Taken"+ofGetTimestampString();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
