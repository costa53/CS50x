#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int start;
    int end;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    int y = 0;
    int inc;
    while (start < end)
    {
        inc = (start / 3) - (start / 4);
        y++;
        start += inc;
    }

    printf("Years: %i\n", y);
}