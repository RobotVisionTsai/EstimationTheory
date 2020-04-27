#include <iostream>
#include <stdio.h>
#include <string.h>
#include<math.h>
#include "fVector.h"

using namespace std;

class fVector
{
    /*-------------------------------------------------------------------------*
     *                                                                         *
     *  FRIEND OPERATORS                                                       *
     *                                                                         *
     *-------------------------------------------------------------------------*/
    friend fVector  operator +  (const fVector& A, const fVector& B)
    {
        fVector C;
        int i = 0;
        if(A.size <= B.size)
        {
            for(i=0;i<A.size;i++)
            {
                C.elem[i] = A.elem[i] + B.elem[i];
            }
        }
        else if(A.size > B.size)
        {
            for(i=0;i<B.size;i++)
            {
                C.elem[i] = A.elem[i] + B.elem[i];
            }
        }
        return C;
    }
    friend fVector  operator -  (const fVector& A, const fVector& B) // Binary minus.
    {
        fVector C;
        int i = 0;
        if(A.size <= B.size)
        {
            for(i=0;i<A.size;i++)
            {
                C.elem[i] = A.elem[i] - B.elem[i];
            }
        }
        else if(A.size > B.size)
        {
            for(i=0;i<B.size;i++)
            {
                C.elem[i] = A.elem[i] - B.elem[i];
            }
        }
        return C;
    } 
    friend fVector  operator -  (const fVector& A)  // Unary minus.
    {
        fVector C;
        int i = 0;
        for(i=0;i<A.size;i++)
        {
            C.elem[i] = 0 - A.elem[i]; 
        }        
        return C;
    }
    friend fVector  operator -  (const fVector& A, Float B)
    {
        fVector C;
        int i = 0;
        for(i=0;i<A.size;i++)
        {
            C.elem[i] = A.elem[i] - B; 
        }        
        return C;
    }
    friend fVector  operator -  (Float B, const fVector& A)
    {
        fVector C;
        int i = 0;
        for(i=0;i<A.size;i++)
        {
            C.elem[i] = B - A.elem[i]; 
        }        
        return C;
    }
    friend fVector  operator *  (const fVector& A, Float B)
    {
        fVector C;
        int i = 0;
        for(i=0;i<A.size;i++)
        {
            C.elem[i] = A.elem[i] * B; 
        }        
        return C;
    }
    friend fVector  operator *  (Float B, const fVector& A)
    {
        fVector C;
        int i = 0;
        for(i=0;i<A.size;i++)
        {
            C.elem[i] = A.elem[i] * B; 
        }        
        return C;
    }
    friend fVector  operator /  (const fVector& A, Float B)
    {
        fVector C;
        int i = 0;
        for(i=0;i<A.size;i++)
        {
            if(B != 0 )
            {
                C.elem[i] = A.elem[i] / B; 
            }
            else
            {
                cout << "分母不得為零" << endl;
            }            
        }        
        return C;
    }
    friend fVector  operator /  (const fVector& A, const fVector& B) // Element-wise division
    {
        fVector C(A.size);
        for(int i=0;i<A.size;i++)
        {
            C.elem[i] = A.elem[i]/B.elem[i];
        }
        return C;
    }
    friend double   operator *  (const fVector& A, const fVector& B) // Inner-product between two vectors
    {
        double n = 0;
        for(int i=0;i<A.size;i++)
        {
            n += A.elem[i]*B.elem[i];
        }
        return n;
    }
    friend fVector  operator ^  (const fVector&, const fVector&); // Cross-product between two vectors
    friend fVector& operator += (fVector& A, const fVector& B)
    {
        int i = 0;
        if(A.size <= B.size)
        {
            for(i=0;i<A.size;i++)
            {
                A.elem[i] = A.elem[i] + B.elem[i];
            }
        }
        else if(A.size > B.size)
        {
            for(i=0;i<B.size;i++)
            {
                A.elem[i] = A.elem[i] + B.elem[i];
            }
        }
        return A;
    }
    friend fVector& operator -= (fVector& A, const fVector& B)
    {
        int i = 0;
        if(A.size <= B.size)
        {
            for(i=0;i<A.size;i++)
            {
                A.elem[i] = A.elem[i] - B.elem[i];
            }
        }
        else if(A.size > B.size)
        {
            for(i=0;i<B.size;i++)
            {
                A.elem[i] = A.elem[i] - B.elem[i];
            }
        }
        return A;
    }
    friend fVector& operator *= (fVector& A, Float B)
    {       
        int i = 0;
        for(i=0;i<A.size;i++)
        {
            A.elem[i] = A.elem[i] * B; 
        }        
        return A;
    }
    friend fVector& operator /= (fVector& A, Float B)
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

    /*-------------------------------------------------------------------------*
     *                                                                         *
     *  FRIEND FUNCTIONS                                                       *
     *                                                                         *
     *-------------------------------------------------------------------------*/
    friend fVector  Min(const fVector& A, const fVector& B) // Element-wise minimum-element extraction between two vectors
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
    friend fVector  Max(const fVector& A, const fVector& B) // Element-wise maximum-element extraction between two vectors
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
    friend double   Dist(const fVector& A, const fVector& B) // Returns two norm distance between two vectors
    {
        double n = 0;
        for(int i =0;i<A.size;i++)
        {
            n += pow((A.elem[i] - B.elem[i]), 2);
        }
        return sqrt(n);
    }
    friend fVector  Normalize(const fVector &A) // Normalizes a vector into an unit vector
    {
        fVector C(A.size);
        double mean, std;
        mean = Mean(A);
        std = Std(A);
        for(int i=0;i<A.size;i++)
        {
            C.elem[i] = (A.elem[i] - mean)/std;
        }
        return C;

    }
    friend double   OneNorm(const fVector& A) // Returns one norm value of a vector
    {
        double n = 0;
        for(int i=0;i<A.size;i++)
        {
            n += A.elem[i];
        }
        return n;
    }
    friend double   TwoNorm(const fVector &A) // Returns two norm value of a vector
    {
        double n = 0;
        for(int i=0;i<A.size;i++)
        {
            n += pow((A.elem[i]), 2);
        }
        return n;
    }
    friend double   TwoNormSqr(const fVector &A) // Returns square of the two norm value of a vector
    {
        return pow(TwoNorm(A),2);
    }
    friend fVector  Sqrt(const fVector& A) // Element-wise square root of a vector
    {
        fVector C(A.size);
        for(int i=0;i<A.size;i++)
        {
            C.elem[i] = sqrt(A.elem[i]);
        }
        return C;
    }
    friend double   Mean(const fVector& A) // Mean value of a vector.
    {
        double n = 0;
        for(int i =0;i<A.size;i++)
        {
            n += A.elem[i];
        }
        return n/A.size;
    }
    friend double   Var(const fVector& A) // Variance of a vector.
    {
        double n;
        double x = Mean(A);
        for(int i =0;i<A.size;i++)
        {
            n += pow((A.elem[i] - x), 2);
        }
        return n/(A.size - 1);
    } 
    friend double   Std(const fVector& A) // Standard derivation of a vector.    	
    {
        return sqrt(Var(A));
    }
    friend void     ShowVector(const fVector&, VecType Type = ColVec);

public:
    /*-------------------------------------------------------------------------*
     *                                                                         *
     *  C O N S T R U C T O R S  & D E S T R U C T O R S                       *
     *                                                                         *
     *-------------------------------------------------------------------------*/
     // Initinalize constructor.
    fVector::fVector(int size = 0)
    {
        this->size = size;
        elem = new Float[size];       
    }
    // Copy constructor.
    fVector::fVector(const fVector& A) 
    {
        size = A.size;
        elem = new Float[size];
        memccpy(elem, &A.elem[0], sizeof(Float)*size);
    }
    // Assign constructor.
    fVector::fVector(const Float* x, int n)
    {
        elem = NULL;
        size = n;
        elem = new Float[n];
        memccpy(elem, x, sizeof(Float) * size);
    }
    fVector::fVector(int n, const Float* x)
    {
        elem = NULL;
        size = n;
        elem = new Float[n];
        memccpy(elem, x, sizeof(Float) * size);
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

public:
    fVector& operator=(const fVector&);
    void    operator=(Float);
    void    SetSize(int);

    fVector& Swap(int i, int j);
    fVector GetBlock(int i, int j) const;
    void    SetBlock(int i, int j, const fVector&);
    void	fVector::Show(VecType Type = ColVec) const
    {
        if(Type==1)
        {
            for(int i=0;i<size;i++)
            {
                if(i!=(size-1))
                  cout<<elem[i]<<" ";
                else
                  cout<<elem[i]<<endl;                
            }
        }
        if(Type==2)
        {
            for(int i=0;i<size;i++)
            {
                cout<<elem[i]<<endl;
            }
        }
    }

public: // Inlined functions.
    inline Float  operator()(int i) const { return elem[i]; }
    inline Float& operator()(int i) { return elem[i]; }
    inline Float* Array() const { return elem; }
    inline int    Size() const { return size; }

private:
    int    size;
    Float* elem;

    static int nVecCount;
};

