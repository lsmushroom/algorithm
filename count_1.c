#include <stdio.h>
#include <stdlib.h>

int foo(int n)
{
    int cnt = 0;
    int val = 0;
    int i = 0;

    for(; i <= n; i++)
    {
        val = i;
        while(val)
        {
            cnt += (int)(val%10 == 1);
            val /= 10;
        }
    }

    return cnt;
}

int main(int argc , char** argv)
{
    if(argc < 2)
        return -1;
    
    printf("str: %s\n" , argv[1]);
    printf("cnt: %d\n" , foo(atoi(argv[1])));

    return 0;
}
