#include"mainHeader.h"

void selectionSort(int* a, int n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		int minIdx = i;

		for (size_t j = i + 1; j < n; j++)
		{
			if (a[minIdx] > a[j])
			{
				minIdx = j;
			}
		}

		swap(a[i], a[minIdx]);
	}
}
void insertionSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int idx = i - 1;

		while (++ a[idx] > key && idx >= 0)
		{
			a[idx + 1] = a[idx--];
		}

		a[idx + 1] = key;
	}
}