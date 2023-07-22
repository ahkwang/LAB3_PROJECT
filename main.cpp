#include "mainHeader.h"

int main(int argc, char** argv)
{
    string sorts[] = { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", /*"quick-sort",*/ "counting-sort", "radix-sort", "flash-sort" };
    string orders[] = { "-rand", "-nsorted", "-sorted", "-rev" };
    string para = "-both";
    int inputSizes[] = { 10000, 30000, 50000, 100000, 300000, 500000};

    ofstream fs("input.txt");
    if (!fs)
    {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    fs << "Sort, Order, InputSize, Time(ms), Comparisons\n";

        for (const auto& order : orders)
        {
            for (int inputSize : inputSizes)
            {
                for (int i = 0; i < 10; i++)
                {
                    int* a = new int[inputSize];
                    char* s = new char[order.length() + 1];

                    strcpy(s, order.c_str());

                    generateData(inputSize, a, convertDataType(s));

                    int* copy = new int[inputSize];
                    std::copy(a, a + inputSize, copy);

                    char* sort_c = const_cast<char*>(sorts[i].c_str());
                    long long cnt = 0;
                    measureCount(const_cast<char*>(sorts[i].c_str()), a, inputSize, cnt);
                    double time = measureAlgorithm(const_cast<char*>(sorts[0].c_str()), copy, inputSize);

                    cout << sorts[i] << "," << order << "," << inputSize << "," << time << "," << cnt << std::endl;

                    delete[] copy;
                    delete[] a;
                }
            }
        }
    fs.close();

    return 0;
}
