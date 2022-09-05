#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int repalce_blank(char *src);

int main(int argc, char const *argv[])
{
    char str[] = "    12 34  45 67 78 qwe 12 131      ";

    repalce_blank(str);
    printf("str =%s\n", str);

    return 0;
}

void my_print(char *str)
{
    int i = 0;

}
int repalce_blank(char src[])
{
    char needDel = 0;
    char *pQuick = NULL;
    char *pSlow = NULL;

    assert(NULL != src);

    pQuick = src;
    pSlow = src;

    while (*pQuick != '\0')
    {
        if (*pQuick != ' ')
        {
            if (needDel)
            {
                strcpy(pSlow, pQuick);
                pQuick = pSlow;
            }

            pQuick++;
            pSlow = pQuick;
            needDel = 0;
            continue;
        }

        if (!needDel)
        {
           pSlow++; 
        }

        if (*(pQuick+1) == ' ')
        {
            needDel = 1;
        }

        pQuick++;
    }

    if (needDel)
    {
        strcpy(pSlow, pQuick);
    }

    return 1;
}
