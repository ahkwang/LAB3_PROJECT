#pragma once

void selectionSort(int* a, int n);

void insertionSort(int* a, int n);

void bubbleSort(int* a, int n);

void shakerSort(int* a, int n);

void shellSort(int* a, int n);

void heapSort(int* a, int n);
void createHeap(int *a,int n, int pos);

void mergeSort(int *a,int n);
void mergeArray(int *a,int l,int r,int mid);
void startMergeSort(int *a, int l, int r);


void quickSort(int* a, int n);

void countingSort(int* a, int n);

void radixSort(int *a, int n);
int countDigit(int x);
int digit(int x,int k);
void countingSortForBase_k(int *a,int n,int k);



void flashSort(int* a, int n);

