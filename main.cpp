#include "mainHeader.h"

int main(int argc, char** argv)
{
<<<<<<<<< Temporary merge branch 1
	if(argc==5)
	{	
		if(!strcmp(argv[1],"-c")){command4(argv[2],argv[3],argv[4]);}
		else
		{
			bool check=false;
			for(int i=0;i<strlen(argv[3]-1);i++)
			{
				if(argv[3][i]=='.')
				{
			
					if(argv[3][i+1]>='a'&&argv[3][i+1]<='z')check=true;
					if(argv[3][i+1]>='A'&&argv[3][i+1]<='Z')check=true;
				}
			}
			if(!check){command3(argv[2],argv[3],argv[4]);}
			else {command1(argv[2],argv[3],argv[4]);}
		}
	}
	else
	if(argc==6)
	{
		if(!strcmp(argv[1],"-a")){command2(argv[2],argv[3],argv[4],argv[5]);}
		else {command5(argv[2],argv[3],argv[4],argv[5]);}
	}
	else 
	{
		cout<<"Not a command\n";
	}
	return 0;
=========
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
>>>>>>>>> Temporary merge branch 2
}
