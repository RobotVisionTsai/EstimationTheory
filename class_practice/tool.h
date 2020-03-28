class CComplex
{
friend CComplex operator+(const CComplex& A, const CComplex& B);
friend CComplex operator+(const CComplex& A, double B);
friend CComplex operator+(double A, const CComplex& B);

public:
    CComplex(double fRe, double fIm);
    CComplex(const CComplex& Comp);
    // CComplex(const Complex& Comp);
    void SetValue(double fRe, double fIm);
    double GetReValue(void) const;
    double GetImValue(void) const;
    CComplex Add(const CComplex& A);
    // CComplex operator+(const CComplex& A);
// 複數加法動作
private:
    double m_fRe;
    double m_fIm;
};