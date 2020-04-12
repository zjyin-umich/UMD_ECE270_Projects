#include "ofApp.h"
#include "stdio.h"
#include "string.h"
int getQuoteIndex(char str[], int index[])  //CALL FUNCTION
{
    int n,i,count;
    n= strlen(str);
    count = 0;
    for(i=0;i<n;i++)
    {
        if(str[i] == '"')
        {
            index[count] = i;
            count++;
        }
    }
    return(count);
}
//--------------------------------------------------------------
void ofApp::setup()
{
    srand(time(NULL));
    string urlStr, jsonStr;
    urlStr = "https://itunes.apple.com/search?term=jack+johnson";
    ofHttpResponse resp = ofLoadURL(urlStr);
    ofBuffer myBuffer = resp.data;
    jsonStr = myBuffer.getText();
    //printf("\nurlStr: %s",urlStr.c_str; FOR PRINTING TO SCREEN
    //n = urlStr.length();

        firstURL = jsonStr.find("artworkUrl100");

        //cout << "URLStr: s"<< jsonStr;
        cout << "\nURLStr: "<< firstURL;
        string artworkStr;
        artworkStr = jsonStr.substr(firstURL,13);
        cout << "\nString:" << artworkStr;
        //-----------------------------------------------------------
        string sFinal,s1,s2;
        s1 = '"';
        s2 = ':';
        sFinal = artworkStr + s1 + s2;// + s1;
        int sFLength = sFinal.length();
        cout << "\n String Plus Final:" << sFinal;
        cout << "\n SFLength = " << sFLength;
        //--------------------------------------------------------
        char quote1 = '"';
        string endURL = ".jpeg";
        int startIndex,endIndex,movingIndex,strlen;
        movingIndex = 0;
        string tempURL;
        //slength = sFLength
        for(i=0;i<500;i++)
        {
            startIndex = jsonStr.find("artworkUrl100",movingIndex)+16;
            endIndex = jsonStr.find("jpeg",startIndex)+4;

            strlen = endIndex = startIndex;
            tempURL = jsonStr.substr(startIndex,strlen);
            myImage[i].loadImage(tempURL);
            movingIndex = endIndex;
        }

        int yPosition = 0;
        int xPosition = 0;
        int count = 0;






}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255,255,255);
    for(i=0;i<50;i++)
    {
        myImage[i].draw(xPosition,yPosition);
        xPosition = xPosition + 100;
        if(xPosition ==1000)
        {
            xPosition = 0;
            count++;
        }

        if(count==10)
        {
            yPosition = yPosition +100;
            count=0;
        }
        if(yPosition ==500)
        {
            yPosition = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
