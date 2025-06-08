#include <stdio.h>
#include <string.h>

#define TSIZE 45
#define FMAX 5

typedef struct _FILM_ {
    char title[TSIZE];
    int raing;
} film;

char * s_gets(char * st, int n);

int main(void) {
    film movies[FMAX];
    int i = 0;
    int j;

    puts("Enter first movie title:");
    while (i < FMAX && s_gets(movies[i].title, TSIZE) != NULL &&
           movies[i].title[0] != '\0') {
        puts("Enter your rating <0-10>:");
        scanf("%d", &movies[i++].raing);

        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (emtpy line to stop):");
    }

    if (i == 0)
        printf("No data entered.");
    else
        printf("Here is the movie list:\n");

    for (j = 0; j < i; j++)
        printf("Movie: %s  Rating: %d\n", movies[j].title, movies[j].raing);

    puts("Bye!");

    return 0;
}

char * s_gets(char * st, int n) {
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);

    if (ret_val) {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}
