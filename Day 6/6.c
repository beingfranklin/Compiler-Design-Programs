#include<stdio.h>
#include<ctype.h>
#include<string.h>

char x , a , ret , stack[20] , ip[20] , cell[4];
int i , j , ptr=0 ,top=-1 , max=20, flag=0;
char table[6][7][4] = {
			"NT", "i",  "+",    "*",    "(",   ")",  "$",
			"E",  "TX", "-",    "-",    "TX", "-",  "-",
			"X", "-",   "+TX", "-",    "-",   "\0", "\0",
			"T",  "FY", "-",    "-",    "FY", "-",  "-",
			"Y", "-",   "\0",   "*FY", "-",   "\0", "\0",
			"F",  "i",  "-",    "-",    "(E)", "-",  "-",
			};

void push(char c)
{
	top += 1;
	stack[top] = c;
}

char pop()
{
	ret = stack[top];
	top -= 1;
	return ret;
}

void main()
{
	printf("Enter the string: ");
	scanf("%s" , ip);

	printf("\nThe table is: \n");
	for(i=0 ; i<6 ; i++)
	{
		for(j=0 ; j<7 ; j++)
			printf("%s\t" , table[i][j]);
		printf("\n");
	}

	push('$');
	push('E');
	while(top != -1)
	{
		printf("\n\nSTACK: \n");
		for(i=top ; i>=0 ; i--)
			printf("%c\n" , stack[i]);

		x = pop();
		a = ip[ptr];

		if(!isupper(x))
			if(x == a)
				ptr += 1;
			else
			{
				flag = 1;
				break;
			}
		else
		{
			for(i=1 ; i<6 ; i++)
				if(x == table[i][0][0])
					break;

			if(isalpha(a) && islower(a))
				j=1;
			else
			{
				for(j=2 ; j<7 ; j++)
					if(a == table[0][j][0])
						break;
			}

			strcpy(cell , table[i][j]);

			if(cell[0] == '-')
			{
				flag = 1;
				break;
			}
			else if(strcmp(cell , "\0"))
			{
				if(cell[0] == 'i')
					push(a);
				else
					for(i=strlen(cell)-1 ; i>=0 ; i--)
						push(cell[i]);
			}

		}
	}

	if((ip[ptr] == '\0') && (flag == 0))
		printf("Valid input!\n");
	else
		printf("Invalid input!\n");
}
