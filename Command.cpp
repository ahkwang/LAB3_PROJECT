#include "mainHeader.h"

int convertDataTypeOutputParam(char* outputParam)
{
    if (strcmp(outputParam, "-time") == 0)
        return 0;
    if (strcmp(outputParam, "-comp") == 0)
        return 1;
    if (strcmp(outputParam, "-both") == 0)
        return 2;
    return 3;
}

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

int checkFile(char* inputFile)
{
    fstream fs;
    fs.open(inputFile, ios::in);
    
    if (!fs.is_open())
    {
        return 0;
    }
    fs.close();
    return 1;
}

void copyArr(int*& dest, int* source, int n)
{
    dest = new int[n];

    for (int i = 0; i < n; i++)
        dest[i] = source[i];

}

void command1(char* algorithm, char* inputFile, char* outputPara)
{
    if (!checkValidAlgorithm(algorithm) || !checkFile(inputFile) || convertDataTypeOutputParam(outputPara) == 3)
    {
        cout << ("Error: unknown command line format!\n");
        return;
    }
    int* a;
    int* b;
    int n;
    long long countCompare = 0;

    inputData(inputFile, a, n);
    copyArr(b, a, n);

    cout << "ALGORITHM MODE";
    cout << "\nAlgorithm: " << algorithm;
    cout << "\nInput file: " << inputFile;
    cout << "\nInput size: " << n;
    cout << "\n--------------------------";
    if (convertDataTypeOutputParam(outputPara) == 0)
    {
        cout << "\nRunning time: " << measureAlgorithm(algorithm, a, n) << " ms";
    }
    else if (convertDataTypeOutputParam(outputPara) == 1)
    {
        measureCount(algorithm, a, n, countCompare);
        cout << "\nComparisions: " << countCompare;
    }
    else
    {
        cout << "\nRunning time: " << measureAlgorithm(algorithm, a, n) << " ms";
        
        measureCount(algorithm, b, n, countCompare);
        cout << "\nComparisions: " << countCompare;
    }
    
    delete a;
    delete b;
}

void convertStringOrder(int dataType)
{
    if (dataType == 0)
    {
        cout << "randomized data";
        return;
    }
    if (dataType == 1)
    {
        cout << "nearly sorted data";
        return;
    }
    if (dataType == 2)
    {
        cout << "sorted data";
        return;
    }
    cout << "reverse sorted data";
}

void command2(char* algorithm, char* inputSize, char* order, char* outputPara)
{
    if (!checkValidAlgorithm(algorithm) || convertDataType(order) == 4 || convertDataTypeOutputParam(outputPara) == 3 || atoll(inputSize) < 0 || atoll(inputSize) > 1e9)
    {
        cout << ("Error: unknown command line format!\n");
        return;
    }

    int n = atoi(inputSize);
    int* a = new int[n];
    int* b;
    long long countCompare = 0;
    generateData(n, a, convertDataType(order));
    
    copyArr(b, a, n);

    cout << "ALGORITHM MODE";
    cout << "\nAlgorithm: " << algorithm;
    cout << "\nInput size: " << n;
    cout << "\nInput order: "; 
    convertStringOrder(convertDataType(order));
    /*convertStringOrder(convertDataTypeOutputParam(outputPara));*/
    cout << "\n--------------------------";
    if (convertDataTypeOutputParam(outputPara) == 0)
    {
        cout << "\nRunning time: " << measureAlgorithm(algorithm, a, n) << " ms";
    }
    else if (convertDataTypeOutputParam(outputPara) == 1)
    {
        measureCount(algorithm, a, n, countCompare);
        cout << "\nComparisions: " << countCompare;
    }
    else
    {
        cout << "\nRunning time: " << measureAlgorithm(algorithm, a, n) << " ms";

        measureCount(algorithm, b, n, countCompare);
        cout << "\nComparisions: " << countCompare;
    }

    delete a;
    delete b;

}
void command4(char* algorithm1, char* algorithm2, char* input_file)
{
    //check algo
    //cout<<algorithm1<<endl;
    if (!checkValidAlgorithm(algorithm1) || !checkValidAlgorithm(algorithm2))
    {
        cout << ("Error: unknown command line format!\n");
        return;
    }
    
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
    measureCount(algorithm1, a, n, countCompare1);
    measureCount(algorithm2, a, n, countCompare2);

    double time1 = measureAlgorithm(algorithm1, a, n);
    double time2 = measureAlgorithm(algorithm2, a, n);

    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << n << endl;
    cout << "-------------------------\n";
    cout << "Running time: " << fixed << setprecision(5) << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << setprecision(0) << countCompare1 << " | " << countCompare2 << endl;
    
    delete[]a;
}