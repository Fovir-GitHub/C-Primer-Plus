// Write a function that takes three arguments :
// the name of an array of sorted integers,
// the number of elements of the array, and an integer to seek.
// The function returns the value 1 if the integer is in the array,
// and 0 if it isn’t.Have the function use the binary search technique.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

void generate_data(int data[], int n);
void output_data(int data[], int n);
int  binary_search(int data[], int element_number, int number);
int  my_compare(const void * a, const void * b);

int main(void)
{
    srand(time(0));

    int data[ARRAY_SIZE];
    int find_number;

    generate_data(data, ARRAY_SIZE);
    qsort(data, ARRAY_SIZE, sizeof(int), my_compare);

    puts("Please enter the number:");
    while (scanf("%d", &find_number) == 1)
    {
        output_data(data, ARRAY_SIZE);
        putchar('\n');
        printf("%d\n", binary_search(data, ARRAY_SIZE, find_number));
        puts("Next number to find:");
    }

    return 0;
}

void generate_data(int data[], int n)
{
    for (int i = 0; i < n; i++) data[i] = rand() % 1000;

    return;
}

void output_data(int data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
        if (i > 0 && i % 5 == 0)
            putchar('\n');
    }

    return;
}

int binary_search(int data[], int element_number, int number)
{
    int left = 0, right = element_number - 1;
    int middle;
    // if (number == data[left] || number == data[right])
    // 	return 1;
    if (number < data[left] || number > data[right])
        return 0;

    while (left <= right)
    {
        middle = left + (right - left) / 2;

        if (data[middle] == number)
            return 1;
        else if (data[middle] < number)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return 0;
}

int my_compare(const void * a, const void * b)
{
    const int * first  = (const int *) a;
    const int * second = (const int *) b;

    if (*first > *second)
        return 1;
    else if (*first < *second)
        return -1;
    else
        return 0;
}
