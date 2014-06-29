#include <stdio.h>
#include <string.h>

char* foo(char* str1 , char* str2)
{
    if(!str1)
        return NULL;

    if(!str2)
        return str1;

    int nlen1 = strlen(str1);
    int nlen2 = strlen(str2);
    int i = 0, j = 0, k = 0;

    static int map[255];

    memset(map , 0 , 255);
    for(i = 0; i < nlen2; i++)
    {
        map[str2[i]] = 1;
    }

    while(j < nlen1)
    {
        if( !map[str1[j]] )
        {
            if(k < j)
            {
                str1[k] = str1[j];
            }
            k++;
        }
        j++;
    }

    str1[k] = '\0';
    
    return str1;
}

int main(int argc , char** argv)
{
    char str1[] = "They are students";
    char str2[] = "Ttaeiou";
    
    printf("str: %s\n" , str1);
    printf("str: %s\n" , foo(str1 , str2));

    return 0;
}
