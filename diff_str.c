#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//给出两个有序的数组A,B，返回在B中存在而在A中不存在的数
int foo(const int* a, const int alen, const int* b, const int blen , int* diff)
{
    if(!a || !b)
        return 0;

    int i = 0, j = 0, k = 0;
    
    while(i < alen && j < blen)
    {
        if(a[i] == b[j])
        {
            i++;
            j++;
        }
        else if(a[i] > b[j])
        {
            diff[k++] = b[j++];
        }
        else
        {
            i++;
        }
    }

    for(; j < blen ; j++ , k++)
    {
        diff[k] = b[j];
    }

    return k;
}

int main(int argc , char** argv)
{
    int a[] = {2,4,6,14,19,23,33,41};
    int b[] = {0,1,2,3,5,6,8,9,14,16,17,18,19,23,25,28,33,40,41,55,100,123,234};
    int alen = sizeof(a) /sizeof(int);
    int blen = sizeof(b) /sizeof(int);
    int* diff = NULL;
    int i = 0 , k = 0;

    diff = (int*)malloc(sizeof(int) * blen); 
    memset(diff , 0 , sizeof(int) * blen);

    k = foo(a, alen, b , blen , diff);
    
    for(i = 0 ; i < alen; i++)
    {
        printf("%d " , a[i]);
    }
    printf("\n");
    for(i = 0 ; i < blen; i++)
    {
        printf("%d " , b[i]);
    }
    printf("\n");
    for(i = 0 ; i < k; i++)
    {
        printf("%d " , diff[i]);
    }
    printf("\n");

    return 0;
}
