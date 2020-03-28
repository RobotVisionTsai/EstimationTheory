#include<iostream>
#include "fVector.h"
using namespace std;

int main()
{
    Float a[2] = {1,2};
    Float b[2] = {4,5};

    fVector VecA(a,2);
    fVector VecB(b,2);
    VecA.Show();
    VecB.Show();
    (VecA+VecB).Show();
    // Float a[3] = {1,2,3};
    // Float b[3] = {4,5,6};

    // fVector VecA(a,3);
    // fVector VecB(b,3);
    // VecA.Show();
    // VecB.Show();
    // (VecA+VecB).Show();
    // cout << a << endl;  
    // cout << &a[0] << endl; 
    // cout << &a[1] << endl; 
    // cout << &a[2] << endl; 
    // fVector VecA(1,2,3);
    return 0 ;

}