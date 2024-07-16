// Write a program that opens a text file
// whose name is obtained interactively.
// Set up a loop that asks the user to enter a file position.
// The program then should print the part of the file
// starting at that position and proceed to the next newline character.
// Let negative or nonnumeric input terminate the user - input loop.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 80

int main(void)
{
    FILE* fp;
    char file[SIZE];
    long pos = 0;
    int ch;

    // Ask for file position.
    puts("Please enter the file position:");
    scanf("%s", file);

    // Check whether the file can be opened.
    if ((fp = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "Can't open %s", file);
        exit(EXIT_FAILURE);
    }
    puts("Enter the position you want to start:");

    // Check pos is number and positive.
    while ((scanf("%ld", &pos)) == 1 && pos >= 0)
    {
        // Go to the position.
        fseek(fp, pos, SEEK_SET);
        // Output.
        while ((ch = getc(fp)) != EOF && ch != '\n')
            putc(ch, stdout);

        putchar('\n');
        puts("Enter another again.");
    }
    puts("Done!");

    fclose(fp);

    return 0;
}