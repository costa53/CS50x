#include <stdio.h>
#include <cs50.h>

long valid(void);
int count(long num);

int main(void)
{
    long n = valid();
    long c = count(n);
    if (c < 13 || c > 16)
    {
        printf("INVALID\n");
        return 0;
    }
    int even = 0;
    int cod = 0;
    int s1 = 0;
    int s2 = 0;
    while (n != 0)
    {
        int dig = n % 10;
        even++;
        if (even % 2 == 0)
        {
            dig *= 2;
            if (dig >= 10)
            {
                dig = (dig % 10) + 1;
            }
            s1 += dig;
        }
        else
        {
            s2 += dig;
        }

        if (n > 10 && n < 100)
        {
            if ((n >= 65 && n <= 69) && c == 16)
            {
                cod = 1;
            }
            else if ((n >= 51 && n <= 55) && c == 16)
            {
                cod = 2;
            }
            else if ((n >= 40 && n <= 49) && (c == 13 || c == 16))
            {
                cod = 3;
            }
            else if ((n == 34 || n == 37) && c == 15)
            {
                cod = 4;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
        n /= 10;
    }

    int sum = s1 + s2;
    if (sum % 10 == 0)
    {
        if (cod == 1)
        {
            printf("ELO\n");
        }
        else if (cod == 2)
        {
            printf("MASTERCARD\n");
        }
        else if (cod == 3)
        {
            printf("VISA\n");
        }
        else if (cod == 4)
        {
            printf("AMEX\n");
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

long valid(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 1);
    return number;
}

int count(long num)
{
    int c = 0;
    while (num != 0)
    {
        num /= 10;
        c++;
    }
    return c;
}