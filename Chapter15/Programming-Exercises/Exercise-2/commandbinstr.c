// Write a program that reads two binary strings as
// command - line arguments and prints the results of
// applying the  ~operator to each number
// and the results of applying the &, | , and ^operators to the pair.
// Show the results as binary strings.

#include<stdio.h>
#include<string.h>	
#include<limits.h>

const static int Size = CHAR_BIT * sizeof(int);

int BinaryString2Int(const char * str);
char * Int2BinaryString(int n, char * ps);
void ShowBinaryString(const char * str);

int main(int argc, char * argv[])
{
	char BinaryString[Size + 1];
	char * First = argv[1];
	char * Second = argv[2];

	int FirstNumber = BinaryString2Int(First);
	int SecondNumber = BinaryString2Int(Second);

	printf("~%d:\n", FirstNumber);
	ShowBinaryString(Int2BinaryString(~FirstNumber, BinaryString));
	putchar('\n');

	printf("~%d:\n", SecondNumber);
	ShowBinaryString(Int2BinaryString(~SecondNumber, BinaryString));
	putchar('\n');

	printf("%d & %d:\n", FirstNumber, SecondNumber);
	ShowBinaryString(Int2BinaryString(
		FirstNumber & SecondNumber, BinaryString
	));
	putchar('\n');

	printf("%d | %d:", FirstNumber, SecondNumber);
	ShowBinaryString(Int2BinaryString(
		FirstNumber | SecondNumber, BinaryString
	));
	putchar('\n');

	printf("%d ^ %d:\n", FirstNumber, SecondNumber);
	ShowBinaryString(Int2BinaryString(
		FirstNumber ^ SecondNumber, BinaryString
	));

	putchar('\n');

	puts("Done.");

	return 0;
}

int BinaryString2Int(const char * str)
{
	int Sum = 0;
	int Length = strlen(str);

	for (int i = 0;i < Length;i++)
		Sum = (Sum <<= 1) + (str[i] - '0');

	return Sum;
}

char * Int2BinaryString(int n, char * ps)
{
	for (int i = Size - 1;i >= 0;i--, n >>= 1)
		ps[i] = (1 & n) + '0';

	return ps;
}

void ShowBinaryString(const char * str)
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
