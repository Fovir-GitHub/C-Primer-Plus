// Write a file-copy program that takes the original filename and
// the copy file from the command line.
// Use standard I/O and the binary mode, if possible.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 80

int main(int argc, char * argv[])
{
    FILE *in, *out;
    int ch;

    // If the arument is wrong.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // If fail to open the file.
    if ((in = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    // Get copied file name.
    char * file = strcat(argv[1], ".copy");
    // Open the copied file.
    out = fopen(file, "wb");
    // Copy
    while ((ch = getc(in)) != EOF) putc(ch, out);
    printf("Copied!\n");
    // Close file.
    fclose(in);
    fclose(out);

    return 0;
}