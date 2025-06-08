// Write a function that takes two int arguments : a value and a bit position.
// Have the function return 1 if that particular bit position is 1,
// and have it return 0 otherwise.Test the function in a program.

#include <stdbool.h>
#include <stdio.h>

bool thePositionisOn(int n, int position);

int main(void) {
    int n, pos;

    while (scanf("%d %d", &n, &pos) == 2)
        printf("%d\n", thePositionisOn(n, pos));

    return 0;
}

bool thePositionisOn(int n, int position) { return (n & (1 << position)); }
