#pragma once

void  measureSelectionSort(int* a, int n, long long& countCompare);

void  measureInsertionSort(int* a, int n, long long& countCompare);

void  measureBubbleSort(int* a, int n, long long& countCompare);

void  measureShakerSort(int* a, int n, long long& countCompare);

void  measureShellSort(int* a, int n, long long& countCompare);

void  measureHeapSort(int* a, int n, long long& countCompare);
void countCreateHeap(int *a,int n, int pos, long long &countCompare);

void  measureMergeSort(int* a, int n, long long& countCompare);

void measureMergeSort(int *a,int n , long long &countCompare);
void countMergeArray(int *a,int l,int r,int mid, long long &countCompare);
void countStartMergeSort(int *a, int l, int r, long long &countCompare);


void  measureQuickSort(int* a, int n, long long& countCompare);
void measureQuickSort_function(int* a, int left, int right, long long& countCompare);

void  measureCountingSort(int* a, int n, long long& countCompare);

void  measureRadixSort(int* a, int n, long long& countCompare);

void measureRadixSort(int *a, int n, long long &countCompare);
int countDigit2(int x, long long &countCompare);
int digit2(int x,int k, long long &countCompare);
void countCountingSortForBase_k(int *a,int n,int k,long long &countCompare);

void measureFlashSort(int* a, int n, long long& countCompare);