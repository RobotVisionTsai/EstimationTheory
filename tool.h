struct Complex
{
    double fRe;
    double fIm;
};
Complex ComplexAddst(const Complex A, const Complex B);

Complex operator+(const Complex &A, const Complex &B);