#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LEN 81

char * s_gets(char * st, int n);
char showmenu(void);
void eatline(void);
void show(void (*fp)(char *), char * str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int main(void) {
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *);

    puts("Enter a string (empty line to quit):");

    while (s_gets(line, LEN) != NULL && line[0] != '\0') {
        while ((choice = showmenu()) != 'n') {
            switch (choice) {
            case 'u':
                pfun = ToUpper;
                break;
            case 'l':
                pfun = ToLower;
                break;
            case 't':
                pfun = Transpose;
                break;
            case 'o':
                pfun = Dummy;
                break;
            }

            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");

    return 0;
}

char showmenu(void) {
    char ans;
    puts("Enter menu choice:");
    puts("u) uppercase       l) lowercase");
    puts("t) transposed case o) original case");
    puts("n) next string");
    ans = getchar();
    ans = tolower(ans);
    eatline();

    while (strchr("ulton", ans) == NULL) {
        puts("Please enter a u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void eatline(void) {
    while (getchar() != '\n')
        continue;
    return;
}

void ToUpper(char * str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }

    return;
}

void ToLower(char * str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }

    return;
}

void Transpose(char * str) {
    while (*str) {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }

    return;
}

void Dummy(char * str) {
    // leaves string unchanged.
}

void show(void (*fp)(char *), char * str) {
    (*fp)(str);
    puts(str);

    return;
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