#include<iostream>
#include<string.h>
#include <iomanip>
#include <math.h>
#include "fMatrix.h"
using namespace std;

fMatrix  operator +  ( const fMatrix &A, const fMatrix &B)
{
    fMatrix c(A.rows,A.cols);
    for(int i=0;i<A.rows*A.cols;i++)
    {
        c.elem[i] = A.elem[i]+B.elem[i];
    }
    return c;
}

fMatrix  operator -  ( const fMatrix &A, const fMatrix &B)
{
    fMatrix c(A.rows,A.cols);
    for(int i=0;i<A.rows*A.cols;i++)
    {
        c.elem[i] = A.elem[i]-B.elem[i];
    }
    return c;
}

fMatrix  operator -  ( const fMatrix &A)
{
    fMatrix c(A.rows,A.cols);
    for(int i=0;i<A.rows*A.cols;i++)
    {
        c.elem[i] = -A.elem[i];
    }
    return c;
}

fMatrix  operator *  ( const fMatrix &A, Float n )
{
    fMatrix c(A.rows,A.cols);
    for(int i=0;i<A.rows*A.cols;i++)
    {
        c.elem[i] = n*A.elem[i];
    }
    return c;
}

fMatrix  operator *  ( Float n, const fMatrix &A ) 
{
    fMatrix c(A.rows,A.cols);
    for(int i=0;i<A.rows*A.cols;i++)
    {
        c.elem[i] = n*A.elem[i];
    }
    return c;
}

fMatrix  operator /  ( const fMatrix &A, Float n)
{
    fMatrix c(A.rows,A.cols);
    for(int i=0;i<A.rows*A.cols;i++)
    {
        c.elem[i] = A.elem[i]/n;
    }
    return c;
}

fMatrix  operator *  ( const fMatrix &A, const fMatrix &B )
{
    fMatrix c(A.rows,B.cols);
    if(A.cols != B.rows)
    {
        cout<<"shape error !!!"<<endl;
        return 0;
    }
    for(int i=0;i<A.rows*B.cols;i++)
    {
        Float sum = 0;
        int n = i%B.rows;
        int d = i/A.rows;
        for(int j=0;j<B.cols;j++)
        {
            sum += A.elem[d*A.cols+j]*B.elem[n+j*B.cols];
        }
        
        c.elem[i] = sum;
    }
    // cout << A.rows*B.cols<<endl;
    return c;
}
void fMatrix::Show() const
{
    // for(int i=0;i<cols*rows;i++)
    // {
    //     cout<<elem[i]<<" ";

    // }
    // cout <<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(4)<<elem[i*cols+j]<<" ";
        }
        cout<<endl;
    }
}
fMatrix::fMatrix( int n_rows, int n_cols)
{   
    this->rows = n_rows;
    this->cols = n_cols;
    elem = new Float[rows*cols];
}

fMatrix::fMatrix( const fMatrix & A)
{
    rows = A.rows;
    cols = A.cols;
    elem = new Float[rows*cols];
    memcpy(elem,&A.elem[0],sizeof(Float)*rows*cols);
} 

fMatrix::fMatrix( Float *Array, int n_rows , int n_cols  )
{
    elem = NULL;
    rows = n_rows;
    cols = n_cols;
    elem = new Float[rows*cols];
    memcpy(elem,Array,sizeof(Float)*rows*cols);
}

fMatrix::~fMatrix(void)
{
    if (elem)
    {
        delete elem;
        elem = NULL;
    }   
}