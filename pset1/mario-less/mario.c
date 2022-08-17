#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < h; c++)
        {
            if (r + c < h - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("\n");
    }
}