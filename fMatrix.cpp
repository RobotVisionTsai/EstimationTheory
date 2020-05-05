#include<iostream>
#include<string.h>
#include <math.h>
#include "fVector.h"
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
	fMatrix C(A.cols,B.rows);
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
fVector  operator *  ( const fMatrix &A, const fVector & B);
fVector  operator *  ( const fVector &A, const fMatrix & B);

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
	fMatrix C(A.cols,B.rows);
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
fVector& operator *= (       fVector &A, const fMatrix & B);
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
fMatrix  Transp      ( const fMatrix & );	// Transpose of a matrix
fMatrix  AATransp    ( const fMatrix & );	// Computes A * Transp(A).
fMatrix  ATranspA    ( const fMatrix & );	// Computes Transp(A) * A.
fMatrix  Outer       ( const fVector &, const fVector & );  // Computes the outer product of two vectors.
fMatrix  Identity	( int nSize ); // Returns an nSizexnSize identity matrix.

fMatrix  Diag        ( const fVector & );// Returns the square matrix with the elements of the vector d along its diagonal.
fVector  Diag        ( const fMatrix & );// Returns the vector consisting of the diagonal elements of the matrix M
fMatrix  Diag        ( Float, Float, Float );// Returns the 3 x 3 diagonal matrix with x, y, and z as its diagonal elements.

double   Determinant ( const fMatrix & );// Computes the determinant of a square matrix
double   Trace       ( const fMatrix & );// Computes the trace of a square matrix
double   OneNorm     ( const fMatrix & );// Computes the L1-norm of the matrix A, which is the maximum absolute column sum.
double   InfNorm     ( const fMatrix & );// Computes the Inf-norm of the matrix A, which is the maximum absolute row sum.

fMatrix  Inverse  ( const fMatrix & );// Computes the inverse of a square matrix.
fMatrix  Cholesky	( const fMatrix & );// Computes Cholesky decomposition of a square matrix.	
fVector  Mean		( const fMatrix & );// Computes column mean value of a matrix.	
fMatrix  Cov			( const fMatrix & );// Returns a covariance matrix of a square matrix.
fMatrix  Cov			( const fVector & );// Returns a covariance matrix of a vector, using outer product.
void     SVDcmp		( fMatrix &AU, fVector &W, fMatrix &V); // Computes SVD decomposition of a matrix.

void     ShowMatrix  ( const fMatrix & );// Print a matrix on screen.


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

static  const fMatrix Null;

/*-------------------------------------------------------------------------*
 *                                                                         *
 *  A S S I G N M E N T    O P E R A T O R S                               *
 *                                                                         *
 *-------------------------------------------------------------------------*/
	// 6. A=B
	fMatrix  &operator=( const fMatrix &M )
	{

	};
    fMatrix  &operator=( Float s )
	{

	};

/*-------------------------------------------------------------------------*
 *                                                                         *
 *  MATRIX OPERATION FUNCTIONS                                             *
 *                                                                         *
 *-------------------------------------------------------------------------*/
	// 7. Swap
	fMatrix &SwapRows( int i1, int i2 )
	{
		fMatrix C(A.cols,A.rows);
    	if(i1  > A.rows || i2 > A.rows)
    	{
        cout<<"shape error !!!"<<endl;
        return 0;
    	}
	};
    fMatrix &SwapCols( int j1, int j2 );
	// 8. Inverse
	fMatrix &Inv(void);

	void    SetCol( int col, const fVector & )
	{

	};
    void    SetRow( int row, const fVector & );
    void    SetBlock( int imin, int imax, int jmin, int jmax, const fMatrix & );
    void    SetBlock( int imin, int imax, int jmin, int jmax, const fVector & );
    void    SetSize( int rows, int cols = 0 );

    fVector  GetCol( int col ) const
	{

	};
    fVector  GetRow( int row ) const
	{

	};
    fMatrix  GetBlock( int imin, int imax, int jmin, int jmax ) const
	{
		
	};

	void	fMatrix::Show() const
	{

	};

