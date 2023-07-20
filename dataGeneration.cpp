#include "mainHeader.h"

void inputData(const char* filename, int*& a, int& n)
{
	fstream fs;
	fs.open(filename, ios::in);

	if (!fs)
		return;

	fs >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
		fs >> a[i];

	fs.close();
}

void outputData(const char* filename, int* a, int n)
{
	fstream fs;
	fs.open(filename, ios::out);

	if (!fs)
		return;

	fs << n << endl;

	for (int i = 0; i < n; i++)
		fs << a[i] << " ";

	fs.close();
}

void generateRandomData(int n, int Arr[])
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
		Arr[i] = rand() % n;
}

void generateSortedData(int n, int Arr[])
{
	for (int i = 0; i < n; i++)
		Arr[i] = i;
}

void generateReverseData(int n, int Arr[])
{
	for (int i = 0; i < n; i++)
		Arr[i] = n - 1 - i;
}

void generateNearlySortedData(int n, int Arr[])
{
	for (int i = 0; i < n; i++)
		Arr[i] = i;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(Arr[r1], Arr[r2]);
	}
}

void generateData(int n, int Arr[], int dataType)
{
	switch (dataType)
	{
	case 0:
		generateRandomData(n, Arr);
		break;
	case 1:
		generateNearlySortedData(n, Arr);
		break;
	case 2:
		generateSortedData(n, Arr);
		break;
	case 3:
		generateReverseData(n, Arr);
		break;
	default:
		cout << ("Error: unknown data type!\n");
	}
}