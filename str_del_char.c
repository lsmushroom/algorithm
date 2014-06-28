#include <stdio.h>
#include <string.h>

/*删除串中指定的字符
 * Input:
 * @str: sting
 * @c: char need to be deleted
 * Return: string without the character specified by c
 */
char* foo(char* str , char* c)
{
    if(!str)
        return NULL;

    int i = 0 , j = 0;
    int len = strlen(str);

    while(i < len)
    {
        if(str[i] != c[0])
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
    if(argc < 3)
        return -1;

    printf("%s\n" , argv[1]);
    printf("%s\n" , foo(argv[1] , argv[2]));

    return 0;
}
