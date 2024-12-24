#include <stdio.h>
#include <string.h>
void fun(char s[])
{
    int i, j, n, c, k;
    char ch;
    for (i = 0; s[i]; i++)
    {
        c = 1;
        ch = s[i];
        for (j = i + 1; s[j]; j++)
        {
            if (ch != s[j])
            {
                break;
            }
            c++;
        }
        j = j - 1;
        /**********Program**********/
        if (c < 3)
        {
            k = 3 - c;
            for (n = j; s[n]; n++)
                ;
            for (; n >= j + 1; n--)
                s[n + k] = s[n];
        }
        else if (c > 3)
        {
            k = c - 3;
            for (n = j + 1; s[n]; n++)
                s[n - k] = s[n];
            s[n - k] = s[n];
        }
        s[i + 1] = '|';
        s[i + 2] = '0' + c;
        i += 2;
        /**********  End  **********/
    }
}
int main()
{
    char s[100] = "aaaacc333bkkkggggd";
    printf("压缩前的数据: ");
    puts(s);
    fun(s);
    printf("压缩后的数据: ");
    puts(s);
    return 0;
}
