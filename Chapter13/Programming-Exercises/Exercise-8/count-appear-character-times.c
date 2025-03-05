// Write a program that takes as command - line arguments a character
// and zero or more filenames.If no arguments follow the character,
// have the program read the standard input.
// Otherwise, have it open each file in turn
// and report how many times the character appears in each file.
// The filename and the character itself
// should be reported along with the count.
// Include error - checking to see whether the number of arguments is correct
// and whether the files can be opened.
// If a file can’t be opened,
// have the program report that fact and go on to the next file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    FILE * fp;
    int    ch;
    int    origin;
    int    count = 0;

    // If arguments less than 2
    if (argc < 2)
    {
        fprintf(stderr, "No enough arguments.");
        exit(EXIT_FAILURE);
    }
    // If the first argument is not a character.
    if (strlen(argv[1]) > 1)
    {
        fprintf(stderr, "The first argument should be a single character.");
        exit(EXIT_FAILURE);
    }

    // Get original character.
    origin = argv[1][0];

    // If have 2 arguments, read from stdin.
    if (argc == 2)
    {
        // Stop reading till '\n'.
        while ((ch = getchar()) != '\n')
            if (ch == origin)
                count++;
        printf("The character \'%c\' appeared %d times.\n", origin, count);

        return 0;
    }

    for (int i = 2; i < argc; i++)
    {
        // If can't open the file.
        if ((fp = fopen(argv[i], "r")) == NULL)
            fprintf(stderr, "Can't open the file %s\n", argv[i]);
        else
        {
            // Set count to 0.
            count = 0;
            // Read in.
            while ((ch = getc(fp)) != EOF)
                if (origin == ch)
                    count++;
            // Output the result.
            fprintf(stdout, "In file %s, \'%c\' appeared %d times.\n", argv[i],
                    origin, count);

            fclose(fp);
        }
    }
}