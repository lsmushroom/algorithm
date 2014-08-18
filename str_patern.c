#include <stdio.h>

int isSubstr(char* s , int slen , char* p , int plen)
{
    if(!s || !p)
        return 0;

    int i , j;

    for(i = 0 , j = 0; i < slen && j < plen; i++)
    {
        if(s[i] == p[j]) {
            j++;
        } else if(j > 0) {
            j = 0;
        }
    }

    if(j == plen)
        return i;

    return 0;
}

int foo(const char* s , const char* p)
{
    if(!s || !p)
        return 0;

    int i , j;
    int slen = strlen(s);
    int plen = strlen(p);
    int start , end;

    for(i = 0, j = 0; i < slen && j < plen; i++)
    {
        if(p[j] == '*')
        {
            while(j < plen && p[j] == '*')
                ++j;

            start = j;
            while(j < plen && p[j] != '*')
                ++j;

            end = j;
            i = isSubstr(s + i, slen - i, p + start , end - start);
            if(i == 0)
                break;
        }
        else if(s[i] == p[j] || p[j] == '?')
        {
            j++;
        }
        else
        {
            break;
        }
    }

    if(i < slen)

    return 0;
}

int main(int argc , char** argv)
{
    if(argc < 3)
        return -1;
    
    printf("str: %s , pattern: %s\n" , argv[1] , argv[2]);
    printf("is patern: %d\n" , foo(argv[1] , argv[2]));

    return 0;
}
