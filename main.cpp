#include"mainHeader.h"

void printArr(int* a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
int main(int argc, char* argv[])
{
    int a[] = {6, 5, 4, 3, 2, 1 };
	long long cnt;
	measureSelectionSort(a, 6, cnt);
	cout << cnt;
    return 0;
}