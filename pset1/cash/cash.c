#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float v;
    do
    {
        v = round(get_float("Value: ")*100);
    }
    while (v <= 0);

    int coins = 0;
    while (true)
    {
        if (v >= 25)
        {
            v -= 25;
            coins++;
        }
        else if (v >= 10)
        {
            v -= 10;
            coins++;
        }
        else if (v >= 5)
        {
            v -= 5;
            coins++;
        }
        else if (v >= 1)
        {
            v -= 1;
            coins++;
        }
        else
        {
            break;
        }
    }
    printf("Coins: %i\n", coins);
}