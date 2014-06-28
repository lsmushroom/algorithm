#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* foo(char* str ,  int offset)
{
    if(!str)
        return NULL;

    if(offset == 0)
        return str;

    int len = strlen(str);
    int i = offset % len;
    int j = 0;
    int k = len % i;

    while(i < len)
    {
        str[j] ^= str[i];
        str[i] ^= str[j];
        str[j] ^= str[i];

        j++;
        i++;
    }

    if(j < len && k > 0)
    {
        j++;
        foo(str + j , (offset - k));
    }

    return str;
}

int main(int argc , char** argv)
{
    if(argc < 3)
        return -1;
    
    printf("str: %s\n" , argv[1]);
    printf("str: %s\n" , foo(argv[1] , atoi(argv[2])));

    return 0;
}
