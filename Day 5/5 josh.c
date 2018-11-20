#include<stdio.h> 
#include<ctype.h>
#include<string.h>

int n;
char production[10][10];
 
void first(char array[], char ch);
void follow(char array[], char ch);
void append(char array[], char ch);
 
int main()
{
      int i, choice;
      char option, ch, result[10];
      printf("\nEnter the number of productions: ");
      scanf(" %d", &n);
      for(i = 0; i < n; i++)
      {
            printf("\nEnter production[%d]: ", i + 1);
            scanf(" %s", production[i]);
      }
      do
      {
            printf("\n\nFIRST & FOLLOW COMPUTATION\n");
            printf("1. FIRST\n2. FOLLOW\n\nEnter your option: ");
            scanf("%d" , &choice);
            switch(choice)
            {
                  case 1: printf("\nEnter the value to find first: ");
                          scanf(" %c", &ch);
                          result[0] = '\0';
                          first(result, ch);
                          printf("\nFIRST[%c] = {", ch);
                          for(i = 0; result[i] != '\0' ; i++)
                          {
                              printf(" %c ", result[i]);
                          }
                          printf("}\n");
                          result[0] = '\0';
                          break;
                  case 2: printf("\nEnter the value to find follow: ");
                          scanf(" %c", &ch);
                          result[0] = '\0';
                          follow(result, ch);
                          printf("\nFOLLOW[%c] = {", ch);
                          for(i = 0; result[i] != '\0' ; i++)
                          {
                              printf(" %c ", result[i]);
                          }
                          printf("}\n");
                          result[0] = '\0';
                          break;
                  default: printf("\nWrong Option!");
                           break;
            }
            printf("\nPress [Y/y] to continue: ");
            scanf(" %c", &option);
      }while(option == 'y' || option == 'Y');
      return 0;
}
 
void follow(char *array, char ch)
{
      int i, j, k, l, flag;
      char temp[10];

      if(production[0][0] == ch)
      {
            append(array, '$');
      }
      for(i = 0; i < n; i++)
      {
            for(j = 2; j < strlen(production[i]) ; j++)
            {
                  if(production[i][j] == ch)
                  {
                        if(production[i][j + 1] != '\0')
                        {
                              l = j;
                              while((l+1) < strlen(production[i]))
                              {
                                    first(temp, production[i][l + 1]);
                                    flag = 0;
                                    for(k=0 ; temp[k] != '\0' ; k++)
                                          if(temp[k] != '#')
                                                append(array , temp[k]);
                                    for(k=0 ; temp[k] != '\0' ; k++)
                                    {
                                          if(temp[k] == '#')
                                          {
                                                flag = 1;
                                                break;
                                          }
                                    }
                                    if(flag == 0)
                                    {
                                          temp[0] = '\0';
                                          break;
                                    }
                                    l++;
                              }
                        }
                        if(production[i][j + 1] == '\0' && ch != production[i][0])
                        {     				
                              follow(array, production[i][0]);
                        }
                  }
            }
      }
}

void first(char* array, char ch)
{
      int i, j, k;
      char temp[20];
      int flag;

      temp[0] = '\0';
      array[0] = '\0';

      if(!(isupper(ch)))
      {
            append(array, ch);
            return ;
      }
      for(i = 0; i < n; i++)
      {
            if(production[i][0] == ch)
            {
                  if(production[i][2] == '#') 
                  {
                        append(array, '#');
                  }
                  else
                  {
                        j = 2;
                        while(production[i][j] != '\0')
                        {
                              flag = 0;
                              first(temp, production[i][j]);
                              for(k = 0; temp[k] != '\0'; k++)
                              {
                                    append(array,temp[k]);
                              }
                              for(k = 0; temp[k] != '\0'; k++)
                              {
                                    if(temp[k] == '#')
                                    {
                                          flag = 1;
                                          break;
                                    }
                              }
                              if(!flag)
                              {
                                    break;
                              }
                              j++;
                        }
                  }     
            }
      }
      return;
}
 
void append(char array[], char value)
{
      int i;
      for(i = 0; array[i] != '\0'; i++)
      {
            if(array[i] == value)
            {
                  return;
            }
      }
      array[i] = value;
      array[i + 1] = '\0';
}
