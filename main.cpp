#include"mainHeader.h"

int main(int argc, char** argv)
{
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
			if(check==true){command3(argv[2],argv[3],argv[4]);}
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
}
