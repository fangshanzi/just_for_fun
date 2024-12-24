#include "stdio.h"

void change(int *a, int *b);
void sort_big_to_small(int *a, int size);
int *array(int *a, int size_a, int *b, int size_b, int *psize_r);

int main(void)
{
    int a[6], b[6];
    int *p;
    int i, size_r;
    printf("Input array a: (size: 6)\n");
    for (i = 0; i < 6; i++)
    {
        scanf("%d", a + i);
    }
    printf("Input array b: (size: 6)\n");
    for (i = 0; i < 6; i++)
    {
        scanf("%d", b + i);
    }
    p = array(a, 6, b, 6, &size_r);
    printf("The result is:\n");
    for (i = 0; i < size_r; i++)
    {
        if (i % 4 == 0 && i != 0)
            printf("\n");
        printf("%d\t", p[i]);
    }
    return 0;
}

void change(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void sort_big_to_small(int *a, int size)
{
    int i, j;
    for (i = size - 2; i >= 0; i--)
        for (j = 0; j <= i; j++)
            if (a[j] < a[j + 1])
                change(a + j, a + j + 1);
}

int *array(int *a, int size_a, int *b, int size_b, int *psize_r)
{
    int i, j, k, l;
    int size_r, size_r_current;
    static int r[20] = {0};
    size_r = size_a + size_b;
    for (i = 0; i < size_a; i++)
        r[i] = a[i];
    for (i = 0; i < size_b; i++)
        r[size_a + i] = b[i];
    sort_big_to_small(r, size_r);
    for (i = 0; i <= size_r - 2; i++)
        if (r[i] == r[i + 1])
        {
            size_r_current = size_r;
            for (j = i + 1; r[j] == r[i] && j < size_r_current; j++)
                size_r--;
            for (k = i + 1; j < size_r_current; k++, j++)
                r[k] = r[j];
        }
    *psize_r = size_r;
    return r;
}