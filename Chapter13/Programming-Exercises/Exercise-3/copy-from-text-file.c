// Write a file copy program that
// prompts the user to enter the name of a text file
// to act as the source file and the name of an output file.
// The program should use the toupper() function from ctype.h
// to convert all text to uppercase as it’s written to the output file.
// Use standard I / O and the text mode.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 80

int main(void)
{
    FILE *in, *out;
    char  source_file[SIZE];
    char  output_file[SIZE];
    int   ch;

    // Get source file name.
    puts("Please enter the source file name:");
    scanf("%s", source_file);

    // If can not open the source file.
    if ((in = fopen(source_file, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s", source_file);
        exit(EXIT_FAILURE);
    }

    // Get output file name.
    puts("Please enter the output file name:");
    scanf("%s", output_file);
    // Open the output file.
    out = fopen(output_file, "w");

    // Start copy.
    while ((ch = getc(in)) != EOF) putc(toupper(ch), out);
    puts("Done!");

    // Close files.
    fclose(in);
    fclose(out);

    return 0;
}