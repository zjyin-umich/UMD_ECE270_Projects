#include "ofApp.h"
float getMin(int n, float x[])
{
    int i, xmin;
    xmin = x[0];
    for(i=0; i<n; i++)
    {
        if(x[i]<xmin)
        {
            xmin=x[i];
        }
    }
    return(xmin);
}

float getMax(int n, float x[])
{
    int i, xmax;
    xmax = x[0];
    for(i = 0; i<n; i++)
    {
        if(x[i]>xmax)
        {
            xmax = x[i];
        }
    }
    return(xmax);
}

int getXSamples(float xmin, float xmax, float step, float x[])
{
    int i,n;
    n = 1 +(xmax - xmin)/step;
    for(i=0; i<n; i++)
    {
        x[i] = xmin + i*step;
    }
    return(n);
}

/*void getDampedCosSamples(int n, float x[], float y[], float alpha, float w) // t = x[i] equation = y[i] function is grabing y value for x value
{
    int i;
    for (i=0; i<n; i++)
    {
        y[i] = exp(-alpha * x[i]) * cos(w * x[i]);
    }
}
*/

float mapFunc(float in, float inMin, float inMax, float outMin, float outMax)
{
    float m,b,result;
    m = (outMax - outMin)/(inMax - inMin);
    b = outMax - m*inMax;
    result = m * in + b;
    return(result);
}

float map_vec(int n, float in[], float out[], float inMin, float inMax, float outMin, float outMax)
{
    int i;
    for(i=0;i<n;i++)
    {
        out[i] = mapFunc(in[i], inMin, inMax, outMin, outMax);
    }
}
void ofApp:: printMyArray(int n, float x[], char label[])
{
    int i;
    printf("\n%s : ", label);
    for(i=0;i<n;i++)
    {
        printf("%f ", x[i]);
    }
}

//--------------------------------------------------------------
void ofApp::setup()
{
    int k, isReading;
    //float x[10000];
    FILE *fp;
    fp = fopen("yahoo.txt", "r");
    isReading = 1;
    n = 0;
    while(isReading == 1)
    {
        k = fscanf(fp,"%f", &y[n]);

        if (k == EOF) isReading = 0;
        else n = n + 1;
    }

    ofSetBackgroundAuto(FALSE);
    //ofSetBackgroundColor(255,255,255,255);
    ofBackground(255,255,255);
    xmin = 1;
    xmax = 19;
    step = 1;

    numSamples = getXSamples(xmin, xmax, step,x);

    map_vec(numSamples,x,xPix,xmin,xmax,250,750);
    map_vec(numSamples,y,yPix,45,46.5,400,200);
    //printMyArray(numSamples,x,"x");
    //printMyArray(numSamples,xPix,"xPix");
    yGridSize=getXSamples(45,46.5,.1,yGrid);
    xGridSize=getXSamples(1,19,1,xGrid);
    map_vec(xGridSize,xGrid,xGrid,xmin,xmax,250,750);
    map_vec(yGridSize,yGrid,yGrid,45,46.5,400,200);

    //vertical lines for xGrid

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(0,0,255);
    for(i=1;i<numSamples;i++)
    {
        ofLine(xPix[i-1],yPix[i-1],xPix[i],yPix[i]);
    }

    ofSetColor(0,0,0,1);    //xGrid
    for(i=0; i<16;i++)
    {
        ofLine(250,yGrid[i],750,yGrid[i]);
    }

    for(i=0; i<19;i++)
    {
        ofLine(xGrid[i],400,xGrid[i],200);
    }

    ofSetColor(230,60,0,30);
    for(i=0;i<19;i++)
    {
        if(i%2==0)
        {
         ofDrawBitmapString(xAxis[i],xGrid[i]-20,410);
        }
        else
        {
            ofDrawBitmapString(xAxis[i],xGrid[i]-20,430);
        }
    }
    ofSetColor(230,60,0,30);
    for(i=0;i<16;i++)
    {
        ofDrawBitmapString(yAxis[i],210,yGrid[i]);
    }

    ofSetColor(138,43,226);
    ofDrawBitmapString("Yahoo Stock Prices Feb-Mar",410,180);

    ofSetColor(0,0,0,255);
    ofDrawBitmapString("Closing Price",85,300);

    ofSetColor(0,0,0,255);
    ofDrawBitmapString("Date",485,450);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
        if (key == 'm')
    {
        //only needed  glReadBuffer on windows when using ofSetAutoBackground(false)
        glReadBuffer(GL_FRONT);
        ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".png");
    }
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
