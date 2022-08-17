#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string t = get_string("Text: ");
    float l = 0;
    float s = 0;
    float w = 1;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if (isalpha(t[i]))
        {
            l++;
        }
        else if (isspace(t[i]))
        {
            w++;
        }
        else if (t[i] == 33 || t[i] == 46 || t[i] == 63)
        {
            s++;
        }
    }

    float L = (l / w) * 100;
    float S = (s / w) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}