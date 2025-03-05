#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void   showmovies(Item item);
char * s_gets(char * st, int n);

int main(void)
{
    List movies;
    Item temp;

    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr, "No memory available1 Bye!\n");
        exit(1);
    }

    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') continue;

        if (AddItem(temp, &movies) == false)
        {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (emtpy line to stop):");
    }

    if (ListIsEmpty(&movies))
        printf("No data enetered.");
    else
    {
        printf("Here is the movie list:\n");
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));

    EmtpyTheList(&movies);
    printf("Bye!\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val = fgets(st, n, stdin);

    if (ret_val)
    {
        char * find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n') continue;
    }

    return ret_val;
}

void showmovies(Item item)
{
    printf("Movie: %s  Rating: %d\n", item.title, item.rating);
    return;
}
