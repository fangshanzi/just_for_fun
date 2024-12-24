#include "stdio.h"
#include "string.h"
#define MAXSIZE 100

void fun(char *str)
{
    int len = 0, mid;
    char * temp = str;

    printf("\n[The middle character(s):]");
    len = strlen(temp);
    mid = len / 2;
    if(len % 2 == 0)
        printf("%c%c", temp[mid-1], temp[mid]);
    else
        printf("%c", temp[mid]);
}

int main(void)
{
    char str[MAXSIZE];
    scanf("%s", str);
    fun(str);
}