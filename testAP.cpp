#include<iostream>
#include "fVector.h"
using namespace std;

int main()
{

    Float a[3] = {1,2,4};
    fVector VecA(a,3);
    VecA.Show();

    fVector VecB(4,5,6);
    VecB.Show();

    // cout << a << endl;  
    // cout << &a[0] << endl; 
    // cout << &a[1] << endl; 
    // cout << &a[2] << endl; 
    // fVector VecA(1,2,3);
    return 0 ;

}