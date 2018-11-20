#include<stdio.h>
#include<ctype.h>

char ip[20], quad[10][4], id[10], op[10], oper, id1, id2;
int i, j, topi=-1 , topo=-1, row=0, res=90;

void push(char *st, int *top, char ch)
{
    st[++(*top)] = ch;
}

char pop(char *st, int *top)
{
    return st[(*top)--];
}

int priority(char ch)
{
    if((ch == '-') || (ch == '+'))
        return 1;
    else if((ch == '*') || (ch == '/'))
        return 2;
    else if(ch == '^')
        return 3;
    return 0;
}

void main()
{
    printf("\nEnter the expression: ");
    scanf(" %s" , ip);

    for(i=2 ; ip[i] != ';' ; i++)
    {
        if(ip[i] == '(')
            push(op , &topo , ip[i]);

        else if(ip[i] == ')')
        {
            while((topo != -1) && (op[topo] != '('))
            {
                oper = pop(op, &topo);
				id1 = pop(id, &topi);
				id2 = pop(id, &topi);

				quad[row][0] = oper;
				quad[row][1] = id2;
				quad[row][2] = id1;
				quad[row][3] = (char)res;
				row += 1;

				push(id, &topi, (char)res);
				res -= 1;
            }
            pop(op, &topo);
        }

        else if(isalpha(ip[i]))
        {
            push(id, &topi, ip[i]);
        }

        else
        {
            while((topo != -1) && (priority(op[topo]) >= priority(ip[i])))
            {
                oper = pop(op, &topo);
				id1 = pop(id, &topi);
				id2 = pop(id, &topi);

				quad[row][0] = oper;
				quad[row][1] = id2;
				quad[row][2] = id1;
				quad[row][3] = (char)res;
				row += 1;

				push(id, &topi, (char)res);
				res -= 1;
            }
            push(op, &topo, ip[i]);
        }
    }

    while(topo != -1)
    {
        oper = pop(op, &topo);
		id1 = pop(id, &topi);
		id2 = pop(id, &topi);

		quad[row][0] = oper;
		quad[row][1] = id2;
		quad[row][2] = id1;
		quad[row][3] = (char)res;
		row += 1;

		push(id, &topi, (char)res);
		res -= 1;
    }

	quad[row][0] = '=';
	quad[row][1] = ip[0];
	quad[row][2] = (char)(res+1);

    printf("\nQUADRUPLE TABLE: \n\nOPER\tARG1\tARG2\tRES\n");
    for(i=0 ; i<=row; i++)
	{
        for(j=0 ; j<4 ; j++)
			printf("%c\t" , quad[i][j]);
		printf("\n");
	}
	printf("\nTHREE ADDRESS CODE: \n");
	for(i=0 ; i<=row; i++)
	{
		if(i != row)
        	printf("%c = %c %c %c;\n" , quad[i][3] , quad[i][1] , quad[i][0] , quad[i][2]);
		else
			printf("%c = %c;\n" , quad[i][1] , quad[i][2]);
	}
}