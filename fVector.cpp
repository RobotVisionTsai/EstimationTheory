#include<iostream>
#include<string.h>
#include <math.h>
#include "fVector.h"
using namespace std;




    /*-------------------------------------------------------------------------*
     *                                                                         *
     *  FRIEND OPERATORS                                                       *
     *                                                                         *
     *-------------------------------------------------------------------------*/
fVector  operator +  (const fVector& A, const fVector& B)
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] = A.elem[i]+B.elem[i];
    }
    return A;
}
fVector  operator -  (const fVector& A, const fVector& B) // Binary minus.
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] = A.elem[i]-B.elem[i];
    }
    return A;
} 
fVector  operator -  (const fVector& A)  // Unary minus.
{
    int i = 0;
    for(i=0;i<A.size;i++)
    {
        A.elem[i] = 0 - A.elem[i]; 
    }        
    return A;
}
fVector  operator -  (const fVector& A, Float B)
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] = A.elem[i]-B;
    }
    return A;
}
fVector  operator -  (Float B, const fVector& A)
{
    fVector C(A.size);
    for(int i=0;i<A.size;i++)
    {
        C.elem[i] = B - A.elem[i];
    }
    return C;
}
fVector  operator *  (const fVector& A, Float B)
{
     for(int i=0;i<A.size;i++)
    {
        A.elem[i] = A.elem[i]*B;
    }
    return A;
}
fVector  operator *  (Float B, const fVector& A)
{
    fVector C(A.size);
    for(int i=0;i<A.size;i++)
    {
        C.elem[i] = A.elem[i]*B;
    }
    return C;
}
fVector  operator /  (const fVector& A, Float B)
{
    int i = 0;
    for(i=0;i<A.size;i++)
    {
        if(B != 0 )
        {
            A.elem[i] = A.elem[i] / B; 
        }
        else
        {
            cout << "分母不得為零" << endl;
            return 0;
        }            
    }        
    return A;
}
fVector  operator /  (const fVector& A, const fVector& B) // Element-wise division
{
    int i = 0;
    for(i=0;i<A.size;i++)
    {
        if(B.elem[i] != 0 )
        {
            A.elem[i] = A.elem[i] / B.elem[i]; 
        }
        else
        {
            cout << "分母不得為零" << endl;
            return 0;
        }            
    }        
    return A;
}
     double   operator*  (const fVector& A, const fVector& B) // Inner-product between two vectors
    {
        double n = 0;
        for(int i=0;i<A.size;i++)
        {
            n += A.elem[i]*B.elem[i];
        }
        return n;
    }
fVector  operator^  (const fVector& A, const fVector& B) // Cross-product between two vectors
{
    if(A.size != 3 && B.size !=3)
    {
        cout << "vector shape error";
        return 0; 
    }
    fVector c(A.size);
    c.elem[0] = A.elem[1]*B.elem[2] - A.elem[2]*B.elem[1];
    c.elem[1] = -A.elem[0]*B.elem[2] + A.elem[2]*B.elem[0];
    c.elem[2] = A.elem[0]*B.elem[1] - A.elem[1]*B.elem[0];
    
    return c;
}
fVector& operator += (fVector& A, const fVector& B)
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] = A.elem[i]+B.elem[i];
    }
    return A;
}
fVector& operator -= (fVector& A, const fVector& B)
{
    for(int i=0;i<A.size;i++)
    {
        A.elem[i] = A.elem[i]-B.elem[i];
    }
    return A;
}
fVector& operator *= (fVector& A, Float B)
{       
     for(int i=0;i<A.size;i++)
    {
        A.elem[i] = A.elem[i]*B;
    }
    return A;
}
fVector& operator /= (fVector& A, Float B)
{
    int i = 0;
    for(i=0;i<A.size;i++)
    {
        if(B != 0 )
        {
            A.elem[i] = A.elem[i] / B; 
        }
        else
        {
            cout << "分母不得為零" << endl;
            
        }            
    }        
    return A;
}

fVector  Min(const fVector& A, const fVector& B) // Element-wise minimum-element extraction between two vectors
{
    fVector C(A.size);
    for(int i = 0;i<A.size;i++)
    {
        if(A.elem[i]>=B.elem[i])
            C.elem[i] = B.elem[i];
        if(A.elem[i]<B.elem[i])
            C.elem[i] = A.elem[i];
    }
    return C;
}
fVector  Max(const fVector& A, const fVector& B) // Element-wise maximum-element extraction between two vectors
{
    fVector C(A.size);
    for(int i = 0;i<A.size;i++)
    {
        if(A.elem[i]>=B.elem[i])
            C.elem[i] = A.elem[i];
        if(A.elem[i]<B.elem[i])
            C.elem[i] = B.elem[i];
    }
    return C;
}
double   Dist(const fVector& A, const fVector& B) // Returns two norm distance between two vectors
{
    double n = 0;
    for(int i =0;i<A.size;i++)
    {
        n += pow((A.elem[i] - B.elem[i]), 2);
    }
    return sqrt(n);
}
fVector  Normalize(const fVector &A) // Normalizes a vector into an unit vector
{
    fVector C(A.size);
    double twonormsqrt;
    twonormsqrt = TwoNormSqr(A);
    for(int i =0;i<A.size;i++)
    {
        C.elem[i] = A.elem[i]/twonormsqrt;
    }
    return C;
}
double   OneNorm(const fVector& A) // Returns one norm value of a vector
{
    double n = 0;
    for(int i=0;i<A.size;i++)
    {
        n += abs(A.elem[i]);
    }
    return n;
}
double   TwoNorm(const fVector &A) // Returns two norm value of a vector
{
    double n = 0;
    for(int i=0;i<A.size;i++)
    {
        n += pow((A.elem[i]), 2);
    }
    return n;
}
double   TwoNormSqr(const fVector &A) // Returns square of the two norm value of a vector
{
    return sqrt(TwoNorm(A));
}
fVector  Sqrt(const fVector& A) // Element-wise square root of a vector
{
    fVector C(A.size);
    for(int i=0;i<A.size;i++)
    {
        C.elem[i] = sqrt(A.elem[i]);
    }
    return C;
}
double   Mean(const fVector& A) // Mean value of a vector.
{
    double n = 0;
    for(int i =0;i<A.size;i++)
    {
        n += A.elem[i];
    }
    return n/A.size;
}
double   Var(const fVector& A) // Variance of a vector.
{
    double n;
    double x = Mean(A);
    for(int i =0;i<A.size;i++)
    {
        n += pow((A.elem[i] - x), 2);
    }
    return n/(A.size - 1);
} 
double   Std(const fVector& A) // Standard derivation of a vector.    	
{
    return sqrt(Var(A));
}
   // void ShowVector ( const fVector &A, VecType Type)


     // Initinalize constructor.
fVector::fVector(int size )
{
    this->size = size;
    elem = new Float[size];       
}
    // Copy constructor.
fVector::fVector(const fVector& A) 
{
    size = A.size;
    elem = new Float[size];
    memcpy(elem, &A.elem[0], sizeof(Float)*size);
}
    // Assign constructor.
fVector::fVector(const Float* x, int n)
{
    elem = NULL;
    size = n;
    elem = new Float[n];
    memcpy(elem, x, sizeof(Float) * size);
}
fVector::fVector(int n, const Float* x)
{
    elem = NULL;
    size = n;
    elem = new Float[n];
    memcpy(elem, x, sizeof(Float) * size);
}
fVector::fVector(Float a, Float b) 
{
    size = 2;        
    elem = NULL;        
    elem = new Float[size];
    elem[0] = a;
    elem[1] = b;
}
fVector::fVector(Float a, Float b, Float c)
{
    size = 3;        
    elem = NULL;
    elem = new Float[size];
    elem[0] = a;
    elem[1] = b;
    elem[2] = c;
}
fVector::~fVector()
{
    if (elem)
    {
        delete elem;
        elem = NULL;
    }
}

static  const fVector Null;

fVector& fVector::operator=(const fVector&A)
{
    if (this != &A)
    {
        delete[] this->elem;
        this->elem = new Float[A.size];
        this->size = A.size;
        for(int i=0;i<A.size;i++)
        {
            this->elem[i] = A.elem[i];
        }
    }
    return *this;
}
    // void    operator=(Float);
    // void    SetSize(int);

    // fVector& Swap(int i, int j);
    // fVector GetBlock(int i, int j) const;
    // void    SetBlock(int i, int j, const fVector&);
void	fVector::Show(VecType Type ) const
{
    if(Type==1)
    {
        for(int i=0;i<size;i++)
        {           
                cout<<elem[i]<<endl;                
        }
    }
    if(Type==2)
    {
        for(int i=0;i<size;i++)
        {
            if(i!=(size-1))
                cout<<elem[i]<<" ";
            else
                cout<<elem[i]<<endl;
        }
    }
}


