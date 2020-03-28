#include "CComplex.h"

CComplex::CComplex(double Re,double Im)
{
    m_fIm = Im ;
    m_fRe = Re ;
}

// CComplex::Add(const CComplex& A)
// {
//     CComplex C;
//     C.fIm = A.Im + B.fIm;
//     C.fRe = A.fRe + B.fRe;
//     return C;
// }