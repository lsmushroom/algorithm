#include <stdio.h>
#include <string.h>

char foo(char* str)
{
    if(!str)
        return 0;

    static int map[256];
    int i = 0;
    //可以不用计算其长度，操作指针访问数组元素，检测是否为'\0'来判断是否结束
    int len = strlen(str); 

    memset(map , 0 , 256);

    for(i = 0; i < len; i++)
    {
        map[str[i]]++;
    }
    
    for(i = 0; i < len; i++)
    {
        if( map[str[i]] == 1 )
            break;
    }

    return str[i];
}

int main(int argc , char** argv)
{
    if(argc < 2)
        return -1;
    
    printf("str: %s\n" , argv[1]);
    printf("char: %c\n" , foo(argv[1]));

    return 0;
}
