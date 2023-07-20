#include"mainHeader.h"

//test main
int main(int argc, char* argv[])
{
    char algorithm1[] = "merge-sort";
    char algorithm2[] = "counting-sort";
    char hi[] = "input.txt";
    int n = 10000;
    int* a = new int[n];
    generateData(n, a, 1);
    outputData(hi, a, n);
    command4(algorithm1, algorithm2, hi);
   
    return 0;
}
