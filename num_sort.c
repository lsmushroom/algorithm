#include <stdio.h>


/*
 * @arr: 仅包含1,2,3，三种元素的数组，将其按序排列
 * @len: 数组长度
 */
void foo(int* arr, int len)
{
    if(!arr || !len)
        return;

    int i = 0, j, k = len - 1;
    int tmp = 0;
    
    while(arr[i] == 1 && ++i && i < len);
    while(arr[k] == 3 && --k && k >= 0);
    j = i + 1;

    while(j <= k)
    {
        if(arr[j] == 1)
        {
            //i指向当前数组中第一个非1的元素，而这个位置的值有可能当i，j指向同一个元素
            //而arr[j]与arr[k]交换之后，使i指向的原本不是1的元素变为1 ,由此当出现i,j同
            //指向1时，让二者共同前进一步处理下一个元素
            if(arr[i] == 1)
            {
                i++;
                j++;
            }
            else
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;

                i++;
            }
        }
        else if(arr[j] == 3)
        {
            if(arr[k] == 3)
            {
                k--;
                j++;
            }
            else
            {
                tmp = arr[k];
                arr[k] = arr[j];
                arr[j] = tmp;

                k--;
            }
        }
        else if(arr[j] == 2)
        {
            j++;
        }
    }

    return;
}

int main(int argc , char** argv)
{
//    int arr[] = {3, 1, 2, 3, 1, 3, 3, 2, 1, 2, 2, 1};
//    int arr[] = {1,1,1,1,1};
//    int arr[] = {2,2,2,2,2};
    int arr[] = {};
    const int len = sizeof(arr) / sizeof(int);
    int i;

    printf("len = %d\n" , len);
    foo(arr , len);
    for(i = 0; i < len; i++)
    {
        printf("%d " , arr[i]);
    }
    printf("\n");

    return 0;
}
