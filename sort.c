#include <stdio.h>

#define swap(a , b) \
    do{ typeof(a) tmp = (a) ; (a) = (b) ; (b) = tmp; }while(0)

int partition(int* arr , int start , int end)
{
    if(!arr)
        return 0;

    int i = start - 1;
    int pivot = arr[end];
    int j;

    for(j = start; j <= end - 1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i] , arr[j]);
        }
    }

    swap(arr[i + 1] , arr[end]);
    return i + 1;
}

void quicksort(int* arr , int start , int end)
{
    if(!arr || start >= end)
        return ;

    int q = 0;

    q = partition(arr , start , end);
    quicksort(arr , start , q - 1);
    quicksort(arr , q + 1, end);
}

void bubble_sort(int* arr , int len)
{
    if(!arr)
        return ;

    int i , j;

    for(i = len; i > 0; i--)
    {
        for(j = 0; j < i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
                swap(arr[j] , arr[j + 1]);
        }
    }
}

void foo(int* arr , int len)
{
    if(!arr)
        return;

    //quicksort(arr , 0, len - 1);
    bubble_sort(arr , len);

    return;
}

int binary_search(int* arr , int len , int val)
{
    if(!arr)
        return -1;

    int i = len >> 1;

    if(val < arr[i])
}

int main(int argc , char** argv)
{
    int arr[] = {10,2,5,11,23,4,15,19};
    int len = sizeof(arr)/sizeof(int);
    int i;

    for(i = 0; i < len; i++)
    {
        printf("%d " , arr[i]);
    }
    printf("\n");

    foo(arr , len);
    
    for(i = 0; i < len; i++)
    {
        printf("%d " , arr[i]);
    }
    printf("\n");

    i = binary_search(arr , len , 23);
    printf("23 pos : %d\n" ,i);

    return 0;
}
