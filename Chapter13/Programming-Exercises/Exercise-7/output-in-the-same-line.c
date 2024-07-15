// Write a program that opens two files.
// You can obtain the filenames either by using command - line arguments
// or by soliciting the user to enter them.
// 	a.Have the program print line 1 of the first file,
// line 1 of the second file, line 2 of the first file,
// line 2 of the second file, and so on,
// until the last line of the longer file(in terms of lines) is printed.
// 	b.Modify the program so that lines with
// the same line number are printed on the same line.

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
	FILE* first, * second;
	char ch = 0;

	// If arguments are error.
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s filename1 filename2",
			argv[0]);
		exit(EXIT_FAILURE);
	}
	// If can't open file.
	if ((first = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can't open the first file.");
		exit(EXIT_FAILURE);
	}
	if ((second = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Can't open the second file.");
		exit(EXIT_FAILURE);
	}
	while (!(feof(first) && feof(second)))
	{
		if (!feof(first))
		{
			while ((ch = getc(first)) != '\n' && ch != EOF)
				putc(ch, stdout);
			putc(' ', stdout);
		}
		if (!feof(second))
			while ((ch = getc(second)) != '\n' && ch != EOF)
				putc(ch, stdout);

		putc('\n', stdout);
	}

	// Close files.
	fclose(first);
	fclose(second);

	return 0;

}