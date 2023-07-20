#pragma once

void inputData(const char* filename, int*& a, int& n);
void outputData(const char* filename, int* a, int n);
void generateRandomData(int n, int Arr[]);
void generateSortedData(int n, int Arr[]);
void generateReverseData(int n, int Arr[]);
void generateNearlySortedData(int n, int Arr[]);
void generateData(int n, int Arr[], int dataType);