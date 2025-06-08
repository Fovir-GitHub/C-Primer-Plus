#include <assert.h>
#include <limits.h>
#include <stdio.h>

static_assert(CHAR_BIT == 8 /*16*/, "16-bit char falsely assumed");

int main(void) {
    puts("char is 16 bits.");

    return 0;
}