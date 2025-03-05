#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

typedef struct _FILM_
{
    char            title[TSIZE];
    int             rating;
    struct _FILM_ * next;
} film;

char * s_gets(char * st, int n);

int main(void)
{
    film * head = NULL;
    film * prev, *current;
    char   input[TSIZE];

    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) && input[0] != '\0')
    {
        current = (film *) malloc(sizeof(film));
        if (head == NULL)
            head = current;
        else
            prev->next = current;

        current->next = NULL;
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);

        while (getchar() != '\n') continue;
        puts("Enter next movie title (emtpy line to stop):");
        prev = current;
    }

    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");

    current = head;
    while (current)
    {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }

    current = head;
    while (current)
    {
        head = current->next;
        free(current);
        current = head;
    }

    puts("Bye!");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val = fgets(st, n, stdin);
    char * find;

    if (ret_val)
    {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n') continue;
    }

    return ret_val;
}