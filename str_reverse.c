#include <stdio.h>
#include <string.h>

/* 不开辟新空间完成字符串的逆序
 * Input:
 * @str: string
 *Return:
 * return: reverse the string
 */
char* foo(char* str)
{
    if(!str)
        return NULL;

    int i = 0;
    int j = strlen(str) - 1;

    for(;i < j; i++ , j--)
    {
//        str[i] ^= str[j] ^= str[i] ^= str[j];
        str[i] ^= str[j];
        str[j] ^= str[i];
        str[i] ^= str[j];
    }

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
