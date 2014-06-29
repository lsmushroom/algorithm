#include <stdio.h>

void print(char* str , int chosen)
{
    if(!str)
        return;

    int i;
    int mask = 1;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(!((mask << i) & chosen))
        {
            printf("%c" , str[i]);
            chosen &= (mask << i);
            print(str , chosen);
            chosen &= ~(mask << i);
        }
    }
//    printf("\n");
}

void foo(char* str)
{
    if(!str)
        return ;

    print(str , 0);
}

int main(int argc , char** argv)
{
    if(argc < 2)
        return -1;
    
    printf("str: %s\n" , argv[1]);
    foo(argv[1]);

    return 0;
}
