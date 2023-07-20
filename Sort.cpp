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

void bubbleSort(int* a, int n) {}

void shakerSort(int* a, int n){}

void shellSort(int* a, int n){}

void heapSort(int* a, int n){}

void createHeap(int a, int n, int pos){}

void mergeSort(int* a, int n){}

void quickSort(int* a, int n){}

void countingSort(int* a, int n){}

void radixSort(int* a, int n){}

void flashSort(int* a, int n){}

