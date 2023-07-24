#include "mainHeader.h"

int main(int argc, char* argv[])
{
    /*char* a = new char[11];
    char* b = new char[7];
    char* c = new char[6];
    strcpy(a, "quick-sort");
    strcpy(b, "input_1.txt");
    strcpy(c, "-both");

    command1(a,b,c);*/
    if (strcmp(argv[1], "-a") == 0)
    {
        if (argc == 5)
        {
            if (argv[3][0] >=0 && argv[3][0]<=9)
            {
                command1(argv[2], argv[3], argv[4]);
            }
            else
            {
                command3(argv[2], argv[3], argv[4]);
            }
        }
        else
        {
            command2(argv[2], argv[3], argv[4], argv[5]);
        }
    }
    else
    {
        if (argc == 5)
        {
            command4(argv[2], argv[3], argv[4]);
        }
        else
        {
            command5(argv[2], argv[3], argv[4], argv[5]);
        }
    }

    /*char sorts[][20] = {"selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort"};
    char orders[][20] = {"-rand", "-nsorted", "-sorted", "-rev"};
    string orderString[] = {"rand", "nsorted", "sorted", "rev"};
    string para = "-both";
    int inputSizes[] = { 10000, 30000, 50000, 100000, 300000, 500000};

    ofstream fs("output.csv");
    if (!fs)
    {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    int idx = 0;

    fs << "Sort, Order, InputSize, Time(ms), Comparisons\n";

        for ( auto order : orders)
        {
            for (int inputSize : inputSizes)
            {
                for (int i = 0; i < 11; i++)
                {
                    int* a = new int[inputSize];


                    generateData(inputSize, a, convertDataType(order));

                    int* copy = new int[inputSize];
                    std::copy(a, a + inputSize, copy);

                    long long cnt = 0;
                    measureCount(sorts[i], a, inputSize, cnt);
                    double time = measureAlgorithm(sorts[i], copy, inputSize);

                    cout << sorts[i] << "," << orderString[idx] << "," << inputSize << "," << time << "," << cnt << std::endl;

                    delete[] copy;
                    delete[] a;
                }
            }
            idx++;
        }
    fs.close();*/
    return 0;
}
