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

void  measureCountingSort(int* a, int n, long long& countCompare)
{
	countCompare = 0;

	int maxValue = a[0];

	for (int i = 0; ++countCompare, i < n; i++)
		if (++countCompare && maxValue < a[i])
			maxValue = a[i];

	int minValue = a[0];

	for (int i = 0; ++countCompare && i < n; i++)
		if (++countCompare && minValue > a[i])
			minValue = a[i];

	int maxNum = maxValue - minValue + 1;
	int* countArr = new int[maxNum];
	int* sortedArr = new int[n];

	for (int i = 0; ++countCompare, i < maxNum; i++)
		countArr[i] = 0;

	for (int i = 0; ++countCompare, i < n; i++)
		sortedArr[i] = 0;

	for (int i = 0; ++countCompare, i < n; i++)
		countArr[a[i] - minValue]++;
	for (int i = 1; ++countCompare, i < maxNum; i++)
		countArr[i] += countArr[i - 1];

	for (int i = 0; ++countCompare, i < n; i++)
	{
		sortedArr[countArr[a[i] - minValue] - 1] = a[i];
		countArr[a[i] - minValue]--;
	}
	for (int i = 0; ++countCompare, i < n; i++)
		a[i] = sortedArr[i];

}

void  measureRadixSort(int* a, int n, long long& countCompare){}

void measureFlashSort(int* a, int n, long long& countCompare){}