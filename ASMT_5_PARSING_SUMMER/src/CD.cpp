#include "CD.h"


CD::CD()
{
    //artist,title, year,genre,rating,fan,imageURL
    artist = "";
    title = "";
    year = 0;
    genre = "";
    rating = 0;
    fan = "";
    imageURL = "";

    //ctor CONSTRUCTOR
}
CD::~CD()
{
    //dtor
}

void CD::print(string label)
{
    cout <<"\n"<<label<<"-----";
    cout <<"\ntitle: "<<title;
    cout <<"\nartist: "<<artist;
    cout <<"\nyear: "<<year;
    cout <<"\ngenre: "<<genre;
    cout <<"\nrating: "<<rating;
    cout <<"\nfan: "<<fan;
    cout <<"\nimageURL: "<<imageURL;
}

int CD ::getCommaIndex(string str,int index[])
{
    int n,i,count;
    n= str.length();
    count = 0;
    for(i=0;i<n+1;i++)
    {
        if(str[i] == ',')
        {
            index[count] = i;
            count++;
        }
    }
    return(count);
}

void CD ::parseCSVString(string CSV)
{
    int numComma, i, i1, i2, index[MAX_STR_LEN],k;
    numComma = getCommaIndex(CSV,index);


    string yearStr;
    string ratingStr;

    for(i=0;i<numComma+1;i++)
    {

        if(i==0) i1 = 0;
        else i1 = index[i-1]+1;

        if(i==numComma) i2= CSV.length()-1;
        else i2 = index[i]-1;
        k = i2-i1 + 1;


        //artist,title, year,genre,rating,fan,imageURL

        if(i==0) artist = CSV.substr(i,k);
        if(i==1) title = CSV.substr(i1,k);

        if(i==2)
        {
            yearStr = CSV.substr(i1,k);
            year = atoi(yearStr.c_str()); //atoi needs a C string not a C++ string, this is converting the C++ string to a C string with the .c_str()
        }
        if(i==3) genre = CSV.substr(i1,k);
        if(i==4)
        {
            ratingStr = CSV.substr(i1,k);
            rating = atof(ratingStr.c_str());
        }
        if(i==5) fan = CSV.substr(i1,k);
        if(i==6) imageURL = CSV.substr(i1,k);

        //cout<<"\n";
        //cout<<"i: "<<i<<"  "<<"k: "<<k;

    }

}
