#include"font.h"

int GetChoice(font * ft)
{
	char Choice;
	ShowFontStatus(ft);
	putchar('\n');

	// Put menu
	puts("f)change font    s)change size    a)change alignment");
	puts("b)toggle bold    i)toggle italic  u)toggle underline");
	puts("q)quit");

	Choice = getchar();
	EatLine();

	while (strchr("fsabiuq", Choice) == NULL)
	{
		puts("Please enter right choice:");
		Choice = getchar();
		EatLine();
	}

	return Choice;
}

void ShowFontStatus(font * ft)
{
	printf("ID SIZE ALIGNMENT   B   I   U\n");
	printf("%2d %4d    %s    %s %s %s\n",
		ft->FontID, ft->FontSize,
		(ft->Alignment == 0 ? ("Left") :
			(ft->Alignment == 1 ? "Center" : "Right")),
		ft->Bold ? "on" : "off",
		ft->Italic ? "on" : "off",
		ft->Underline ? "on" : "off");

	return;
}

void ChangeFontSize(font * ft)
{
	int NewFontSize;
	printf("Enter font size (0~127): ");

	while (scanf("%d", &NewFontSize) == 1)
	{
		if (NewFontSize < 0 || NewFontSize>127)
			printf("Enter font size (0~127): ");
		else
			break;
	}

	ft->FontSize = NewFontSize;

	return;
}

void ChangeAlignment(font * ft)
{
	char Choice;

	// put menu
	puts("Select alignment:");
	puts("l)left  c)center  r)right");

	Choice = getchar();
	EatLine();

	while (strchr("lcr", Choice) == NULL)
	{
		EatLine();
		puts("Please enter right choice:");
		EatLine();
	}

	ft->Alignment = (Choice == 'l' ? 0 :
		(Choice == 'c' ? 1 : 2));
	return;
}

void ToggleStyle(font * ft, int style)
{
	switch (style)
	{
	case BOLD:
		ft->Bold ^= 1;
		break;
	case ITALIC:
		ft->Italic ^= 1;
		break;
	case UNDERLINE:
		ft->Underline ^= 1;
		break;
	}
	return;
}

void ChangeFont(font * ft)
{
	int NewFontID;
	printf("Please enter font ID(1~99): ");

	while (scanf("%d", &NewFontID) == 1)
	{
		if (NewFontID < 1 || NewFontID>99)
			printf("Please enter font ID(1~99): ");
		else
			break;
	}

	ft->FontID = NewFontID;
	return;
}

void EatLine(void)
{
	while (getchar() != '\n')
		continue;
	return;
}