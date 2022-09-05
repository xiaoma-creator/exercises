#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int repalce_blank(char *src);

int main(int argc, char const *argv[])
{
    char *str = "1  2 3  4 5  6";

    repalce_blank(str);
    printf("str = %s\n", str);

    return 0;
}

int repalce_blank(char *src)
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
                memcpy(pSlow, pQuick, strlen(pQuick));
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
        memcpy(pSlow, pQuick, strlen(pQuick));
    }
    
    *(pQuick+1) = '\0';

    return 1;
}
