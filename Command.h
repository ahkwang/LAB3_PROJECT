#pragma once
#include <string>

double measureAlgorithm(char* algorithm, int* a, int n);
bool checkValidAlgorithm(char* algorithm);
int convertDataType(char* inputOrder);
int convertDataTypeOutputParam(char* outputParam);
int *copyArray(int *a,int n);
int checkFile(char* inputFile);
void convertStringOrder(int dataType);
void writeFile(char* fileName, char* name_order, int* a, int n);
void copyArr(int*& dest, int* source, int n);

void measureCount(char* algorithm, int* a, int n, long long& countCompare);

void command1(char* algorithm, char* inputFile, char* outputPara);

void command2(char* algorithm, char* inputSize, char* order, char* outputPara);

void command3(char* algorithm, char* input_size, char* output_param);

void command4(char* algorithm1, char* algorithm2, char* input_file);

void command5(char* algorithm1, char* algorithm2, char* input_size, char* input_order);
