/*
题目：N名学生的成绩已在主函数中放入一个带头节点的链表结构中，h指向链表的头节点。
      请编写函数fun，其功能是：求出平均分，并由函数值返回。

例如：若学生的成绩是：85　76　69　85　91　72　64　87，则平均分应当是：78.625。

注意：请勿改动主函数main和其它函数中的任何内容，仅在函数fun的花括号中填入你
      编写的若干语句。
*/

#include "stdio.h"
#include "stdlib.h"

#define N 8

struct slist
{
    double s;
    struct slist *next;
};

typedef struct slist STREC;

STREC *create(double *s);
void free_space(STREC *head);
void outlist(STREC *h);
double fun(STREC *h);

int main(void)
{
    double s[N] = {85, 76, 69, 85, 91, 72, 64, 87}, ave;
    STREC *h;

    h = create(s);
    outlist(h);
    ave = fun(h);
    printf("ave= %6.3f\n", ave);
    free_space(h);

    return 0;
}

STREC *create(double *s)
{
    STREC *head, *prev, *current;
    int i;
    head = prev = (STREC *)malloc(sizeof(STREC));
    prev->s = 0;
    for (i = 0; i < N; i++)
    {
        current = (STREC *)malloc(sizeof(STREC));
        current->s = s[i];
        prev->next = current;
        prev = current;
    }
    prev->next = NULL;
    return head;
} // 创建了一个无用的节点

void outlist(STREC *h)
{
    STREC *p;
    p = h->next; // 跳过第一个无用节点
    printf("head");
    do
    {
        printf("->%4.1f", p->s);
        p = p->next;
    } while (p != NULL);
    printf("\n\n");
}

double fun(STREC *head)
{
    double ave=0;
    STREC *current;
    current=head;
    while(current!=NULL)
    {
        ave+=current->s;
        current=current->next;
    }
    return ave/N;
}

void free_space(STREC * head)
{
    STREC *current;
    current=head;
    while(current!=NULL)
    {
        head=current->next;
        free(current);
        current=head;
    }
}