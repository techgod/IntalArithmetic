// Yash Pradhan
// PES1201700262
// Section 6G
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

#define MAX_LEN 1001

//Some helper functions
static void strrev(char *str,int len)
{
    if (!str || ! *str)
    {
        return;
    }

    int i = len - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        --i;
        ++j;
    }
}

//Start of Implementations 
char* intal_add(const char* intal1, const char* intal2)
{
    char* intal_r = malloc(sizeof(char)*MAX_LEN);

    int i = strlen(intal1)-1;
    int j = strlen(intal2)-1;    
    int carry = 0;

    int len=0;

    while(i>=0 && j>=0)
    {
        int sum = (intal1[i]-'0')+(intal2[j]-'0')+carry;
        intal_r[len]=(sum%10)+'0';
        carry = sum/10;
        --i;
        --j;
        ++len;
    }

    while(i>=0)
    {
        int sum = ((intal1[i]-'0')+carry); 
        intal_r[len]=(sum%10)+'0';
        carry = sum/10; 
        --i;
        ++len;
    }

    while(j>=0)
    {
        int sum = ((intal2[j]-'0')+carry); 
        intal_r[len]=(sum%10)+'0';
        carry = sum/10; 
        --j;
        ++len;
    }

    if(carry)
    {
        //strappend(intal_r,carry+'0');
        intal_r[len]=carry+'0';
        ++len;
    }

    strrev(intal_r,len);
    intal_r[len]='\0';

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

    char* intal_r = malloc(sizeof(char)*MAX_LEN);    

    if(res==0)
    {
        intal_r[0]='0';
        intal_r[1]='\0';
        return intal_r;
    }

    char *big = (char*) malloc(sizeof(char)*MAX_LEN);
    char *small = (char*) malloc(sizeof(char)*MAX_LEN);

    int bsize;
    int ssize;

    if(res>0)
    {
        bsize = strlen(intal1);
        ssize = strlen(intal2);
        strcpy(big,intal1);
        strcpy(small,intal2);
    }
    else
    {
        bsize = strlen(intal2);
        ssize = strlen(intal1);
        strcpy(big,intal2);
        strcpy(small,intal1);
    }

    strrev(big,bsize);
    strrev(small,ssize);

    int len = 0;
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
        intal_r[len]=sub+'0';
        ++len; 
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
  
        intal_r[len]=sub+'0';
        ++len;
    }

    // there are some zeros which can be at the end (will go to beginning when reversed)
    int nlen;
    for(nlen=len;nlen>0;--nlen)
    {
        //nlen - 1 is last position
        if(intal_r[nlen-1]!='0')
        {
            break;
        }
    }

    intal_r[nlen]='\0';
    //nlen is the length without the zeros
    strrev(intal_r,nlen);
     
    free(big);
    free(small);

    return intal_r;
    
}

char* intal_multiply(const char* intal1, const char* intal2)
{

        char* intal_r = malloc(sizeof(char)*MAX_LEN);    

        //start with last digit of second element
        int len1 = strlen(intal1);
        int len2 = strlen(intal2);

        if(intal1[0] == '0' || intal2[0] == '0')
        {
            intal_r[0]='0';
            intal_r[1]='\0';
            return intal_r;
        }

        int result[len1+len2];
        memset(result,0,sizeof(result));

        int ind1=0 ,ind2 = 0, r_lpos=0;

        for(int i=len1-1;i>=0;--i)
        {
            //going through each digit of intal2 from right to left
            int carry = 0;
            int n1 = intal1[i]-'0';

            ind2=0;

            for(int j=len2-1;j>=0;--j)
            {
                //go left to right in intal1
                int n2 = intal2[j]-'0';
                int sum = n1*n2 + result[ind1+ind2] + carry;

                carry = sum/10;

                if((ind1+ind2)>r_lpos)
                {
                    r_lpos = ind1+ind2;
                }
                result[ind1 + ind2] = sum % 10;

                ++ind2;
            }

            if(carry>0)
            {
                if((ind1+ind2)>r_lpos)
                {
                    r_lpos = ind1+ind2;
                }
                result[ind1+ind2] += carry;
            }

            ++ind1; 
        }


        while(r_lpos>=0)
        {
            if(result[r_lpos]!='0')
            {
                break;
            }
            --r_lpos;
        }

        intal_r[r_lpos+1]='\0';

        for(int i=0;i<=r_lpos;++i)
        {
            intal_r[i]=result[r_lpos-i]+'0';
        }       

        return intal_r;
        
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
    char* a = malloc(sizeof(char)*MAX_LEN);    
    char* b = malloc(sizeof(char)*MAX_LEN);    
    char* c = malloc(sizeof(char)*MAX_LEN);    

    strcpy(a,"0");
    strcpy(b,"1");

    unsigned int i; 

    if(n == 0) 
    {
        free(b);
        free(c);
        return a; 
    }

    for (i = 2; i <= n; i++) 
    { 
        char *res = intal_add(a,b); 
        strcpy(c,res);
        free(res);

        strcpy(a,b); 
        strcpy(b,c); 
    } 

    free(a);
    free(c);
    return b; 
}

char* intal_factorial(unsigned int n)
{
    char* pro = malloc(sizeof(char)*MAX_LEN);    

    strcpy(pro,"1");

    if(n==0 || n==1)
    {
        return pro;
    }

    for(unsigned int i=2;i<=n;++i)
    {
        char result[MAX_LEN];
        sprintf(result, "%d", i); 

        char *res = intal_multiply(pro,result);

        strcpy(pro,res);
        free(res);
    }

    return pro;
}


char* intal_bincoeff(unsigned int n, unsigned int k)
{
    k = n-k<k?n-k:k;

    char* c[k+1]; 
    
    for(int i=1;i<=k;++i)
    {
        c[i]=malloc(sizeof(char)*MAX_LEN);
        strcpy(c[i],"0");
    }
    //memset(C, "0", sizeof(C)); 
  
    c[0]=malloc(sizeof(char)*MAX_LEN);
    strcpy(c[0],"1"); // nC0 is 1 
  
    for (int i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (int j = i<k?i:k; j > 0; --j)
        {
            c[j] = intal_add(c[j],c[j-1]); 
        } 
    } 

    for(int i=0;i<k;++i)
    {
        free(c[i]);
    }

    return c[k]; 
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

