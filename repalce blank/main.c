
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int repalce_blank(char *src);
void my_print(char *str);

int main(int argc, char const *argv[])
{
    char str[] = "";

    repalce_blank(str);
    printf("str =%s\n", str);
    my_print(str);

    return 0;
}

void my_print(char *str)
{
    int i = 0;
    int len = strlen(str);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '.';
        }

        putchar(str[i]);
    }
    
    putchar('\n');
}

/* 删除字符串中多余的空格，使不会出现连续的空格 */
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

        if (!needDel) pSlow++; 
        if (*(pQuick+1) == ' ') needDel = 1;

        pQuick++;
    }

    if (needDel)
    {
        strcpy(pSlow, pQuick);
    }

    return 1;
}
