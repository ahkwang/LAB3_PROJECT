#include"mainHeader.h"

//test main
int main(int argc, char* argv[])
{
    // char algorithm1[] = "counting-sort";
    // char algorithm2[] = "radix-sort";
    // char hi[] = "input.txt";
    // int n = 100000;
    // int* a = new int[n];
    // generateData(n, a, 1);
    // outputData(hi, a, n);
    // command4(algorithm1, algorithm2, hi);
    // return 0;
     if (argc == 6)
    {
        string mode = argv[1];
        if (mode == "-c") // -c: compare mode
        {
            // string algorithm1 = argv[2];
            // string algorithm2 = argv[3];
            // int size = stoi(argv[4]); // input size
            // string order = argv[5];   // input order
            // Command5(algorithm1, algorithm2, size, order);
            char *algorithm1 = argv[2];
            char *algorithm2 = argv[3];
            char *size = argv[4];
            char *order = argv[5];
            command5(algorithm1, algorithm2, size, order);
        }
        else
        {
            cerr << "Error: Invalid mode." << endl;
            return 1;
        }
    }
    else
    {
        cerr << "Error: Invalid number of arguments." << endl;
        cout << "Usage: " << argv[0] << " -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]" << endl;
        return 1;
    }

    return 0;
}
