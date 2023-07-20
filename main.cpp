#include"mainHeader.h"

//test main
int main(int argc, char* argv[])
{
    char algorithm1[] = "counting-sort";
    char algorithm2[] = "radix-sort";
    char outputPara[] = "-both";
    char inputSize[] = "100000";
    char order[] = "-rand";
    char hi[] = "input.txt";
    int n = 100000;
    int* a = new int[n];
    generateData(n, a, 3);
    outputData(hi, a, n);
    command2(algorithm1, inputSize, order, outputPara);
    return 0;
}
