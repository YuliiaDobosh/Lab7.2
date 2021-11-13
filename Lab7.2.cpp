#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);

void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int k , const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int MaxMin(int** a, const int rowCount, const int colCount)
{
	int* min = new int[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		min[i] = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] < min[i])
				min[i] = a[i][j];
	}
	int max = min[0];
	for (int i = 1; i < rowCount; i++)
		if (min[i] > max)
			max = min[i];
	delete[] min;
	return max;
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	int k;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a,k, n, Low, High);
	Print(a, k,n);
	cout << "Max From Min " << MaxMin(a, k, n) << endl;
	return 0;
}

