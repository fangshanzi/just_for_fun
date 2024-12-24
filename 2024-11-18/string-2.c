#include <stdio.h>
#include <string.h>

void fun(char s[]);

int main(void)
{
    char s[100] = "aaaacc333bkkkggggd";
    printf("压缩前的数据: ");
    puts(s);
    fun(s);
    printf("压缩后的数据: ");
    puts(s);

    return 0;
}

void fun(char *const s)
{
    char *p;
    char *q;
    int count;
    for (p = s; *p != '\0'; p++)
    {
        //count为*p连续出现的次数，注意p的位置是可变的，标记当前程序处理的起点
        for (count = 1, q = p + 1; *q != '\0' && *q == *p; q++)
            count++;
        //删除冗余，注意此时字符串的长度改变，q停在原字符串的结束处，而在最后一次循环中'\0'已被封存（q+1的妙用）
        for(q--;*q!='\0';q++)
            *(q-count+2)=*(q+1);
        //在p后空出两个字符的位置，通过strlen()函数与字符串的绝对起点s确定当前字符串的结束
        for(q=s+strlen(s);q>=p+1;q--)
            *(q+2)=*q;
        *(p+1)='|';
        *(p+2)='0'+count;
        p+=2;
    }
}