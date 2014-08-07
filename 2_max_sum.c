#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(int* arr , int len)
{
    if(!arr)
        return 0;

    int max = 0;
    int curr;
    int last;
    int i ;

    last = curr = max = arr[0]; 
    for(i = 1; i < len; i++ , last = curr)
    {
        if(last > 0) {
            curr = last + arr[i];
        } else {
            curr = arr[i];
        }

        if(max < curr)
            max = curr;
//        max = curr > max ? curr : max;
    }

    return max;
}

int main(int argc , char** argv)
{
    int max = 0;
//    int arr[] = {1, -2, 3, 10, -4, -7, 2, -5};
//    int arr[] = {-1, -2, -3, -10, -4, -7, -2, -5};
    int arr[] = {0 , 1, -2, -3, -10, -4, -7, -2, -5};
    int len = sizeof(arr)/sizeof(int);

    max = foo(arr , len);
    printf("max = %d\n"  , max);

    return 0;
}
