#include "mainHeader.h"

int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-a") == 0)
    {
        if (argc == 5)
        {
            if (argv[3][0] >=0 && argv[3][0]<=9)
            {
                command3(argv[2], argv[3], argv[4]);
            }
            else
            {
                command1(argv[2], argv[3], argv[4]);
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
    return 0;
}
