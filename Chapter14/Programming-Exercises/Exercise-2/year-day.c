// Write a program that prompts the user
// to enter the day, month, and year.
// The month can be a month number, a month name, or a month abbreviation.
// The program then should return
// the total number of days in the year up through the given day.
// (Do take leap years into account.)

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define LEN 21
#define MONTH 12

struct Month
{
    int  month_number;
    char month_all[LEN];
    char month_abbr[LEN];
    int  day;
};

int main(void)
{
    struct Month month[MONTH] = {
        {1, "January", "Jan", 31},   {2, "February", "Feb", 28},
        {3, "March", "Mar", 31},     {4, "April", "Apr", 30},
        {5, "May", "May", 31},       {6, "June", "Jun", 30},
        {7, "July", "Jul", 31},      {8, "August", "Aug", 31},
        {9, "September", "Sep", 30}, {10, "October", "Oct", 31},
        {11, "November", "Nov", 30}, {12, "December", "Dec", 31}};

    int  day;
    char user_month[LEN];
    int  month_num;
    int  year;
    int  result = 0;

    puts("Please enter the day:");
    scanf("%d", &day);
    puts("Please enter the month:");

    // check the input is right.
    while (scanf("%s", user_month) == 1)
    {
        bool correct = false;
        int  temp    = 0;

        if (isdigit(user_month[0])) // input is digit.
        {
            // string to number.
            for (int i = 0; i < strlen(user_month); i++)
            {
                if (!isdigit(user_month[i]))
                {
                    temp = -1;
                    break;
                }
                temp = 10 * temp + (user_month[i] - '0');
            }

            if (temp > 0 && temp <= 12)
                correct = true;
        }
        else // input is string.
        {
            for (int i = 0; i < MONTH; i++)
                if (strcmp(user_month, month[i].month_abbr) == 0 ||
                    strcmp(user_month, month[i].month_all) == 0)
                {
                    correct = true;
                    temp    = month[i].month_number;
                    break;
                }
        }

        // if the input is wrong.
        if (!correct)
        {
            puts("Please input the right month.");
            continue;
        }
        else
        {
            month_num = temp;
            break;
        }
    }

    puts("Please enter the year:");
    scanf("%d", &year);

    bool is_leap_year = !(year % 4);

    for (int i = 0; i < month_num - 1; i++) result += month[i].day;
    result += day;
    if (is_leap_year && month_num > 2)
        result += 1;

    printf("The total number of days in the year up through the given day is "
           "%d.\n",
           result);

    return 0;
}