#include "tool.h"
#include<iostream>
using namespace std;

// struct Complex 
// {
//     double fRe;
//     double fIm;
// };

// Complex ComplexAddst(const Complex A, const Complex B)
// {
//     Complex C;
//     C.fIm = A.fIm + B.fIm;
//     C.fRe = A.fRe + B.fRe;
//     return C;
// }

int main()
{
    Complex A={1,2};
    Complex B={3,4};
    Complex C[2];
    C[0] = ComplexAddst(A, B);
    cout << C[0].fIm << endl;
    return 0;
}