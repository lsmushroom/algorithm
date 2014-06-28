#include <stdio.h>
#include <string.h>

/* 删除字符串中的数字并压缩字符串（神州数码以前笔试题），如字符串”abc123de4fg56”
 * 处理后变为”abcdefg”。注意空间和效率。（下面的算法只需要一次遍历，不需要开辟新
 * 空间，时间复杂度为O(N)）
 * Input:
 * @str: string with character and integer number
 *Return:
 * return: remove the integer number, just keep the character in the string
 */
char* foo(char* str)
{
    if(!str)
        return NULL;

    int i = 0 , j = 0;
    int len = strlen(str);

    while(i < len)
    {
        if((str[i] >= 'a' && str[i] <= 'z')
                || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if(j < i)
                str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

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
