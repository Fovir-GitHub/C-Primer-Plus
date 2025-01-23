// Write a program that lets you input a string.
// The program then should push the characters of the string onto a stack,
// one by one(see review question 5),
// and then pop the characters from the stack and display them.
// This results in displaying the string in reverse order.

#include "stack.h"
#include <stdio.h>

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