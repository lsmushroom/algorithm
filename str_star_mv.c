#include <stdio.h>
#include <string.h>

//#define swap(x , y) do { \
    typeof(x) _x = x; \
    typeof(y) _y = y; \
    _x ^= _y; \
    _y ^= _x; \
    _x ^= _y; \
}while(0);

#define swap(a, b) \
    do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)

/*
 * 函数将字符串中的字符'*'移到串的前部分，前面的非'*'字符后移，但不能改变非'*'字符的先后顺序，
 * 函数返回串中字符'*'的数量。如原始串为：ab**cd**e*12，处理后为*****abcde12，函数并返回值为5。
 * */
int foo(char* str)
{
    if(!str)
        return 0;

    int cnt = 0;
    int len = strlen(str) - 1;
    int i = len, j = len;

    while(i >= 0)
    {
        if(str[i] != '*')
            j--;
        i--;

        if( i >= 0 && i < j && str[i] != '*')
        //if(i < j && str[i] != '*')
        {
            swap(str[i] , str[j]);
            cnt++;
            j--;
        }
    }

    return cnt;
}

int main(int argc , char** argv)
{
 //   if(argc < 2)
  //      return -1;
    
//    printf("str: %s\n" , argv[1]);
//    printf("str: %n , %s\n" , foo(argv[1]) , argv[1]);
//    printf("str: %n\n" , foo(argv[1]));

    char test[] = "ab**cd**ef" ;
    int cnt = foo(argv[1]);

    printf("str: %d\n" , cnt);
    printf("str: %s\n" , argv[1]);

    return 0;
}
