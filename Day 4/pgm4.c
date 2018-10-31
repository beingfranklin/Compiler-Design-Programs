#include<stdio.h>
#include<string.h>
int i=0,p[10],k=0;
char in[100];
int A()
{
    if(in[i]=='a')
    {
        i++;
		p[k]=4;
		k++;
        return 1;
    }
    else if(in[i]=='b')
    {
        i++;
		p[k]=5;
		k++;
        return 1;
    }
    else if(in[i]=='c')
    {
        i++;
		p[k]=6;
		k++;
        return 1;
    }
    else
	  return 0;
}
int B()
{
    int op=2,r1;
    if(in[i]=='b')
    {
        i++;
        op=1;
		p[k]=7;
		k++;
        return 1;
    }
    if(op==2)
    {
        if(in[i]=='c')
        {
            i++;
			p[k]=8;
			k++;
            r1=A();
            if(r1==1)
            {
                if(in[i]=='d')
                {
					i++;
                    return 1;
                }
            }
            else
			{
				i--;
				k=0;
                return 0;
			}
        }
        else
            return 0;
    }
}
int S()
{
    int op=2,r1,r2;
    if(in[i]=='c')
    {
        i++;
        if(in[i]=='d')
        {
		   if((i+1)==strlen(in))
			{
				op=1;
				p[0]=1;
				k=1;
				i++;
				return 1;
			}
			else
			{
				i=0;
			}
		}
        else
        {
            i=0;
        }
    }
    if(op==2)
    {
        p[k]=2;
		k++;
		r1=A();
        if(r1==1)
        {
            r2=B();
            if(r2==1)
			{
				if(i==strlen(in))
				{
					return 1;
				}
				else
				{
					op=3;
					k=0;
					i=0;
				}
			}
            else 
            {
                op=3;
				k=0;
                i=0;
            }
        }
        else
        {
            op=3;
			k=0;
        }
    }
    if(op==3)
    {
		p[k++]=3;
		r1=B();
        if(r1==1)
        {
            return 1;    
        }
        else
		{
			k--;
            return 0;
		}
    }
}        
void main()
{
    int r1,j;
    printf("\nEnter Input String : ");
    scanf("%s",in);
    r1=S();
    if((r1==1)&&(i==strlen(in)))
    {
        printf("\nAccepted\n\nProductions\n",k);			
		for(j=0;j<k;j++)
		{
			if(p[j]==1)
				printf("\n%d. S->cd",j);
			else if(p[j]==2)
				printf("\n%d. S->AB",j);
			else if(p[j]==3)
				printf("\n%d. S->B",j);
			else if(p[j]==4)
				printf("\n%d. A->a",j);
			else if(p[j]==5)
				printf("\n%d. A->b",j);
			else if(p[j]==6)
				printf("\n%d. A->c",j);
			else if(p[j]==7)
				printf("\n%d. B->b",j);
			else if(p[j]==8)
				printf("\n%d. B->cAd\n",j);
		}
		
    }
    else
    {
        printf("\nNot Accepted\n");
    }
}