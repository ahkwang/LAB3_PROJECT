#include "mainHeader.h"

void  measureSelectionSort(int* a, int n, long long & countCompare)
{
	countCompare = 0;

	for (size_t i = 0; (++countCompare), i < n - 1; i++)
	{
		int minIdx = i;

		for (size_t j = i + 1; (++countCompare), j < n; j++)
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

	for (int i = 1; (++countCompare), i < n; i++)
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

void  measureBubbleSort(int* a, int n, long long& countCompare)
{
	return;
}

void  measureShakerSort(int* a, int n, long long& countCompare)
{
	return;
}

void  measureShellSort(int* a, int n, long long& countCompare){}

void  measureHeapSort(int* a, int n, long long& countCompare){}

void  measureMergeSort(int* a, int n, long long& countCompare){}

void  measureQuickSort(int* a, int n, long long& countCompare){}

void  measureCountingSort(int* a, int n, long long& countCompare){}

void  measureRadixSort(int* a, int n, long long& countCompare){}

void measureFlashSort(int* a, int n, long long& countCompare){}