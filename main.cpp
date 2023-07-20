#include"mainHeader.h"

//test main
int main(int argc, char* argv[])
{
    char algorithm1[] = "counting-sort";
    char algorithm2[] = "radix-sort";
    char outputPara[] = "-both";
    char hi[] = "input.txt";
    int n = 100000;
    int* a = new int[n];
    generateData(n, a, 3);
    outputData(hi, a, n);
    command1(algorithm1, hi, outputPara);
    return 0;
}
