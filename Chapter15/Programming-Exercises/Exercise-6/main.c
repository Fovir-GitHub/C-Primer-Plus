// Design a bit - field structure that holds the following information :
// Font ID : A number in the range 0–255
// Font Size : A number in the range 0–127
// Alignment : A number in the range 0–2 represented the choices Left,
// Center, and Right
// Bold : Off(0) or on(1)
// Italic : Off(0) or on(1)
// Underline : Off(0) or on(1)
// Use this structure in a program that displays the font parameters
// and uses a looped menu to let the user change parameters.

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"font.h"

int main(void)
{
	font MyFont = { 1,12,0,false,false,false };
	int Choice;

	while (true)
	{
		Choice = GetChoice(&MyFont);

		switch (Choice)
		{
		case 'f':
			ChangeFont(&MyFont);
			EatLine();
			break;
		case 's':
			ChangeFontSize(&MyFont);
			EatLine();
			break;
		case 'a':
			ChangeAlignment(&MyFont);
			break;
		case 'b':
			ToggleStyle(&MyFont, BOLD);
			break;
		case 'i':
			ToggleStyle(&MyFont, ITALIC);
			break;
		case 'u':
			ToggleStyle(&MyFont, UNDERLINE);
			break;
		case 'q':
			printf("Bye!");
			return 0;
		}
	}

	return 0;
}