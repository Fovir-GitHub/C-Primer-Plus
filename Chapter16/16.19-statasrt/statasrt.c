#include<stdio.h>
#include<limits.h>
#include<assert.h>

static_assert(CHAR_BIT == 8/*16*/, "16-bit char falsely assumed");

int main(void)
{
	puts("char is 16 bits.");

	return 0;
}