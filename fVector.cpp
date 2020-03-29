#include<iostream>
#include<string.h>
#include "fVector.h"
using namespace std;

fVector operator + ( const fVector &A, const fVector &B)
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = A.elem[i]+B.elem[i];
    }
    return fVector(c,A.size);
}

fVector operator - ( const fVector &A, const fVector &B)
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = A.elem[i]-B.elem[i];
    }
    return fVector(c,A.size);
}

fVector operator - ( const fVector &A)
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = -A.elem[i];
    }
    return fVector(c,A.size);
}

fVector operator - ( const fVector &A, Float n)
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = A.elem[i]-n;
    }
    return fVector(c,A.size);
}

fVector operator - ( Float n, const fVector &A)
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = n-A.elem[i];
    }
    return fVector(c,A.size);
}

fVector operator * ( const fVector &A, Float n )
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = A.elem[i]*n;
    }
    return fVector(c,A.size);
}

fVector operator * ( Float n, const fVector &A )
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = A.elem[i]*n;
    }
    return fVector(c,A.size);
}

fVector operator / ( const fVector &A, Float n)
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = A.elem[i]/n;
    }
    return fVector(c,A.size);
}

fVector operator / ( const fVector &A, const fVector &B)
{
    Float c[A.size]={};
    for(int i=0;i<A.size;i++)
    {
        c[i] = A.elem[i]/B.elem[i];
    }
    return fVector(c,A.size);
}

double operator * ( const fVector &A, const fVector &B)
{
    double n=0;
    for(int i=0;i<A.size;i++)
    {
        n += A.elem[i]*B.elem[i];
    }
    return n;
}

fVector& operator += ( fVector &A, const fVector &B)
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] += B.elem[i];
    }
    return A;
}

fVector& operator -= ( fVector &A, const fVector &B)
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] -= B.elem[i];
    }
    return A;
}

fVector& operator *= ( fVector &A, Float b)
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] *= b;
    }
    return A;
}

fVector& operator /= ( fVector &A, Float b)
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] /= b;
    }
    return A;
}

// fVector operator + ( const fVector &A, const fVector &B)
// {
//     return fVector(A.elem[0]+B.elem[0],A.elem[1]+B.elem[1],A.elem[2]+B.elem[2]);
// }

fVector::fVector(int size)
{
    size = size ;
}

fVector::fVector(Float a,Float b,Float c)
{
    // elem = NULL;
    elem = new Float[3];
    size = 3;
    elem[0] = a;
    elem[1] = b;
    elem[2] = c;
}

fVector::fVector( const fVector &A)
{   
    size = A.size;
    elem = new Float[size];
    memcpy(elem,&A.elem[0],sizeof(Float)*size);
}

fVector::fVector( const Float *x, int n )
{
    elem = NULL;
    size = n;
    elem = new Float[n];
    memcpy(elem,x,sizeof(Float)*size);
}

fVector::~fVector()
{
    if (elem)
    {
        delete elem;
        elem = NULL;
    }
    
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