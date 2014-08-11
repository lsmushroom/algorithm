#include <stdio.h>
#include <string.h>

int foo(const char* a , const char* b)
{
    if(!a || !b)
        return 0;

    int i , j;
    int alen = strlen(a);
    int blen = strlen(b);

    for(i = 0, j = 0; i < alen && j < blen; i++)
    {
        if(a[i] == b[j]) {
            j++;
        } else if(j > 0) {
            j = 0;
        }
    }

    if(j == blen)
        return 1;

    return 0;
}

int main(int argc , char** argv)
{
    if(argc < 3)
        return -1;
    
    printf("a: %s , b: %s " , argv[1] , argv[2]);
    printf("is str: %d\n" , foo(argv[1] , argv[2]));

    return 0;
}
