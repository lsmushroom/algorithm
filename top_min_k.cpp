#include <stdio.h>
#include <stdlib.h>

#define P(x) (((x) - 1) >> 1)
#define L(x) (((x) << 1)  + 1)
#define R(x) (((x) << 1)  + 2)

void heapy(int* res , const int len , int m)
{
    if(!res)
        return ;

    int larger = m;
    int tmp = 0;

    if(L(m) < len && res[larger] < res[L(m)])
        larger = L(m);
    
    if(R(m) < len && res[larger] < res[R(m)])
        larger = R(m);

    if(larger != m)
    {
        tmp = res[larger];
        res[larger] = res[m];
        res[m] = tmp;

        heapy(res , len , larger);
    }
}

int* foo(int* arr, const int len, const int k)
{
    if(!arr)
        return NULL;
    
    int* res = NULL;
    int size = 0;
    int i;
   
    res = (int*)malloc(sizeof(int) * k);
    if(!res)
        return NULL;

    for(i = 0; i < len; i++)
    {
#if 0
        if(size < k)
        {
            res[size++] = res[0];
            res[0] = arr[i];
        }
        else if(arr[i] < res[0])
        {
            res[0] = res[size - 1];
            res[size - 1] = arr[i];
        }

        heapy(res , size , 0);
#else
        if(size < k)
        {
        }
        else if(arr[i] < res[0])
        {
            res[0] = res[size - 1];
            res[size - 1] = arr[i];
            heapy(res , size , 0);
        }
#endif
    }

    return res;
}

int main(int argc , char** argv)
{
    int arr[] = {2,3,15,23,19,-1,1,0,-2};
    int len = sizeof(arr)/sizeof(int);
    const int k = 4;
    int i;

    int* res = foo(arr , len , k);
    if(!res)
        return 0;

    printf("aaaa\n");
    for(i = 0; i < k; i++)
    {
        printf("%d " , res[i]);
    }
    printf("\n");

    return 0;
}
