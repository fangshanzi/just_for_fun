/*若干人编号后坐成一圈，从序号为一的人开始循环报数1，2，3，报3者离席，剩下的人接着报数，直至只剩一人。最后剩下的人序号为几？*/

#include <stdio.h>

int circle(int n);

int main(void)
{
    int n;
    printf("Input n:\n");
    scanf("%d", &n);
    printf("%d", circle(n));

    return 0;
}

int circle(int n)
{
    int circle[n + 1];//模拟报数
    int report;
    int count;//计量剩余人数
    int mark;

    for (int i = 1; i <= n; i++)
        circle[i] = 1;
    for (mark = 1, report = 0, count = n;; mark++)
    {
        if (circle[mark] == 1)
        {
            report++;
            if (report == 3)
            {
                circle[mark] = 0;
                report = 0;
                count--;
                if (count == 1)
                    break;
            }
        }
        if (mark == n)
            mark = 0;//实现循环报数
    }
    for (mark = 1; mark <= n; mark++)
        if (circle[mark] == 1)
            break;

    return mark;
}