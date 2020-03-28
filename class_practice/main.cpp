#include "tool.h"
#include<iostream>

using namespace std;

int main()
{
    CComplex a(1,2);
    CComplex b(3,4);
    CComplex c = a+b;
    cout << c.GetReValue()<<","<< c.GetImValue() << endl;
    CComplex d = a+1;
    cout << d.GetReValue()<<","<< d.GetImValue() << endl;
    CComplex e = 1+a;
    cout << e.GetReValue()<<","<< e.GetImValue() << endl;
    // cout << a.GetReValue()<<","<< a.GetImValue() << endl;
    // a.SetValue(3,4);
    // cout << a.GetReValue()<<","<< a.GetImValue() << endl;

    // CComplex a(1,2);
    // CComplex b(3,4);
    // CComplex c = a+b;
    // CComplex c_ = a.Add(b);
    // cout << c.GetReValue()<<","<< c.GetImValue() << endl;
    // cout << c_.GetReValue()<<","<< c_.GetImValue() << endl;
    // cout <<"---------------------------------"<<endl;
    // CComplex d(a);
    // cout << d.GetReValue() <<"," << d.GetImValue() << endl;


    return 0;
}