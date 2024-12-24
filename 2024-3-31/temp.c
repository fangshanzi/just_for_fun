#include "stdio.h"

long sum3d(int ds, int rows, int cols, long pa[ds][rows][cols]);

int main(void)
{
    long shots[4][2][3];
    int d, r, c;
    long sum;

    for (d = 0; d < 4; d++)
        for (r = 0; r < 2; r++)
            for (c = 0; c < 3; c++)
                scanf("%ld", &shots[d][r][c]);

    sum = sum3d(4, 2, 3, shots);

    printf("sum=%d", sum);
}

long sum3d(int ds, int rows, int cols, long pa[ds][rows][cols])
{
    int d, r, c;
    long sum;

    for (sum = 0, d = 0; d < ds; d++)
        for (r = 0; r < rows; r++)
            for (c = 0; c < cols; c++)
                sum += pa[d][r][c];

    return sum;
}