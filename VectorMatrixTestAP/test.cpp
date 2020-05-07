#include<iostream>
#include "fVector.h"
// #include "fMatrix.h"
// #include "ParamEstimator.h" 
using namespace std;

void testVectorFuns()
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

	// 11. A^B
	cout << "\n11. A^B" << endl;
    (VecA^VecB).Show();

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

	cout << "\nStarts to test vector functions..." << endl;

	// 16. Min(A,B)
	cout << "\n16. Min(A,B)" << endl;
	(Min(VecA,VecB)).Show();

	// 17. Max(A,B)
	cout << "\n17. Max(A,B)" << endl;
	(Max(VecA,VecB)).Show();

	// VecA.Show();
	// VecB.Show();

	// 18. Dist(A,B)
	cout << "\n18. Dist(A,B)" << endl;
	cout << "Dist(A,B) = " << Dist(VecA,VecB) << endl;

	// 19. Normalize(A,B)
	cout << "\n19. Normalize(A)" << endl;
	(Normalize(VecA)).Show();

	// 20. OneNorm(A)
	cout << "\n20. OneNorm(A)" << endl;
	cout << "OneNorm(A) = " << OneNorm(VecA) << endl;

	// 21. TwoNorm(A)
	cout << "\n21. TwoNorm(A)" << endl;
	cout << "TwoNorm(A) = " << TwoNorm(VecA) << endl;

	// 22. TwoNormSqr(A)
	cout << "\n22. TwoNormSqr(A)" << endl;
	cout << "TwoNormSqr(A) = " << TwoNormSqr(VecA) << endl;

	// 23. Sqrt(A,B)
	cout << "\n23. Sqrt(A)" << endl;
	(Sqrt(VecA)).Show();

	// 24. Mean(A)
	cout << "\n24. Mean(A)" << endl;
	cout << "Mean(A) = " << Mean(VecA) << endl;

	// 25. Var(A)
	cout << "\n25. Var(A)" << endl;
	cout << "Var(A) = " << Var(VecA) << endl;

	// 26. Std(A)
	cout << "\n26. Std(A)" << endl;
	cout << "Std(A) = " << Std(VecA) << endl;

}


int main()
{
	testVectorFuns();
	// testMatrixFuns();
	// testParamEstimator();
    getchar();
	return 0;
}