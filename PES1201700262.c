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

// Adding two intals
char* intal_add(const char* intal1, const char* intal2)
{
    char* intal_r = malloc(sizeof(char)*MAX_LEN);

    int i = strlen(intal1)-1;
    int j = strlen(intal2)-1;    
    int carry = 0;

    int len=0;

    // Summing the corresponding digits in both the intals
    while(i>=0 && j>=0)
    {
        int sum = (intal1[i]-'0')+(intal2[j]-'0')+carry;
        intal_r[len]=(sum%10)+'0';
        carry = sum/10;
        --i;
        --j;
        ++len;
    }

    // Sum the remaining digits in the longer intal
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
        intal_r[len]=carry+'0';
        ++len;
    }

    // Final answer is in reverse (since we had calculated the least significant digit first)
    strrev(intal_r,len);
    intal_r[len]='\0';

    return intal_r;
}


int intal_compare(const char* intal1, const char* intal2)
{
    //lengths of the intals
    int n1 = strlen(intal1);
    int n2 = strlen(intal2);

    //comapring based on just the length
    if(n1>n2)
    {
        return 1;
    }
    if(n2>n1)
    {
        return -1;
    }

    //if lengths are same, compare the characters
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
            int carry = 0;
            int n1 = intal1[i]-'0';

            ind2=0;

            for(int j=len2-1;j>=0;--j)
            {
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

        //remove possible leading zeros
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
    char* intal_t = malloc(sizeof(char)*MAX_LEN);

   int n1 = strlen(intal1);
   int n2 = strlen(intal2);

   if(intal_compare(intal1,intal2)<0)
   {
       strcpy(intal_t,intal1);
       return intal_t;
   }
    
    strncpy(intal_t,intal1,n2);
    intal_t[n2] = '\0';
    int pos = n2;

    if(!(intal_compare(intal_t,intal2)>0))
    {
        intal_t[pos]=intal1[pos];
        ++pos;
        intal_t[pos]='\0';
    }

    while(intal_compare(intal_t,intal2)>=0)
    {
        while(intal_compare(intal_t,intal2)>=0)
        {
            char* res = intal_diff(intal_t,intal2);
            strcpy(intal_t,res);
            free(res);
        }
        if(strlen(intal_t)==1 && intal_t[0]=='0')
        {
            intal_t[0]='\0';
        }
        while(pos<n1 && intal_compare(intal_t,intal2)<0)
        {
            int t_len = strlen(intal_t);
            intal_t[t_len]=intal1[pos];
            intal_t[t_len+1]='\0';
            ++pos;
        }

    }

    if(intal_compare(intal_t,intal2)==0||strlen(intal_t)==0)
    {
        strcpy(intal_t,"0");
    }

    return intal_t;
}

char* intal_pow(const char* intal1, unsigned int n)
{
    char* ans;

    if(intal_compare(intal1,"0")==0) //0
    {
        ans = malloc(sizeof(char)*MAX_LEN);
        strcpy(ans,"0");
        return ans;
    }

    if(n==0)
    {
        ans = malloc(sizeof(char)*MAX_LEN);
        strcpy(ans,"1");
        return ans;
    }
    char* temp = intal_pow(intal1,n/2);

    if ((n%2)==0)
    {
        ans = intal_multiply(temp,temp);
    }
    else
    {
        char *m1 = intal_multiply(temp,temp);
        ans = intal_multiply(m1,intal1);
        free(m1);
    }

    free(temp);
    return ans;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
    if(intal_compare(intal1,"0")==0)
    {
        char* ans = malloc(sizeof(char)*MAX_LEN);
        strcpy(ans,intal2);
        return ans;
    } 
    
    char *mod_res = intal_mod(intal2,intal1);
    char *res = intal_gcd(mod_res, intal1);

    free(mod_res);
    return res; 
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
  
    c[0]=malloc(sizeof(char)*MAX_LEN);
    strcpy(c[0],"1");
  
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = i<k?i:k; j > 0; --j)
        {
            char* res = intal_add(c[j],c[j-1]); 
            strcpy(c[j],res);
            free(res);
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
    int pos = 0;
    char *max_ele = malloc(sizeof(char)*MAX_LEN);

    strcpy(max_ele,*(arr));

    for(int i=1;i<n;++i)
    {
        if(intal_compare(*(arr+i),max_ele)>0)
        {
            strcpy(max_ele,*(arr+i));
            pos = i;
        }
    }

    free(max_ele);
    return pos;
}


int intal_min(char **arr, int n)
{
    int pos = 0;
    char *min_ele = malloc(sizeof(char)*MAX_LEN);

    strcpy(min_ele,*(arr));

    for(int i=0;i<n;++i)
    {
        if(intal_compare(*(arr+i),min_ele)<0)
        {
            strcpy(min_ele,*(arr+i));
            pos = i;
        }
    }

    free(min_ele);
    return pos;
}


int intal_search(char **arr, int n, const char* key)
{
    int pos = -1;
    
    for(int i=0;i<n;++i)
    {
        if(intal_compare(*(arr+i),key)==0)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

int intal_binsearch(char **arr, int n, const char* key)
{
    int l = 0, u=n-1;
    while(l<=u)
    {
        int m = (l+u)/2;
        int res = intal_compare(*(arr+m),key);
        if(res==0)
        {
            return m;
        }
        if(res>0)
        {
            u = m-1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

static void swap(char** a, char** b) 
{ 
    char *t = *a; 
    *a = *b; 
    *b = t; 
} 
  
static int partition(char **arr, int low, int high) 
{ 
    char* pivot = *(arr+high);
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if(intal_compare(*(arr+j),pivot)<0) 
        { 
            ++i;
            swap(arr+i, arr+j); 
        } 
    } 
    swap(arr+i + 1, arr+high); 
    return (i + 1); 
} 
  
static void quickSort(char **arr, int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void intal_sort(char **arr, int n)
{
    quickSort(arr,0,n-1);
}

char* coin_row_problem(char **arr, int n)
{
    char *g = malloc(sizeof(char)*MAX_LEN);
    char *f = malloc(sizeof(char)*MAX_LEN);
    char *temp = malloc(sizeof(char)*MAX_LEN);

    strcpy(g,"0");
    strcpy(f,*arr);

    for(int pos = 2; pos <= n; ++pos)
    {
        char *add_res = intal_add(*(arr+pos-1),g);

        int comp = intal_compare(add_res,f);
        
        if(comp>0)
        {
            strcpy(temp,add_res);
        }
        else
        {
            strcpy(temp,f);
        }

        strcpy(g,f);
        strcpy(f,temp);

        free(add_res);
    }

    free(temp);
    free(g);
    return f;
}

