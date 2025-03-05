// Polar coordinates describe a vector in terms of magnitude
// and the counterclockwise angle from the x - axis to the vector.
// Rectangular coordinates describe the same vector
// in terms of x and y components.
// Write a program that reads the magnitude and angle(in degrees)
// of a vector and then displays the x and y components.
// The relevant equations are these :
// x = r cos A    y = r sin A
// To do the conversion, use a function that takes a structure
// containing the polar coordinates and returns a structure
// containing the
// rectangular coordinates(or use pointers to such structures, if you prefer).

#include <math.h>
#include <stdio.h>

typedef struct _POLAR_COORDINATE_
{
    double r, angle;
} polar_coordinate;

typedef struct _RECT_COORDINATE_
{
    double x, y;
} rect_coordinate;

rect_coordinate convert_polar_to_rect(const polar_coordinate * pc);
void            show_rect_coordinate(const rect_coordinate * rc);

int main(void)
{
    polar_coordinate user_input;
    rect_coordinate  output;

    puts("Please enter r and angle:");
    while (scanf("%lf %lf", &user_input.r, &user_input.angle) == 2)
    {
        output = convert_polar_to_rect(&user_input);
        show_rect_coordinate(&output);

        puts("Next group, please");
    }

    return 0;
}

rect_coordinate convert_polar_to_rect(const polar_coordinate * pc)
{
    rect_coordinate result;
    result.x = (double) pc->r * cos(pc->angle);
    result.y = (double) pc->r * sin(pc->angle);

    return result;
}

void show_rect_coordinate(const rect_coordinate * rc)
{
    printf("(x,y) = (%g, %g)\n", rc->x, rc->y);

    return;
}