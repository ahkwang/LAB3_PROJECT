#include "mainHeader.h"

int main(int argc, char* argv[])
{
    if (strcmp(argv[1], "-a") == 0)
    {
        if (argc == 5)
        {
            bool check_number = true;
            for (int i = 0; i < strlen(argv[3]); i++)
            {
                if (argv[3][i] < '0' && argv[3][i] > '9')// nếu không toàn số thì false
                {
                    check_number = false;
                }
            }
            if (!check_number)
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
