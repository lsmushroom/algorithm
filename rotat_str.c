#include <stdio.h>
#include <string.h>

int foo(const char* a , const char* b)
{
    if(!a || !b)
        return 0;

    int i , j;
    int alen = strlen(a);
    int blen = strlen(b);

    for(i = 0; i < alen; i++)
    {
        if(a[i] == b[0])
            break;
    }

    if(i == alen)
        return 0;

    for(j = 0; j < blen; j++ , i = (i + 1)%alen )
    {
        if(b[j] != a[i])
            break;
    }

    if(j == blen)
        return 1;

    return 0;
}

int main(int argc , char** argv)
{
    if(argc < 2)
        return -1;
    
    printf("str1: %s , str2: %s\n" , argv[1] , argv[2]);
    printf("rotate: %d\n" , foo(argv[1] ,argv[2]));

    return 0;
}
