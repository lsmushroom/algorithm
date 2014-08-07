#include <stdio.h>
#include <stdlib.h>

void foo(int* arr , int len , const int val)
{
    if(!arr)
        return;

    int i , j;
    int half = val >> 1;
   
    for(i = 0; i < len; i++)
    {
        if(arr[i] <= half && arr[i + 1] >= half)
        {
            j = i + 1;
            break;
        }
    }

    if(i == len)
        return ;

    while(i >= 0 && j < len)
    {
        if(arr[i] + arr[j] < val) {
            j++;
        }else if(arr[i] + arr[j] > val) {
            i--;
        } else {
            printf("%d + %d = %d\n" , arr[i] , arr[j] , val);
            break;
        }
    }

    return ;
}

int main(int argc , char** argv)
{
    if(argc < 2)
        return -1;
    
    int val = atoi(argv[1]);

    int arr[] = {1, 2, 4, 6, 7, 9, 14, 15, 27, 39, 43};
    int len = sizeof(arr)/sizeof(int);

    foo(arr , len , val);

    return 0;
}
