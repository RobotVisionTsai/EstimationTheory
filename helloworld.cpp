#include <iostream>
using namespace std;

#define ROW		2
#define COL		4

int main(int argc, char** argv)
{
	int i = 0, j = 0;
	int** ptr2 = NULL;
	//生成一維指標陣列
	ptr2 = new int* [ROW];
	//每個指標陣列再生成整數陣列
	for (i = 0; i < ROW; i++) ptr2[i] = new int[COL];
	//Write
	int cnt = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++) ptr2[i][j] = cnt++;
	}
	//Read value and address
	for (i = 0; i < ROW; i++) 
	{
		for (j = 0; j < COL; j++)
		{
			cout << "ptr2[" << i << "][" << j << "]=" << ptr2[i][j];
			cout << "(" << hex << &ptr2[i][j] << ")" << endl;
		}
	}
	for (i = 0; i < ROW; i++)delete(ptr2[i]);
	//釋放指標
	delete ptr2;
	return 0;
}