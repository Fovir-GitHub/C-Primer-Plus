// Write a function that converts a binary string to a numeric value.
// That is, if you have char * pbin = "01001001";
// you can pass  pbin as an argument to the function
// and have the function return an  intvalue of  25 .

#include<stdio.h>
#include<string.h>

#define LEN 40

int BinaryString2Int(const char * str);

int main(void)
{
	char BinaryString[LEN];

	while (scanf("%s", BinaryString) == 1)
		printf("%d\n", BinaryString2Int(BinaryString));
	return 0;
}

int BinaryString2Int(const char * str)
{
	int Length = strlen(str);
	int sum = 0;

	for (int i = 0;i < Length;i++)
		sum = (sum <<= 1) + (str[i] - '0');
	return sum;
}
