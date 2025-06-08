// The Colossus Airlines fleet consists of
// one plane with a seating capacity of 12.It makes one flight daily.
// Write a seating reservation program with the following features :
// a.The program uses an array of 12 structures.
// Each structure should hold a seat identification number,
// a marker that indicates whether the seat is assigned,
// the last name of the seat holder, and the first name of the seat holder.
// b.The program displays the following menu :
// To choose a function, enter its letter label :
// a) Show number of empty seats
// b) Show list of empty seats
// c) Show alphabetical list of seats
// d) Assign a customer to a seat assignment
// e) Delete a seat assignment
// f) Quit
// c.The program successfully executes the promises of its menu.
// Choices  d) and e)require additional input,
// and each should enable the user to abort an entry.
// d.After executing a particular function,
// the program shows the menu again, except for choice  f).
// e.Data is saved in a file between runs.When the program is restarted,
// it first loads in the data, if any, from the file.

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEATNUMBER 12
#define NAMELENGTH 41

typedef struct _SEAT_ {
    int IndentificationNumber;
    bool isAssigned;

    struct {
        char FirstName[NAMELENGTH];
        char LastName[NAMELENGTH];
    };
} seat;

int GetChoice(void);
void EatLine(void);
void InitSeats(seat st[], int n);
void ShowEmptySeatsList(const seat st[], int n);
void AssignNewCustomer(seat st[], int n);
void DeleteSeatAssignment(seat st[], int n);
void BeforeQuit(seat st[], int n);
void ShowAlphabeticalList(seat st[], int n);

static int EmptySeatNumber = SEATNUMBER;

int main(void) {
    seat Seats[SEATNUMBER];
    int choice = 0;

    InitSeats(Seats, SEATNUMBER);

    while (true) {
        choice = GetChoice();

        switch (choice) {
        case 'a':
            printf("Empty seats remains %d\n", EmptySeatNumber);
            break;
        case 'b':
            ShowEmptySeatsList(Seats, SEATNUMBER);
            break;
        case 'c':
            ShowAlphabeticalList(Seats, SEATNUMBER);
            break;
        case 'd':
            AssignNewCustomer(Seats, SEATNUMBER);
            break;
        case 'e':
            DeleteSeatAssignment(Seats, SEATNUMBER);
            break;
        case 'f':
            BeforeQuit(Seats, SEATNUMBER);
            return 0;
        }
        puts("Press [enter] to continue.");
        EatLine();
    }

    return 0;
}

int GetChoice(void) {
    int choice = 0;

    // put menu.
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");

    while (choice = getchar()) {
        EatLine();
        if (strchr("abcdef", choice) == NULL)
            puts("Please input the right choice.");
        else
            break;
    }

    return choice;
}

void EatLine(void) {
    while (getchar() != '\n')
        continue;
    return;
}

void InitSeats(seat st[], int n) {
    for (int i = 0; i < n; i++) {
        st[i].IndentificationNumber = i;
        st[i].isAssigned = false;
    }

    // read from file.
    FILE * fp;
    int seat_number;
    int index = 0;

    fp = fopen("./seat.data", "r");

    while (fscanf(fp, "%d", &seat_number) == 1) {
        fscanf(fp, "%s %s", st[seat_number].FirstName,
               st[seat_number].LastName);
        st[seat_number].isAssigned = true;
        EmptySeatNumber--;
    }

    fclose(fp); // close file.
}

void ShowEmptySeatsList(const seat st[], int n) {
    puts("Empty seats number:");

    for (int i = 0; i < n; i++)
        if (!st[i].isAssigned)
            printf("%d\n", st[i].IndentificationNumber);

    return;
}

void AssignNewCustomer(seat st[], int n) {
    int seat_number;

    puts("Please enter your seat number:");

    while (scanf("%d", &seat_number) == 1) {
        if (seat_number < 0 || seat_number >= SEATNUMBER) {
            printf("Please enter a number range from 1 to %d\n",
                   SEATNUMBER - 1);
            continue;
        }
        if (st[seat_number].isAssigned)
            printf("The %d seat had been assigned by "
                   "%s %s. Please choose another one.",
                   st[seat_number].IndentificationNumber,
                   st[seat_number].FirstName, st[seat_number].LastName);
        else {
            printf("The %d seat is vailable!\n",
                   st[seat_number].IndentificationNumber);
            st[seat_number].isAssigned = true;
            break;
        }
    }

    puts("Please enter your first name:");
    scanf("%s", st[seat_number].FirstName);
    puts("Please enter your last name:");
    scanf("%s", st[seat_number].LastName);

    puts("Assign successfully!");

    return;
}

void DeleteSeatAssignment(seat st[], int n) {
    int seat_number;
    puts("Please input your seat:");

    while (scanf("%d", &seat_number)) {
        if (seat_number < 0 || seat_number >= SEATNUMBER)
            printf("Please enter a number range from 1 to %d\n",
                   SEATNUMBER - 1);
        else if (!st[seat_number].isAssigned)
            puts("The seat have not been assigned!");
        else {
            st[seat_number].isAssigned = false;
            break;
        }
    }

    puts("Delete assignment successfully!");

    return;
}

void BeforeQuit(seat st[], int n) {
    FILE * fp;
    fp = fopen("./seat.data", "w");
    for (int i = 0; i < n; i++)
        if (st[i].isAssigned)
            fprintf(fp, "%d %s %s\n", st[i].IndentificationNumber,
                    st[i].FirstName, st[i].LastName);
    fclose(fp);

    return;
}

void ShowAlphabeticalList(seat st[], int n) {
    for (int i = 0; i < n; i++) {
        if (st[i].isAssigned)
            printf("%d: %s %s\n", st[i].IndentificationNumber, st[i].FirstName,
                   st[i].LastName);
        else
            printf("%d: Empty\n", i);
    }

    return;
}