#include<stdio.h>
#include"stack.h"

int main(void)
{
	stack string;
	item ch;

	init_stack(&string);

	while ((ch = getchar()) != '\n' && ch != EOF)
		add_item_to_stack(ch, &string);

	while (!stack_is_empty(&string))
	{
		ch = pop_up_from_stack(&string);
		printf("%c", ch);
	}

	clear_stack(&string);

	return 0;
}