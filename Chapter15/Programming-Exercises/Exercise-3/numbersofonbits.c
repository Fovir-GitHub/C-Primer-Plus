// Write a function that takes an  int argument and
// returns the number of “on” bits in the argument.
// Test the function in a program.

#include<stdio.h>

int CountOnBits(int n);

int main(void)
{
	int n;

	while (scanf("%d", &n) == 1)
		printf("There are %d on bits in %d\n",
			CountOnBits(n), n);

	return 0;
}

int CountOnBits(int n)
{
	int Count = 0;

	while (n)
	{
		if ((n | 1) == n)
			Count++;
		n >>= 1;
	}

	return Count;
}
