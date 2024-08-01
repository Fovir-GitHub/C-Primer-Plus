// Write a function that takes as arguments the name of
// an array of type  int elements, the size of an array,
// and a value representing the number of picks.
// The function then should select the indicated number of
// items at random from the array and prints them.
// No array element is to be picked more than once.
// (This simulates picking lottery numbers or jury members.)
// Also, if your implementation has  time() (discussed in  Chapter   12)
// or a similar function available, use its output with  srand()
// to initialize the  rand() random - number generator.
// Write a simple program that tests the function.

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

#define ARRAY_SIZE 50

void generate_data(int array[], int array_size);
void randomly_pick_numbers(int array[], int array_size, int pick_number);

int main(void)
{
	srand(time(NULL));
	int array[ARRAY_SIZE];
	int pick_number;

	generate_data(array, ARRAY_SIZE);

	puts("Please enter number of pick:");
	while (scanf("%d", &pick_number) == 1)
	{
		if (pick_number > ARRAY_SIZE)
		{
			puts("Please enter again:");
			continue;
		}

		randomly_pick_numbers(array, ARRAY_SIZE, pick_number);
		putchar('\n');
		puts("Enter new number of pick:");
	}

	return 0;
}

void generate_data(int array[], int array_size)
{
	for (int i = 0;i < array_size;i++)
		array[i] = rand() % 100;
	return;
}

void randomly_pick_numbers(int array[], int array_size, int pick_number)
{
	bool record[array_size];
	memset(record, false, sizeof(record));
	int pick_position = 0;
	int count = 0;

	for (int i = 0;i < pick_number;i++)
	{
		while (record[pick_position])
			pick_position = rand() % array_size;

		record[pick_position] = true;

		printf("%d ", array[pick_position]);
		if (++count % 6 == 0)
			putchar('\n');
	}

	return;
}
