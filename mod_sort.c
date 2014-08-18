#include <stdio.h>

#define swap(a, b) \
        do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

//一串数字，对每个数字模3，按模为0,1,2的顺序排序
int main()
{
    int num[] = {2,0,2,1,0,1,2,1,1,0,0,2,0};
    int n = sizeof(num)/sizeof(int);
    int i;

    for(i = 0;i < n;i ++)printf("%d ",num[i]%3);puts("");
    int c1,c2,c0;
    //c0 为从左起最后一个余数为0后一个元素的位置
    //c2 为从右起第一个余数为2前一个元素的位置
    //c1 用于中间元素扫描
    c0 = 0,c2 = n - 1;
    //确定c0,c2的位置
    while(c0 < n && num[c0]%3 == 0)
        c0++;
    while(c2 >= 0 && num[c2]%3 == 2)
        c2--;
    //c1为c0的下一个位置
    c1 = c0 + 1;
    while(c0 < c2 && c1 < c2)
    {
        if(num[c1]%3 == 0)
        {
            swap(num[c0],num[c1]);
            c0++;
        }
        if(num[c1]%3 == 2)
        {
            swap(num[c2],num[c1]);
            c2--;
        }
        if(num[c1]%3 == 1)
            c1++;
    }

    for(i = 0;i < n;i ++)
        printf("%d ",num[i]%3);

    return 0;   
}

/*
void* foo(int* arr , int len)
{
    if(!arr)
        return NULL;

    int i = 0 , j = 1, k = len - 1;
    int val = 0;

    while(i < k)
    {
        if(arr[i]%3 != 2)
        {
            i++
        }
        if(arr[k]%3 != 0)
        {
            k--;
        }

        if(arr[i]%3 == 2 && arr[k]%3 == 0)
        {
            swap(arr[i] , arr[k]);
        }
    }


    while(j < k)
    {
        if(arr[j]%3 != 1)
        {
            j++;
        }

        if(arr[j]%3 == 1 && arr[k]%3 == 0)
        {
            swap(arr[i] , arr[k]);
        }
    }


    return ;
}

int main(int argc , char** argv)
{
    if(argc < 2)
        return -1;
    
    printf("str: %s\n" , argv[1]);
    printf("str: %s\n" , foo(argv[1]));

    return 0;
}*/
