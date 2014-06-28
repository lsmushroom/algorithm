#include <stdio.h>

char* foo(char* str)
{
    if(!str)
        return NULL;

    return str;
}

int main(int argc , char** argv)
{
    if(argc < 2)
        return -1;
    
    printf("str: %s\n" , argv[1]);
    printf("str: %s\n" , foo(argv[1]));

    return 0;
}
