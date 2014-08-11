#include <stdio.h>
#include <string.h>

//检查字符串是否是镜像：abcdedcba
int foo(char* str)
{
    if(!str)
        return 0;

    int len = strlen(str);
    int i = 0, j = len - 1;

    for(; i < j; i++ , j--)
    {
        if(str[i] != str[j])
            break;
    }

    return i == j ? 1 : 0;
}

int main(int argc , char** argv)
{
    if(argc < 2)
        return -1;
    
    printf("str: %s\n" , argv[1]);
    printf("str: %d\n" , foo(argv[1]));

    return 0;
}
