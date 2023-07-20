#include "mainHeader.h"

double measureAlgorithm(char* algorithm, int* a, int n)
{
    clock_t t1, t2;
    if (strcmp(algorithm, "selection-sort") == 0)
    {
        t1 = clock();
        selectionSort(a, n);
        t2 = clock();
    }
    else
        if (strcmp(algorithm, "insertion-sort") == 0)
        {
            t1 = clock();
            insertionSort(a, n);
            t2 = clock();
        }
        else
            if (strcmp(algorithm, "bubble-sort") == 0)
            {
                t1 = clock();
                bubbleSort(a, n);
                t2 = clock();
            }
            else
                if (strcmp(algorithm, "shaker-sort") == 0)
                {
                    t1 = clock();
                    shakerSort(a, n);
                    t2 = clock();
                }
                else
                    if (strcmp(algorithm, "shell-sort") == 0)
                    {
                        t1 = clock();
                        shellSort(a, n);
                        t2 = clock();
                    }
                    else
                        if (strcmp(algorithm, "heap-sort") == 0)
                        {
                            t1 = clock();
                            heapSort(a, n);
                            t2 = clock();
                        }
                        else
                            if (strcmp(algorithm, "merge-sort") == 0)
                            {
                                t1 = clock();
                                mergeSort(a, n);
                                t2 = clock();
                            }
                            else
                                if (strcmp(algorithm, "quick-sort") == 0)
                                {
                                    t1 = clock();
                                    quickSort(a, n);
                                    t2 = clock();
                                }
                                else
                                    if (strcmp(algorithm, "counting-sort") == 0)
                                    {
                                        t1 = clock();
                                        countingSort(a, n);
                                        t2 = clock();
                                    }
                                    else
                                        if (strcmp(algorithm, "radix-sort") == 0)
                                        {
                                            t1 = clock();
                                            radixSort(a, n);
                                            t2 = clock();
                                        }
                                        else//flash sort
                                        {
                                            t1 = clock();
                                            flashSort(a, n);
                                            t2 = clock();
                                        }
    return 1.0 * double(t2 - t1) / double(CLOCKS_PER_SEC);
}

bool checkValidAlgorithm(char* algorithm)
{
    if (strcmp(algorithm, "selection-sort") == 0)return true;
    else
        if (strcmp(algorithm, "insertion-sort") == 0)return true;
        else
            if (strcmp(algorithm, "bubble-sort") == 0)return true;
            else
                if (strcmp(algorithm, "shaker-sort") == 0)return true;
                else
                    if (strcmp(algorithm, "shell-sort") == 0)return true;
                    else
                        if (strcmp(algorithm, "heap-sort") == 0)return true;
                        else
                            if (strcmp(algorithm, "merge-sort") == 0)return true;
                            else
                                if (strcmp(algorithm, "quick-sort") == 0)return true;
                                else
                                    if (strcmp(algorithm, "counting-sort") == 0)return true;
                                    else
                                        if (strcmp(algorithm, "radix-sort") == 0)return true;
                                        else
                                            if (strcmp(algorithm, "flash-sort") == 0)return true;
                                            else return false;
}

int convertDataType(char* inputOrder)
{
    if (strcmp(inputOrder, "-rand") == 0)
        return 0;
    if (strcmp(inputOrder, "-nsorted") == 0)
        return 1;
    if (strcmp(inputOrder, "-sorted") == 0)
        return 2;
    if (strcmp(inputOrder, "-rev") == 0)
        return 3;
    return 4;
}

void measureCount(char* algorithm, int* a, int n, long long & countCompare)
{
    countCompare = 0;
    if (strcmp(algorithm, "selection-sort") == 0)
    {
        measureSelectionSort(a, n, countCompare);
    }
    else
        if (strcmp(algorithm, "insertion-sort") == 0)
        {
            measureInsertionSort(a, n, countCompare);
        }
        else
            if (strcmp(algorithm, "bubble-sort") == 0)
            {
                measureBubbleSort(a, n, countCompare);
            }
            else
                if (strcmp(algorithm, "shaker-sort") == 0)
                {
                    measureShakerSort(a, n, countCompare);
                }
                else
                    if (strcmp(algorithm, "shell-sort") == 0)
                    {
                        measureShellSort(a, n, countCompare);
                    }
                    else
                        if (strcmp(algorithm, "heap-sort") == 0)
                        {
                            measureHeapSort(a, n, countCompare);
                        }
                        else
                            if (strcmp(algorithm, "merge-sort") == 0)
                            {
                                measureMergeSort(a, n, countCompare);
                            }
                            else
                                if (strcmp(algorithm, "quick-sort") == 0)
                                {
                                    measureQuickSort(a, n, countCompare);
                                }
                                else
                                    if (strcmp(algorithm, "counting-sort") == 0)
                                    {
                                        measureCountingSort(a, n, countCompare);
                                    }
                                    else
                                        if (strcmp(algorithm, "radix-sort") == 0)
                                        {
                                            measureRadixSort(a, n, countCompare);
                                        }
                                        else//flash sort
                                        {
                                            measureFlashSort(a, n, countCompare);
                                        }
}

int *copyArray(int *a,int n)
{
    int *tmp=new int[n];
    for(int i=0;i<n;i++)tmp[i]=a[i];
    return tmp;
}

void command4(char* algorithm1, char* algorithm2, char* input_file)
{
    //check algo
    //cout<<algorithm1<<endl;
    if (!checkValidAlgorithm(algorithm1)) return;
    if (!checkValidAlgorithm(algorithm2)) return;
    
    int n;
    ifstream file;
    file.open(input_file);

    if (!file.is_open())
    {
        cout << "Cannot open file!\n";
        return;
    }
    file >> n;
    int* a;
    a = new int[n];
    for (int i = 0; i < n; i++)file >> a[i];
    file.close();
    //   for(int i=0;i<n;i++)cout<<a[i]<<" ";

    long long countCompare1, countCompare2;
    int * tmp;
    tmp =copyArray(a,n);
    measureCount(algorithm1, tmp, n, countCompare1);
    
    delete [] tmp;
    tmp=copyArray(a,n);
    measureCount(algorithm2, tmp, n, countCompare2);
    cout<<"here";
    delete [] tmp;
    tmp=copyArray(a,n);
    double time1 = measureAlgorithm(algorithm1, tmp, n);
    delete [] tmp;
    tmp=copyArray(a,n);
    double time2 = measureAlgorithm(algorithm2, tmp, n);
    delete [] tmp;
    

    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << n << endl;
    cout << "-------------------------\n";
    cout << "Running time: " << fixed << setprecision(5) << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << setprecision(0) << countCompare1 << " | " << countCompare2 << endl;
  //  for (int i = 0; i < n; i++)cout << a[i] << " ";
    delete []a;
}