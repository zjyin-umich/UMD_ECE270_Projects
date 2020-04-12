#include "CDList.h"


CDList::CDList()
{
    //ctor

    n = 0;
}

void CDList ::print(string label, int index[])
{
    cout<<"\nCDList: "<<label<<"-----";
    cout<<"\nn: "<<n;

    char str[N_MAX];

    int i;
    for(i=0;i<n;i++)
    {
        cout<<"\n";
        sprintf(str,"list[Sorted: %d  Origin: %d]",i,index[i]);
        list[index[i]].print(string(str));
    }
}

int CDList :: readCSVFile(string filename)
{
    int n,count;
    string line;
    ifstream myFile(filename.c_str());


    if(myFile.is_open())
    {
        count = 0;
        while(getline(myFile,line))
        {
            list[count].parseCSVString(line);
            count++;
        }
        myFile.close();
    }
    else
    {
        cout<<"\n\n-------------------";
        cout<<"\nCant Open File";
        cout<<"\n-------------------\n\n";
    }
    n= count;
    return(count);
}

//SWAP
void CDList ::swap (CD *a, CD *b)        //swapping whole List of Cd and its subcategories(title,artist,year..etc)
{
    CD temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void CDList ::swap (int *a, int *b)        //swapping whole List of Cd and its subcategories(title,artist,year..etc)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void CDList ::swap(ofImage *a, ofImage *b)   //swapping of a seperate Image Array
{
    ofImage temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



//SORT

void CDList :: sortByTitle()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(list[j-1].title>list[j].title)
            {
                swap(&list[j-1], &list[j]);
                swap(&myImage[j-1], &myImage[j]);
            }
        }
    }
}
void CDList :: sortByArtist()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(list[j-1].artist>list[j].artist)
            {
                swap(&list[j-1], &list[j]);
                swap(&myImage[j-1], &myImage[j]);
            }
        }
    }
}
void CDList :: sortByYear()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(list[j-1].year>list[j].year)
            {
                swap(&list[j-1], &list[j]);
                swap(&myImage[j-1], &myImage[j]);
            }
        }
    }
}
void CDList :: sortByGenre()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(list[j-1].genre>list[j].genre)
            {
                swap(&list[j-1], &list[j]);
                swap(&myImage[j-1], &myImage[j]);
            }
        }
    }
}
void CDList :: sortByRating()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(list[j-1].rating>list[j].rating)
            {
                swap(&list[j-1], &list[j]);
                swap(&myImage[j-1], &myImage[j]);
            }
        }
    }
}
void CDList :: sortByFan()
{
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(list[j-1].fan>list[j].fan)
            {
                swap(&list[j-1], &list[j]);
                swap(&myImage[j-1], &myImage[j]);
            }
        }
    }
}

void CDList :: loadImg(int n, ofImage images[])
{
    int i;
    for(i=0;i<n;i++)
    {
        images[i].loadImage(list[i].imageURL);
        images[i].width = 100;
        images[i].height = 100;
    }
}
CDList::~CDList()   //DONT TOUCH
{
    //dtor
}
