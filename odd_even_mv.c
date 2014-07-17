#include <stdio.h>

/* 输入一个整数数组，调整数组中数字的顺序，使得所有奇数位于数组的前
 * 半部分，所有偶数位于数组的后半部分。要求时间复杂度为O(n)
 * */
void foo(int* arr , int len)
{
    if(!arr)
        return ;

    int i , j = len - 1;
    int tmp = 0;

    for(i = j; i >= 0; i--)
    {
        if ( ! (arr[j]&1) ) {
            j--;
        } else if( !(arr[i] & 1) ) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            j--;
        }
    }

    return ;
}

int main(int argc , char** argv)
{
    int arr[] = { 4,12,1,3,53,25,9,2 };
    int i;

    printf("%d \n" , sizeof(arr)/sizeof(int));
    for(i = 0; i < sizeof(arr)/sizeof(int); i++)
        printf("[%d] " , arr[i]);
    printf("\n");

    foo(arr , sizeof(arr)/sizeof(int));

    for(i = 0; i < sizeof(arr)/sizeof(int); i++)
        printf("[%d] " , arr[i]);
    printf("\n");

    return 0;
}
