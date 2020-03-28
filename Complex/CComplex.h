class CComplex
{
public:
    CComplex(double fRe, double fIm);
    // CComplex(const CComplex& Comp);
    // CComplex(const CComplex& Comp);
    // void SetValue(double fRe, double fIm);
    // double GetReValue(void) const;
    // double GetImValue(void) const;
    CComplex Add(const CComplex& A);
    // 複數加法動作
private:
    double m_fRe;
    double m_fIm;
};