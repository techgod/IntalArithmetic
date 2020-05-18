// Yash Pradhan
// PES1201700262
// Section 6G
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

#define MAX_LEN 1001

//Some helper functions
static char* strrev(char *str)
{
    if (!str || ! *str)
    {
        return str;
    }

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        --i;
        ++j;
    }
    return str;
}

static void strappend(char *input, char c)
{
    int n = strlen(input);
    input = (char*) realloc(input,(strlen(input) + 2));
    input[n]=c;
    input[n+1]='\0';
}

static void remove_leading_zeros(char *dest,char *source)
{
    while(*(source)=='0')++source;
    strcpy(dest,source);
}

//Start of Implementations 

char* intal_add(const char* intal1, const char* intal2)
{
    char* intal_r = malloc(sizeof(char)*2);
    int i = strlen(intal1)-1;
    int j = strlen(intal2)-1;    
    int carry = 0;

    while(i>=0 && j>=0)
    {
        int sum = (intal1[i]-'0')+(intal2[j]-'0')+carry;
        strappend(intal_r,(sum%10)+'0');
        carry = sum/10;
        --i;
        --j;
    }

    while(i>=0)
    {
        int sum = ((intal1[i]-'0')+carry); 
        strappend(intal_r,(sum%10)+'0');
        carry = sum/10; 
        --i;
    }

    while(j>=0)
    {
        int sum = ((intal2[j]-'0')+carry); 
        strappend(intal_r,(sum%10)+'0');
        carry = sum/10; 
        --j;
    }

    if(carry)
    {
        strappend(intal_r,carry+'0');
    }

    intal_r = strrev(intal_r);

    return intal_r;
}


int intal_compare(const char* intal1, const char* intal2)
{
    int n1 = strlen(intal1);
    int n2 = strlen(intal2);

    //based on just the length
    if(n1>n2)
    {
        return 1;
    }
    if(n2>n1)
    {
        return -1;
    }

    //n1 basically same as n2
    for(int i=0;i<n1;++i)
    {
        if(intal1[i]>intal2[i])
        {
            return 1;
        }
        else if(intal2[i]>intal1[i])
        {
            return -1;
        }
    }
    return 0;
}
char* intal_diff(const char* intal1, const char* intal2)
{
    //use above strcmp
    int res = intal_compare(intal1,intal2);

    char* intal_r = malloc(sizeof(char)*2);    
    if(res==0)
    {
        intal_r[0]='0';
        intal_r[1]='\0';
        return intal_r;
    }

    char *big,*small;
    int bsize;
    int ssize;


    if(res>0)
    {
        bsize = strlen(intal1);
        ssize = strlen(intal2);
        big = (char*) malloc(sizeof(char)*(strlen(intal1)+1));
        small = (char*) malloc(sizeof(char)*(strlen(intal2)+1));
        strcpy(big,intal1);
        strcpy(small,intal2);
    }
    else
    {
        bsize = strlen(intal2);
        ssize = strlen(intal1);
        big = (char*) malloc(sizeof(char)*bsize);
        small = (char*) malloc(sizeof(char)*ssize);
        strcpy(big,intal2);
        strcpy(small,intal1);
    }

    intal_r = (char*) realloc(intal_r,sizeof(char)*bsize);

    strrev(big);
    strrev(small);

    int carry = 0;

    for (int i=0; i<ssize; ++i) 
    { 
       
        int sub = ((big[i]-'0')-(small[i]-'0')-carry); 
          
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
        {
            carry = 0; 
        }
        strappend(intal_r,sub+'0'); 
    } 

    for (int i=ssize; i<bsize; ++i) 
    { 
       
        int sub = ((big[i]-'0')-carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
        {
            carry = 0; 
        }
  
        strappend(intal_r,sub+'0'); 
    }

    strrev(intal_r); 

    char *intal_final = (char*) malloc(sizeof(char)*(strlen(intal_r)+1));

    remove_leading_zeros(intal_final,intal_r);

    free(intal_r);
    free(big);
    free(small);

    return intal_final;
}
char* intal_multiply(const char* intal1, const char* intal2)
{
        return "a";

}
char* intal_mod(const char* intal1, const char* intal2)
{
        return "a";

}
char* intal_pow(const char* intal1, unsigned int n)
{
        return "a";

}
char* intal_gcd(const char* intal1, const char* intal2)
{
        return "a";

}
char* intal_fibonacci(unsigned int n)
{
    return "a";
}
char* intal_factorial(unsigned int n)
{
    return "a";
}
char* intal_bincoeff(unsigned int n, unsigned int k)
{
    return "a";
}
int intal_max(char **arr, int n)
{
    return 0;
}
int intal_min(char **arr, int n)
{
    return 0;
}
int intal_search(char **arr, int n, const char* key)
{
    return 0;
}
int intal_binsearch(char **arr, int n, const char* key)
{
    return 0;
}
void intal_sort(char **arr, int n)
{
}
char* coin_row_problem(char **arr, int n)
{
    return "a";
}

