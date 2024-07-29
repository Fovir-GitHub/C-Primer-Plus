// Write a function that rotates the bits of
// an  unsigned int by a specified number of bits to the left.
// For instance, rotate_l(x, 4) would move the bits in x four places
// to the left, and the bits lost from the left end would reappear
// at the right end.That is, the bit moved out of
// the high - order position is placed in the low - order position.
// Test the function in a program.

#include<stdio.h>
#include<limits.h>

unsigned int rotate(unsigned int x, int num);
char * itobs(int, char *);
void show_bstr(const char *);
void shownuminbin(int x);

int main(void)
{
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	unsigned int x;
	int num;
	unsigned int result;

	while (scanf("%u %d", &x, &num) == 2)
	{
		puts("Original:");
		shownuminbin(x);
		result = rotate(x, num);
		puts("After operation:");
		shownuminbin(result);
	}

	return 0;
}

unsigned int rotate(unsigned int x, int num)
{
	const int bits = CHAR_BIT * sizeof(unsigned int);
	num %= bits;
	return (x << num) | (x >> (bits - num));
}

void shownuminbin(int x)
{
	char bin[CHAR_BIT * sizeof(unsigned int) + 1];
	show_bstr(itobs(x, bin));
	putchar('\n');
}

char * itobs(int n, char * ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(unsigned int);

	for (i = size - 1;i >= 0;i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}

void show_bstr(const char * str)
{
	int i = 0;

	while (str[i])
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}

	return;
}
