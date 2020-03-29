#include<iostream>
#include "fVector.h"
using namespace std;

int main()
{
    Float A[3] = {1.1, 2.2, 3.3};
	Float B[3] = {4.4, 5.5, 6.6};

	fVector VecA(A, 3);
	fVector VecB(B, 3);

	cout << "\nVecA = " << endl;
	VecA.Show();
	
	cout << "\nVecB = " << endl;
	VecB.Show();
	
	cout << "\nStarts to test vector operators..." << endl;
	// 1. A+B
	cout << "\n1. A+B" << endl;
	(VecA+VecB).Show();

	// 2. A-B
	cout << "\n2. A-B" << endl;
	(VecA-VecB).Show();
    
    // 3. -A
	cout << "\n3. -A" << endl;
	(-VecA).Show();

    // 4. A-2
	cout << "\n4. A-2" << endl;
	(VecA-2).Show();

    // 5. 2-A
	cout << "\n5. 2-A" << endl;
	(2-VecA).Show();

    // 6. A*2
	cout << "\n6. A*2" << endl;
	(VecA*2).Show();

    // 7. 0.5*B
	cout << "\n7. 0.5*B" << endl;
	(0.5*VecB).Show();
    
    // 8. A/4
	cout << "\n8. A/4" << endl;
	(VecA/4).Show();

    // 9. A/B
	cout << "\n9. A/B" << endl;
	(VecA/VecB).Show();

    // 10. A*B
	cout << "\n10. A*B" << endl;
	cout << "A*B = " << VecA*VecB << endl;

    // 12. A+=B
	cout << "\n12. A+=B" << endl;
	(VecA+=VecB).Show();

    // 13. A-=B
	cout << "\n13. A-=B" << endl;
	(VecA-=VecB).Show();

    // 14. A*=5
	cout << "\n14. A*=5" << endl;
	(VecA*=5).Show();

    // 15. A/=5
	cout << "\n15. A/=5" << endl;
	(VecA/=5).Show();

    //Copy Vector
    cout << "\nCopy Vector A -> C" <<endl;
    fVector VecC(VecA);
    VecC.Show();

    cout << &VecA << endl << &VecC << endl; 

    return 0 ;

}