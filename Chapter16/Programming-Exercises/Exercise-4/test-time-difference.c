// Here, clock_t is a type defined in  time.h.
// The function returns the processor time,
// which is given in some implementation - dependent units.
// (If the processor time is unavailable or cannot be represented,
// the function returns a value of - 1.)
// However, CLOCKS_PER_SEC, also defined in  time.h,
// is the number of processor time units per second.
// Therefore, dividing the difference between two return values of
// clock() by CLOCKS_PER_SEC gives you the number of seconds elapsed between the
// two calls. Typecasting the values to  double before division enables you to
// get fractions of a second.Write a function that takes a  double argument
// representing a desired time delay and then runs a loop until that amount of
// time has passed. Write a simple program that tests the function.

#include <stdio.h>
#include <time.h>

void delay(double seconds) {
    clock_t start_time = clock();
    double elapsed_time;
    do {
        elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    } while (elapsed_time < seconds);
}

int main(void) {
    unsigned long long loop_time;

    while (scanf("%llu", &loop_time) == 1) {
        clock_t first_time = clock();

        // Use delay function to wait
        delay((double)loop_time /
              1000000); // Assuming loop_time is in microseconds

        clock_t next_time = clock();
        double time_difference =
            (double)(next_time - first_time) / CLOCKS_PER_SEC;

        printf("Time difference is %f seconds\n", time_difference);
    }

    return 0;
}
