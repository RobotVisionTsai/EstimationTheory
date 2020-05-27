
#include <iostream>
#include <string.h>
#include <iomanip>
#include <math.h>
#include "fMatrix.h"

using namespace std;

fMatrix  operator +  ( const fMatrix &A, const fMatrix &B )
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = A.elem[i] + B.elem[i];	
	}
	return A;
};
// 2. A-B
fMatrix  operator -  ( const fMatrix & A                )
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = 0 - A.elem[i];	
	}
	return A;
};
fMatrix  operator -  ( const fMatrix & A, const fMatrix & B)
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = A.elem[i] - B.elem[i];	
	}
	return A;
};
// 3. c*A or A*c
fMatrix  operator *  ( const fMatrix &A,       Float    B)
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = A.elem[i] * B;	
	}
	return A;
};
fMatrix  operator *  (       Float  B,  const fMatrix & A)
{
	fMatrix C(A.rows, A.cols);
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		C.elem[i] = B * A.elem[i];	
	}
	return C;
};
// 4. A/c
fMatrix  operator /  ( const fMatrix &A,       Float    B)
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = A.elem[i] / B;	
	}
	return A;
};
// 5. A*B
fMatrix  operator *  ( const fMatrix &A, const fMatrix & B)
{    
	fMatrix C(B.rows,A.cols);
    if(A.rows != B.cols)
    {
        cout<<"shape error !!!"<<endl;
        return 0;
    }
	for(int i = 0;i<A.cols*B.rows;i++)	
	{	
		Float sum = 0;
		int d = i/A.cols;
		int n = i%A.cols;
		for(int j;j<A.rows;j++)
		{
			sum += A.elem[d*A.rows + j] * B.elem[j*B.rows + n];
		} 	
		C.elem[i] = sum;
	}
	return C;
};
fVector  operator *  ( const fMatrix &A, const fVector & B)
{
    fVector C(A.rows);
	if(A.rows != B.Size())
    {
        cout<<"shape error !!!"<<endl;
        return 0;
    }
    for(int i=0;i<A.rows;i++)
    {
        double sum = 0;
        for(int j=0;j<B.Size();j++)
        {
            sum += A.elem[i*B.Size()+j]*B.Array()[j];
        }
        C.Array()[i] = sum;
    }
        // cout<< B.Array()[i]<<endl;
    return C;
};
fVector  operator *  ( const fVector &A, const fMatrix & B)
{
    fVector C(B.cols);
	if(A.Size() != B.cols)
    {
        cout<<"shape error !!!"<<endl;
        return 0;
    }
    for(int i=0;i<B.rows;i++)
    {
        double sum = 0;
        for(int j=0;j<A.Size();j++)
        {
            sum += A.Array()[j]*B.elem[i+j*B.cols];
        }
        C.Array()[i] = sum;
    }
    return C;
};

fMatrix& operator += (       fMatrix &A, const fMatrix & B)
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = A.elem[i] + B.elem[i];	
	}
	return A;
};
fMatrix& operator -= (       fMatrix &A, const fMatrix & B)
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = A.elem[i] - B.elem[i];	
	}
	return A;
};
fMatrix& operator *= (       fMatrix &A,       Float    B)
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = A.elem[i] * B;	
	}
	return A;
};
fMatrix& operator *= (       fMatrix &A, const fMatrix & B)
{
    if(A.cols != B.rows)
    {
        cout<<"shape error !!!"<<endl;
        exit(1);
    }
    fMatrix c(A.rows,B.cols);
    for(int i=0;i<A.rows*B.cols;i++)
    {
        Float sum = 0;
        int d = i/B.cols;
        int n = i%B.cols;

        for(int j=0;j<A.cols;j++)
        {
            sum += A.elem[d*A.cols+j]*B.elem[n+j*B.cols];
        }
        
        // cout << sum << endl;
        c.elem[i] = sum; 
    }
    A = c;
    // cout << A.rows*B.cols<<endl;
    return A;
};
fVector& operator *= (       fVector &A, const fMatrix & B)
{
    fVector C(B.cols);
    for(int i=0;i<B.rows;i++)
    {
        double sum = 0;
        for(int j=0;j<A.Size();j++)
        {
            sum += A.Array()[j]*B.elem[i+j*B.cols];
        }
        C.Array()[i] = sum;
    }
    A = C;
    return A;
};
fMatrix& operator /= (       fMatrix &A,       Float    B)
{
	for(int i = 0;i<A.rows*A.cols;i++)	
	{	
		A.elem[i] = A.elem[i] / B;	
	}
	return A;
};

/*-------------------------------------------------------------------------*
 *                                                                         *
 *  FRIEND FUNCTIONS                                                       *
 *                                                                         *
 *-------------------------------------------------------------------------*/
fMatrix  Transp      ( const fMatrix & A)	// Transpose of a matrix
{
    fMatrix C(A.cols,A.rows);
    for(int i=0;i<A.cols;i++)
    {
        for(int j=0;j<A.rows;j++)
        {
            C.elem[i*A.rows+j] = A.elem[j*A.cols+i];
        }
    }
    return C;
}
fMatrix  AATransp    ( const fMatrix & A)	// Computes A * Transp(A).
{

	return A * Transp(A);
}
fMatrix  ATranspA    ( const fMatrix & A)	// Computes Transp(A) * A.
{
	return Transp(A) * A;
}
fMatrix  Outer  ( const fVector & A, const fVector & B)  // Computes the outer product of two vectors.
{
	fMatrix C(B.Size(), A.Size());
	for(int i=0;i<A.Size()*B.Size();i++)
    {
        C.elem[i] = A.Array()[i/C.cols]*B.Array()[i%C.cols];
    }
    return C;
}
fMatrix  Identity	( int nSize ) // Returns an nSizexnSize identity matrix.
{
	fMatrix C(nSize ,nSize );
    for(int i=0;i<nSize*nSize;i++)
    {
        if(i/nSize==i%nSize)
        {
            C.elem[i] = 1;
        }
        else
        {
            C.elem[i] = 0;
        }
    }
    return C;
}
fMatrix  Diag        ( const fVector & A)// Returns the square matrix with the elements of the vector d along its diagonal.
{
	fMatrix N(A.Size(), A.Size());
	for(int i=0;i<A.Size()*A.Size();i++)
    {
        if(i/A.Size()==i%A.Size())
        {
            N.elem[i] = A.Array()[i/A.Size()];
        }
        else
        {
            N.elem[i] = 0;
        }    
    }
    return N;
}
fVector  Diag        ( const fMatrix & A)// Returns the vector consisting of the diagonal elements of the matrix M
{
    if(A.rows != A.cols)
    {
        cout << "shape error!" <<endl;
        return 0;
    }

    fVector C(A.rows);
    for(int i=0;i<A.rows*A.cols;i++)
    {
        if(i/A.rows==i%A.cols)
        {
            C.Array()[i/A.rows] = A.elem[i];
        }    
    }
    return C;
}
fMatrix  Diag        ( Float A, Float B, Float C)// Returns the 3 x 3 diagonal matrix with x, y, and z as its diagonal elements.
{
    fMatrix N(3,3);
    for(int i=0;i<9;i++)
    {
        N.elem[i] = 0;
    }
    N.elem[0] = A;
    N.elem[4] = B;
    N.elem[8] = C;
    return N;
}
double   Determinant ( const fMatrix & A)// Computes the determinant of a square matrix
{
    if(A.cols!=A.rows)
    {
        cout << "shape error!" <<endl;
        return 0;
    }
    // double mul;
    double sum = 0;

    if (A.rows == 2)
    {
        sum = A.elem[0]*A.elem[3]-A.elem[1]*A.elem[2];
        return sum;
    }
    for(int i=0;i<A.cols;i++)
    {
        int n=0;
        fMatrix c(A.cols-1,A.cols-1);
        for(int j=A.cols;j<A.cols*A.rows;j++)
        {
            if(j%A.cols != i)
            {
                c.elem[n] = A.elem[j];
                n++;
                // cout << j << " ";
            }
        }
        // cout << endl;
        
        if(i%2 == 0)
            sum += A.elem[i]*Determinant(c);
            // cout << Determinant(c) << " ";
        if(i%2 == 1)
            sum -= A.elem[i]*Determinant(c);
            // cout << Determinant(c) << " ";
    }
    return sum;    
}
double   Trace       ( const fMatrix & A)// Computes the trace of a square matrix
{
    if(A.cols!=A.rows)
    {
        cout << "shape error!" <<endl;
        return 0;
    }
    double sum = 0;
    for(int i=0;i<A.rows*A.cols;i++)
    {
        if(i/A.cols==i%A.rows)
        {
            sum += A.elem[i];
        }
    }
    return sum;
}

// double   OneNorm     ( const fMatrix & )// Computes the L1-norm of the matrix A, which is the maximum absolute column sum.
// {}
// double   InfNorm     ( const fMatrix & )// Computes the Inf-norm of the matrix A, which is the maximum absolute row sum.
// {}

fMatrix  Inverse  ( const fMatrix & A)// Computes the inverse of a square matrix.
{
    if(A.cols!=A.rows)
    {
        cout << "shape error!" <<endl;
        return 0;
    }
    if(A.cols==2)
    {
        fMatrix c(2,2);
        c.elem[0] = A.elem[3];
        c.elem[1] = -A.elem[1];
        c.elem[2] = -A.elem[2];
        c.elem[3] = A.elem[0];
        return c/Determinant(A);
    }
    fMatrix c(A.rows,A.cols);
    fMatrix d(A.rows-1,A.cols-1);
    for(int i=0;i<A.cols*A.rows;i++)
    {
        // fMatrix d(A.rows-1,A.cols-1);
        int n = 0;
        for(int j=0;j<A.cols*A.rows;j++)
        {
            if(j/A.rows != i/A.rows && j%A.cols != i%A.cols)
            {
                d.elem[n] = A.elem[j];
                // cout<<j;
                n++;
            }
        }
        // cout <<endl;
        // for(int k=0;k<4;k++)
        // {
        //     cout << d.elem[k] << " ";
        // }
        // cout<<"   det="<<Determinant(d)<<endl;
        if (i%2 == 0)
        {
            c.elem[i] = Determinant(d)/Determinant(A);
        }
        else
        {
            c.elem[i] = -Determinant(d)/Determinant(A);
        }
        
        // c = Transp(c);
    
    }
    return Transp(c);
}

// fMatrix  Cholesky	( const fMatrix & )// Computes Cholesky decomposition of a square matrix.	
// {

// }

fVector  Mean		( const fMatrix & A)// Computes column mean value of a matrix.	
{
    fVector c(A.cols);
    Float n;
    for(int i=0;i<A.rows;i++)
    {
        n = 0;
        for(int j=0;j<A.cols;j++)
        {
            n += A.elem[i+j*A.cols];
            // cout << A.elem[i*A.cols+j] << " ";
        }
        // cout << endl;
        c.Array()[i] = n / A.cols;
    }
    return c;
}
fMatrix  Cov			( const fMatrix & A)// Returns a covariance matrix of a square matrix.
{
    fVector Am = Mean(A);
    fMatrix c(A);
    for(int i=0;i<A.cols;i++)
    {
        for(int j=0;j<A.cols;j++)
        {
            c.elem[i*A.cols+j] -= Am.Array()[j]; 
        }
    }
    return (Transp(c)*c) / (A.rows-1);
}
fMatrix  Cov			( const fVector & A)// Returns a covariance matrix of a vector, using outer product.
{
   return Cov(Outer(A,A)); 
}
// void     SVDcmp		( fMatrix &AU, fVector &W, fMatrix &V) // Computes SVD decomposition of a matrix.
// {}
// void     ShowMatrix  ( const fMatrix & A)// Print a matrix on screen.
// {}

/*-------------------------------------------------------------------------*
 *                                                                         *
 *  C O N S T R U C T O R S  & D E S T R U C T O R S                       *
 *                                                                         *
 *-------------------------------------------------------------------------*/
	// Initinalize constructor.
fMatrix::fMatrix( int n_rows, int n_cols)
{
	this->rows = n_rows;
	this->cols = n_cols;
	elem = new Float[rows*cols];
}
	// Assign constructor.
fMatrix::fMatrix( Float *Array, int n_rows , int n_cols  )
{   
	elem = NULL;
    rows = n_rows;
    cols = n_cols;
    elem = new Float[rows*cols];
    memcpy(elem,Array,sizeof(Float)*rows*cols);
}
fMatrix::fMatrix( int n_rows , int n_cols , Float *Array )
{
	elem = NULL;
    rows = n_rows;
    cols = n_cols;
    elem = new Float[rows*cols];
    memcpy(elem,Array,sizeof(Float)*rows*cols);
}
	// Copy constructor.
fMatrix::fMatrix( const fMatrix & A)
{
	rows = A.rows;
	cols = A.cols;
	elem = new Float[rows*cols];
	memcpy(elem, &A.elem[0], sizeof(Float)*rows*cols);	
};  
	// Destructor
fMatrix::~fMatrix( void )
{
	if (elem)
    {
        delete elem;
        elem = NULL;
    }
}

int		fMatrix::Rows() const
{
	return rows;
}
int 	fMatrix::Cols() const
{
	return cols;
}


// static  const fMatrix Null;

/*-------------------------------------------------------------------------*
 *                                                                         *
 *  A S S I G N M E N T    O P E R A T O R S                               *
 *                                                                         *
 *-------------------------------------------------------------------------*/
	// 6. A=B
fMatrix  &fMatrix::operator=( const fMatrix &M )
{
    if (this != &M)
    {
        delete[] this->elem;
        this->elem = new Float[M.rows * M.cols];
        this->rows = M.rows;
        this->cols = M.cols;
        for (int i = 0; i < M.rows * M.cols; i++)
        {
            this->elem[i] = M.elem[i];
        }
    }
    return *this;
};
fMatrix  &fMatrix::operator=( Float s )
{
	for (int i = 0; i < this->rows * this->cols; i++)
    {
        this->elem[i] = s;
    }
	return *this;
};

/*-------------------------------------------------------------------------*
 *                                                                         *
 *  MATRIX OPERATION FUNCTIONS                                             *
 *                                                                         *
 *-------------------------------------------------------------------------*/
	// 7. Swap
	// fMatrix &fMatrix::SwapRows( int i1, int i2 )
	// {
    //     swap(elem[i1],elem[i2]);        
	// }
    // fMatrix &SwapCols( int j1, int j2 );
	// // 8. Inverse
	// fMatrix &Inv(void);

	// void    SetCol( int col, const fVector & )
	// {

	// };
    // void    SetRow( int row, const fVector & );
    // void    SetBlock( int imin, int imax, int jmin, int jmax, const fMatrix & );
    // void    SetBlock( int imin, int imax, int jmin, int jmax, const fVector & );
    // void    SetSize( int rows, int cols )
    // {
    //     fMatrix Z(rows, cols);
    //     return Z;
    // }
    // fVector  GetCol( int col ) const
	// {
        

	// };
    // fVector  GetRow( int row ) const
	// {

	// };
    // fMatrix  GetBlock( int imin, int imax, int jmin, int jmax ) const
	// {
		
	// };

void	fMatrix::Show() const
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<setiosflags(ios::fixed)<<setprecision(4)<<elem[i*cols+j]<<" ";
        }
        cout<<endl;
    }
};
