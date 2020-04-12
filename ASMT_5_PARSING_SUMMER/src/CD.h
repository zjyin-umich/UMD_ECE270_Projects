#ifndef CD_H
#define CD_H
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h> //needed for atoi

using namespace std;


#define MAX_STR_LEN 2000

class CD
{
    public:

        //member Var
        string artist;
        string title;
        int year;
        string genre;
        int rating;
        string fan;
        string imageURL;
        CD();
            //CD(string artist, string title, int year, string genre, int rating, string fan, string imageURL); Dont really need this

        //member Functions - METHODS
        void print(string label);
        void parseCSVString(string CSV);
        int getCommaIndex(string str,int index[]);




        virtual ~CD();

    protected:

    private:
};

#endif // CD_H
