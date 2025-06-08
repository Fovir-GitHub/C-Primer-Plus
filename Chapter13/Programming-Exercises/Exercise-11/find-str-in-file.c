// Write a program that takes two command - line arguments.
// The first is a string; the second is the name of a file.
// The program should then search the file,
// printing all lines containing the string.
// Because this task is line oriented rather than character oriented,
// use  fgets() instead of getc().
// Use the standard C library function  strstr()
// (briefly described in exercise 7 of  Chapter   11)
// to search each line for the string.
// Assume no lines are longer than 255 characters.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int main(int argc, char * argv[]) {
    FILE * fp;
    char temp[MAX];

    // If the number of arguments is wrong.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s string filename.", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Check whether the file can be opened.
    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Can't open %s", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("Lines containing the string \"%s\":\n", argv[1]);
    // Start search.
    while (fgets(temp, MAX, fp) != NULL)
        if (strstr(temp, argv[1]) != NULL)
            fprintf(stdout, temp);

    fclose(fp);

    return 0;
}