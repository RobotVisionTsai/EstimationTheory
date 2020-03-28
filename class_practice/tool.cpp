#include "tool.h"

CComplex::CComplex(double fRe, double fIm)
{
    this->m_fRe = fRe;
    this->m_fIm = fIm;
}

CComplex::CComplex(const CComplex& Comp)
{
    this->m_fRe = Comp.m_fRe;
    this->m_fIm = Comp.m_fIm;
}

void CComplex::SetValue(double fRe, double fIm)
{
    this->m_fRe = fRe;
    this->m_fIm = fIm;
}

double CComplex::GetReValue(void) const
{
    return m_fRe;
}

double CComplex::GetImValue(void) const
{
    return m_fIm;
}

CComplex CComplex::Add(const CComplex& A)
{
    CComplex C(0,0);
    C.SetValue(m_fRe+A.m_fRe,
               m_fIm+A.m_fIm);
    return C;           
}

// CComplex CComplex::operator+(const CComplex& A)
// {
//     CComplex C(0,0);
//     C.SetValue(m_fRe+A.GetReValue(),
//                m_fIm+A.GetImValue());
//     return C;           
// }

CComplex operator+(const CComplex& A, const CComplex& B)
{
    return CComplex(A.m_fRe+B.m_fRe, A.m_fIm+B.m_fIm);
}

CComplex operator+(const CComplex& A, double B)
{
    return CComplex(A.m_fRe+B, A.m_fIm);
}
CComplex operator+(double A, const CComplex& B)
{
    return CComplex(A+B.m_fRe, B.m_fIm);
}