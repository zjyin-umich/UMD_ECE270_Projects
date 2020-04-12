#ifndef CDLIST_H
#define CDLIST_H
#include "CD.h"
#include "ofMain.h"

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h> //needed for atoi
using namespace std; //for strings

#define N_MAX 1000
class CDList
{
    public:

        int n;
        CD list[N_MAX];
        ofImage myImage[N_MAX];


        CDList();
        void print(string label);
        int readCSVFile(string fileName);

        void print(string label, int index[]);


        //Swap
        void swap(CD *a, CD *b);        //swapping whole List of Cd and its subcategories(title,artist,year..etc)
        void swap(ofImage *a, ofImage *b);   //swapping of a seperate Image Array
        void swap(int *a, int *b);


        //sort
        void sortByTitle();
        void sortByArtist();
        void sortByYear();
        void sortByGenre();
        void sortByRating();
        void sortByFan();


        //LOAD IMAGE
        void loadImg(int n, ofImage images[]);


        virtual ~CDList();

    protected:

    private:
};

#endif // CDLIST_H
