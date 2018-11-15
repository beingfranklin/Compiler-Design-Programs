#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 
  
int count, n = 0; 
char firstres[10][100]; 
char followres[10][100]; 
int m = 0; 
char production[10][10]; 
char f[10], first[10]; 
int k; 
char ck; 
int e; 
  
int main() 
{ 
    int jm = 0; 
    int km = 0; 
    int i, choice; 
    char c, ch; 
    printf("Enter the number of production :");
    scanf("%d",&count); 
    for(int i = 0;i < count;i++){  
    printf("Enter Production %d :",i+1);
    scanf("%s",production[i]); }
    int index; 
    char done[count]; 
    int ptr = -1; 
    for(k = 0; k < count; k++) { 
        for(index = 0; index < 100; index++) { 
            firstres[k][index] = '!'; 
        } 
    } 
    int point1 = 0, point2, flag; 
      
    for(k = 0; k < count; k++) 
    { 
        c = production[k][0]; 
        point2 = 0; 
        flag = 0; 
        for(index = 0; index <= ptr; index++) 
            if(c == done[index]) 
                flag = 1; 
                  
        if (flag == 1) 
            continue; 
            
        findfirst(c, 0, 0); 
        ptr += 1; 
          
        done[ptr] = c; 
        printf("\n First(%c) = { ", c); 
        firstres[point1][point2++] = c; 
          
        for(i = 0 + jm; i < n; i++) { 
            int lark = 0, chk = 0; 
              
            for(lark = 0; lark < point2; lark++) { 
                  
                if (first[i] == firstres[point1][lark]) 
                { 
                    chk = 1; 
                    break; 
                } 
            } 
            if(chk == 0) 
            { 
                printf("%c ", first[i]); 
                firstres[point1][point2++] = first[i]; 
            } 
        } 
        printf("}"); 
        jm = n; 
        point1++; 
    } 
    printf("\n"); 
    printf("\n\n"); 
    char donee[count]; 
    ptr = -1; 
      
  
    for(k = 0; k < count; k++) { 
        for(index = 0; index < 100; index++) { 
            followres[k][index] = '!'; 
        } 
    } 
    point1 = 0; 
    int land = 0; 
    for(e = 0; e < count; e++) 
    { 
        ck = production[e][0]; 
        point2 = 0; 
        flag = 0; 
          
        for(index = 0; index <= ptr; index++) 
            if(ck == donee[index]) 
                flag = 1; 
                  
        if (flag == 1) 
            continue; 
        land += 1; 
          
      
        follow(ck); 
        ptr += 1; 
          
        
        donee[ptr] = ck; 
        printf(" Follow(%c) = { ", ck); 
        followres[point1][point2++] = ck; 
          
       
        for(i = 0 + km; i < m; i++) { 
            int lark = 0, chk = 0; 
            for(lark = 0; lark < point2; lark++)  
            { 
                if (f[i] == followres[point1][lark]) 
                { 
                    chk = 1; 
                    break; 
                } 
            } 
            if(chk == 0) 
            { 
                printf("%c ", f[i]); 
                followres[point1][point2++] = f[i]; 
            } 
        } 
        printf(" }\n"); 
        km = m; 
        point1++;  
    } 
} 
  
void follow(char c) 
{ 
    int i, j; 
      
    if(production[0][0] == c) { 
        f[m++] = '$'; 
    } 
    for(i = 0; i < 10; i++) 
    { 
        for(j = 2;j < 10; j++) 
        { 
            if(production[i][j] == c) 
            { 
                if(production[i][j+1] != '\0') 
                { 
     
                    followfirst(production[i][j+1], i, (j+2)); 
                } 
                  
                if(production[i][j+1]=='\0' && c!=production[i][0]) 
                { 
                   
                    follow(production[i][0]); 
                } 
            }  
        } 
    } 
} 
  
void findfirst(char c, int q1, int q2) 
{ 
    int j; 
      

    if(!(isupper(c))) { 
        first[n++] = c; 
    } 
    for(j = 0; j < count; j++) 
    { 
        if(production[j][0] == c) 
        { 
            if(production[j][2] == '#') 
            { 
                if(production[q1][q2] == '\0') 
                    first[n++] = '#'; 
                else if(production[q1][q2] != '\0' 
                          && (q1 != 0 || q2 != 0)) 
                { 
                
                    findfirst(production[q1][q2], q1, (q2+1)); 
                } 
                else
                    first[n++] = '#'; 
            } 
            else if(!isupper(production[j][2])) 
            { 
                first[n++] = production[j][2]; 
            } 
            else 
            { 
               
                findfirst(production[j][2], j, 3); 
            } 
        } 
    }  
} 
  
void followfirst(char c, int c1, int c2) 
{ 
    int k; 
      
   
    if(!(isupper(c))) 
        f[m++] = c; 
    else
    { 
        int i = 0, j = 1; 
        for(i = 0; i < count; i++) 
        { 
            if(firstres[i][0] == c) 
                break; 
        } 
          
        
        while(firstres[i][j] != '!') 
        { 
            if(firstres[i][j] != '#')  
            { 
                f[m++] = firstres[i][j]; 
            } 
            else
            { 
                if(production[c1][c2] == '\0') 
                { 
                    
                    follow(production[c1][0]); 
                } 
                else
                { 
                   
                    followfirst(production[c1][c2], c1, c2+1); 
                } 
            } 
            j++; 
        } 
    } 
} 
