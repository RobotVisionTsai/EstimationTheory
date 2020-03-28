#include "tool.h"

Complex ComplexAddst(const Complex A, const Complex B)
{
    Complex C;
    C.fIm = A.fIm + B.fIm;
    C.fRe = A.fRe + B.fRe;
    return C;
}

Complex operator+(const Complex& A, const Complex& B)
{
    Complex C;
    C.fIm = A.fIm + B.fIm;
    C.fRe = A.fRe + B.fRe;
    return C;
}