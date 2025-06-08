// Write a function called  transform()
// that takes four arguments :
// the name of a source array containing type  double data,
// the name of a target array of type  double,
// an  intrepresenting the number of array elements,
// and the name of a function(or , equivalently, a pointer to a function).
// The  transform() function should apply the indicated function to
// each element in the source array,
// placing the return value in the target array.
// For example, the call
// transform(source, target, 100, sin);
// would set  target[0] to  sin(source[0]), and so on, for 100 elements.
// Test the function in a program that calls  transform() four times,
// using two functions from the  math.hlibrary
// and two suitable functions of your own devising as arguments
// to successive calls of the  transform() function.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 200

void transform(double source[], double target[], int number,
               double (*func)(double));
void GenerateData(double arr[], int n);
void OutputArray(double arr[], int n);

int main(void) {
    const int GenerateNumber = 20;
    srand(time(NULL));
    double Source[SIZE];
    double Target[SIZE];
    GenerateData(Source, SIZE);
    OutputArray(Source, GenerateNumber);
    putchar('\n');
    transform(Source, Target, GenerateNumber, tan);
    OutputArray(Target, GenerateNumber);

    return 0;
}

void transform(double source[], double target[], int number,
               double (*func)(double)) {
    for (int i = 0; i < number; i++)
        target[i] = func(source[i]);
    return;
}

void GenerateData(double arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = (double)rand() / 123;
    return;
}

void OutputArray(double arr[], int n) {
    for (int i = 1; i <= n; i++)
        printf("%lf%c", arr[i - 1], (i % 5 ? ' ' : '\n'));
    return;
}
