#include "mainHeader.h"

int main(int argc, char** argv)
{
    std::string sorts[] = { "selection-sort", "insertion-sort", "bubble-sort", "shaker-sort", "shell-sort", "heap-sort", "merge-sort", "quick-sort", "counting-sort", "radix-sort", "flash-sort" };
    std::string orders[] = { "-rand", "-nsorted", "-sorted", "-rev" };
    std::string para = "-both";
    int inputSizes[] = { 10000, 30000, 50000, 100000 };

    std::ofstream fs("input.txt");
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
            for (const auto& sort : sorts)
            {
                int* a = new int[inputSize];
                char* s = new char[order.length() + 1];

                strcpy(s, order.c_str());

                generateData(inputSize, a, convertDataType(s));

                int* copy = new int[inputSize];
                std::copy(a, a + inputSize, copy);

                char* sort_c = const_cast<char*>(sort.c_str());
                long long cnt = 0;
                /*measureCount(const_cast<char*>(sort.c_str()), a, inputSize, cnt);*/
				int n = inputSize;
				clock_t t1, t2;

				if (strcmp(sort_c, "selection-sort") == 0)
				{
					t1 = clock();
					selectionSort(a, n);
					t2 = clock();
				}
				else
					if (strcmp(sort_c, "insertion-sort") == 0)
					{
						t1 = clock();
						insertionSort(a, n);
						t2 = clock();
					}
					else
						if (strcmp(sort_c, "bubble-sort") == 0)
						{
							t1 = clock();
							bubbleSort(a, n);
							t2 = clock();
						}
						else
							if (strcmp(sort_c, "shaker-sort") == 0)
							{
								t1 = clock();
								shakerSort(a, n);
								t2 = clock();
							}
							else
								if (strcmp(sort_c, "shell-sort") == 0)
								{
									t1 = clock();
									shellSort(a, n);
									t2 = clock();
								}
								else
									if (strcmp(sort_c, "heap-sort") == 0)
									{
										t1 = clock();
										heapSort(a, n);
										t2 = clock();
									}
									else
										if (strcmp(sort_c, "merge-sort") == 0)
										{
											t1 = clock();
											mergeSort(a, n);
											t2 = clock();
										}
										else
											if (strcmp(sort_c, "quick-sort") == 0)
											{
												t1 = clock();
												quickSort(a, n);
												t2 = clock();
											}
											else
												if (strcmp(sort_c, "counting-sort") == 0)
												{
													t1 = clock();
													countingSort(a, n);
													t2 = clock();
												}
												else
													if (strcmp(sort_c, "radix-sort") == 0)
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
				double time =  1.0 * double(t2 - t1) / double(CLOCKS_PER_SEC);

                cout << sort << "," << order << "," << inputSize << "," << time << "," << cnt << std::endl;

                delete[] copy;
                delete[] a;
            }

        }
    }
    

    fs.close();

    return 0;
}
