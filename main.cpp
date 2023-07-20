#include"mainHeader.h"

//test main
int main(int argc, char* argv[])
{

    char algorithm1[] = "counting-sort";
    char algorithm2[] = "radix-sort";
    char hi[] = "input.txt";
    int n = 100000;
    int* a = new int[n];
    generateData(n, a, 1);
    outputData(hi, a, n);
    command4(algorithm1, algorithm2, hi);
   
    return 0;
}
