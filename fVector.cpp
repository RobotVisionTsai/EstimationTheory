#include<iostream>
#include<string.h>
#include "fVector.h"
using namespace std;

fVector::fVector(int size)
{
    size = size ;
}

fVector::fVector(Float a,Float b,Float c)
{
    elem = new Float[3];
    elem[0] = a;
    elem[1] = b;
    elem[2] = c;
    // cout << &a << endl << &b << endl << &c << endl;
}


fVector::fVector( const Float *x, int n )
{
    // elem = NULL;
    size = n;
    elem = new Float[n];
    memcpy(elem,x,sizeof(Float)*size);
}

fVector::~fVector()
{
    delete elem;
    elem = NULL;
}

void fVector::Show(VecType Type) const
{
    if(Type==1)
    {
        cout << "{";
        for(int i=0;i<size;i++)
        {
            if(i!=(size-1))
                cout<<elem[i]<<",";
            else
                cout<<elem[i];
        }
        cout<<"}"<<endl;
    }
}