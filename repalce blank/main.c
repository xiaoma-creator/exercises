
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int repalce_blank(char *src);

/* 删除字符串中多余的空格，使不会出现连续的空格 */
void delete_multi_spaces(char str[])
{
    int is_first_space = 1;
    int i = 0;
    int j = 0;

    assert(NULL != str);

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            if (is_first_space)
            {
                is_first_space = 0;
                str[j++] = str[i]; 
            }
        }
        else
        {
            str[j++] = str[i];
            is_first_space = 1;
        }

        i++;
    }

    str[j] = '\0';
}

int main(int argc, char const *argv[])
{
    char str[] = "   12 45       97  */ 8888     ";
    // char str[] = "";

    delete_multi_spaces(str);
    printf("str ='%s'\n", str);

    return 0;
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
