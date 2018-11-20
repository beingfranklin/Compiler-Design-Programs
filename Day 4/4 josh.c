#include<stdio.h>
#include<stdlib.h>

int i=0;
char ip[20];

int S();
int A();
int B();

void main()
{
        scanf("\n%s" , ip);
	printf("\n");
        if(S())
        	printf("\nValid expression!\n");
	else
		printf("\nNot a valid expression!\n");
}

int S()
{
	if(ip[i] == 'c' && ip[i+1] == 'd')
	{
		printf("S-->cd\n");
		i += 2;
		return 1;
	}
	else if(ip[i] == 'c' || ip[i] == 'b')
        {
                if(B())
                {
                        printf("S-->B\n");
                        return 1;
                }
        }
	else if(ip[i] == 'a' || ip[i] == 'b')
	{
		if(A() && B())
		{
			printf("S-->AB\n");
			return 1;
		}
	}
	else
	{
		printf("invalid\n");
		return 0;
	}
}

int A()
{
	if(ip[i] == 'a')
	{
		printf("A-->a\n");
		i++;
		return 1;
	}
	else if(ip[i] == 'b')
	{
		printf("A-->b\n");
		i++;
		return 1;
	}
	else
	{
		printf("invalid\n");
		return 0;
	}
}

int B()
{
	if(ip[i] == 'b')
	{
		printf("B-->b\n");
		i++;
		return 1;
	}
	else if(ip[i] == 'c')
	{
		i++;
		if(A())
		{
			if(ip[i] == 'd')
			{
				printf("B-->cAd\n");
				i++;
				return 1;
			}
		}
	}
	else
	{
		printf("invalid\n");
		return 0;
	}
}
