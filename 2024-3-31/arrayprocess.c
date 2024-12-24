#include "stdio.h"

double max_array(int cols, double array[cols]);

double max_array2d(int rows, int cols, double array[rows][cols]);

void input_array(int cols, double array[cols]);

void input_array2d(int rows, int cols, double array[rows][cols]);

int main(void)
{
    int rows, cols;

    printf("Please input the number of rows&columns:\n");
    scanf("%d%d", &rows, &cols);

    double array[rows][cols];
    int r;

    printf("please input numbers in the array:\n");
    input_array2d(rows, cols, array);

    printf("the max number of each row:\n");
    for(r = 0; r < rows; r++)
        printf("%lf\n", max_array(cols, array[r]));

    printf("the max number of the array:\n");
    printf("%lf\n", max_array2d(rows, cols, array));

    return 0;
}

double max_array(int cols, double array[cols])
{
    int c;
    int max_index;

    for(max_index = 0, c = 1; c < cols; c++)
        if(array[c] > array[max_index])
            max_index = c;

    return array[max_index];
}

double max_array2d(int rows, int cols, double array[rows][cols])
{
    int r;
    double max, max_total;

    max_total = max_array(cols, array[0]);
    for(r = 1; r < rows; r++)
        if((max = max_array(cols, array[r])) > max_total)
            max_total = max;

    return max_total;
}

void input_array(int cols, double array[cols])
{
    int c;

    for(c = 0; c < cols; c++)
        scanf("%lf", array + c);
}

void input_array2d(int rows, int cols, double array[rows][cols])
{
    int r;
    
    for(r = 0; r < rows; r++)
        input_array(cols, array[r]);
}