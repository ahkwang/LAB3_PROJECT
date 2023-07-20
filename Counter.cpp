#include "mainHeader.h"

void  measureSelectionSort(int* a, int n, long long & countCompare)
{
	countCompare = 0;

	for (size_t i = 0; i < n - 1; i++)
	{
		int minIdx = i;

		for (size_t j = i + 1; j < n; j++)
		{
			if (++countCompare && a[minIdx] > a[j])
			{
				minIdx = j;
			}
		}

		swap(a[i], a[minIdx]);
	}
}
void  measureInsertionSort(int* a, int n, long long & countCompare)
{
	countCompare = 0;

	for (int i = 1; i < n; i++)
	{
		int key = a[i];
		int idx = i - 1;

		while (++countCompare && a[idx] > key && ++countCompare && idx >= 0)
		{
			a[idx + 1] = a[idx--];
		}

		a[idx + 1] = key;
	}
}