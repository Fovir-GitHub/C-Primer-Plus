#include "names.h"
#include <stdio.h>

int main(void) {
    names winner = {"Less", "Ismoor"};

    printf("The winner is %s %s.\n", winner.first, winner.last);

    return 0;
}