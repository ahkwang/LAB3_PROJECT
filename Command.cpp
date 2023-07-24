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
	return 1000.0 * double(t2 - t1) / double(CLOCKS_PER_SEC);
	//return in miliseconds
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


void measureCount(char* algorithm, int* a, int n, long long& countCompare)
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

	const char* output = "output.txt";
	outputData(output, a, n);

	delete[] a;
	delete[] b;
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

	const char* output = "output.txt";
	outputData(output, a, n);

	delete[] a;
	delete[] b;

}

int* copyArray(int* a, int n)
{
	int* tmp = new int[n];
	for (int i = 0; i < n; i++)tmp[i] = a[i];
	return tmp;
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
	int* tmp;
	tmp = copyArray(a, n);
	measureCount(algorithm1, tmp, n, countCompare1);

	delete[] tmp;
	tmp = copyArray(a, n);
	measureCount(algorithm2, tmp, n, countCompare2);

	delete[] tmp;
	tmp = copyArray(a, n);
	double time1 = measureAlgorithm(algorithm1, tmp, n);
	delete[] tmp;
	tmp = copyArray(a, n);
	double time2 = measureAlgorithm(algorithm2, tmp, n);
	delete[] tmp;


	cout << "COMPARE MODE\n";
	cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
	cout << "Input file: " << input_file << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------\n";
	cout << "Running time: " << fixed << setprecision(5) << time1 << " ms | " << time2 <<" ms"<< endl;
	cout << "Comparisions: " << setprecision(0) << countCompare1 << " | " << countCompare2 << endl;

	delete []a;
}
//////////
void command3(char* algorithm, char* input_size, char* output_param)
{
	if (!checkValidAlgorithm(algorithm)) return;

	int n = atoi(input_size);
	int* a = new int[n];
	int parameter_type = convertDataTypeOutputParam(output_param);

	// tạo mảng chứa tên kiểu dữ liệu
	char** name_order = new char* [4];
	name_order[0] = new char[10];
	strcpy(name_order[0], "Randomize");
	name_order[1] = new char[14];
	strcpy(name_order[1], "Nearly Sorted");
	name_order[2] = new char[7];
	strcpy(name_order[2], "Sorted");
	name_order[3] = new char[9];
	strcpy(name_order[3], "Reversed");

	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << algorithm << endl;
	cout << "Input size: " << n << endl;

	for (int i = 0; i < 4; i++)
	{
		char* fileName = new char[12];
		strcpy(fileName, "input_0.txt");
		fileName[6] = i + 1 + 48;//thay đổi tên file
		writeFile(fileName, name_order[i], a, n);// hàm vừa tạo ra dữ liệu và ghi dữ liệu vào file
		// tạo 1 mảng phụ b để có thể thực hiện 2 lần phép đo
		int* b = new int[n];
		for (int j = 0; j < n; j++)
		{
			b[j] = a[j];
		}

		cout << "\nInput order: " << name_order[i];
		cout << "\n-------------------------\n";
		if (parameter_type == 0 || parameter_type == 2)
		{
			double res = measureAlgorithm(algorithm, a, n);
			cout << "Running time: " << res <<" ms"<< endl;
		}
		if (parameter_type == 1 || parameter_type == 2)
		{
			long long countCompare = 0;
			measureCount(algorithm, b, n, countCompare);
			cout << "Comparisions: " << countCompare << endl;
		}
		delete[]fileName;
	}

}
void writeFile(char* fileName, char* name_order, int* a, int n)
{
	fstream input;
	input.open(fileName, ios::out);
	input << n << '\n';
	if (strcmp(name_order, "Randomize") == 0)
	{
		generateRandomData(n, a);
	}
	else if (strcmp(name_order, "Nearly Sorted") == 0)
	{
		generateNearlySortedData(n, a);
	}
	else if (strcmp(name_order, "Sorted") == 0)
	{
		generateSortedData(n, a);
	}
	else if (strcmp(name_order, "Reversed") == 0)
	{
		generateReverseData(n, a);
	}
	else
	{
		return;
	}

	for (int i = 0; i < n; i++)
	{
		input << a[i] << " ";
	}
}

void command5(char* algorithm1, char* algorithm2, char* input_size, char* input_order)
{
	if (!checkValidAlgorithm(algorithm1) || !checkValidAlgorithm(algorithm2))
	{
		cerr << "Error: Invalid sort algorithm." << endl;
		return;
	}

	int n = stoi(input_size);
	int dataType = -1;
	dataType = convertDataType(input_order);

	if (dataType < 0)
	{
		cerr << "Error: Invalid data type." << endl;
		return;
	}

	int* array1 = new int[n];
	int* array2 = new int[n];
	generateData(n, array1, dataType);
	copy(array1, array1 + n, array2); // copy array1 to array2

	double time1 = -1, time2 = -1;
	long long count_compare1 = 0, count_compare2 = 0;

	int* temp1 = new int[n];
	int* temp2 = new int[n];
	copy(array1, array1 + n, temp1);
	copy(array1, array1 + n, temp2);

	// count comparisions
	measureCount(algorithm1, array1, n, count_compare1);
	measureCount(algorithm2, array2, n, count_compare2);

	// run time
	time1 = measureAlgorithm(algorithm1, temp1, n);
	time2 = measureAlgorithm(algorithm2, temp2, n);

	// PRINT DATA
	cout << "COMPARE MODE" << endl;
	cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
	cout << "Input size: " << n << endl;
	cout << "Input order: ";
	convertStringOrder(dataType);
	cout << "\n------------------------------------------------------\n";
	cout << setprecision(9);
	cout << "Running time: " << time1 << " ms | " << time2<<" ms"<< endl;
	cout << "Comparisions: " << count_compare1 << " | " << count_compare2 << endl;

	delete[] temp1;
	delete[] temp2;
	delete[] array1;
	delete[] array2;
}