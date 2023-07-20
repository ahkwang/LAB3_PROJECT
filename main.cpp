#include"mainHeader.h"

//test main
int main(int argc, char* argv[])
{
<<<<<<< HEAD
  //  srand(time(NULL));
    char algorithm1[] = "heap-sort";
    char algorithm2[] = "insertion-sort";
    char hi[] = "input.txt";
    int n = 10000;
    int* a = new int[n];
    //generateRandomData(n,a);
    //outputData(hi, a, n);
    cout<<"HHI";
=======
    char algorithm1[] = "selection-sort";
    char algorithm2[] = "counting-sort";
    char hi[] = "input.txt";
    int n = 10000;
    int* a = new int[n];
    generateData(n, a, 1);
    outputData(hi, a, n);
>>>>>>> origin/kh
    command4(algorithm1, algorithm2, hi);
    cout<<endl<<"hihi";
    return 0;
}
