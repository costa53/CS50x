#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else
    {
        for (int i = 0, c = strlen(argv[1]); i < c; i++)
        {
            if (c != 26)
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
            else if (!isalpha(argv[1][i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }

            for (int j = i + 1; j < strlen(argv[1]); j++)
            {
                if (toupper(argv[1][i]) == toupper(argv[1][j]))
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }

        string key = argv[1];

        for (int i = 0; i < strlen(key); i++)
        {
            if (islower(key[i]))
            {
                key[i] -= 32;
            }
        }

        string p = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0; i < strlen(p); i++)
        {
            if (isupper(p[i]))
            {
                int l = p[i] - 65;
                printf("%c", key[l]);
            }
            else if (islower(p[i]))
            {
                int l = p[i] - 97;
                printf("%c", key[l] + 32);
            }
            else
            {
                printf("%c", p[i]);
            }
        }

        printf("\n");
        return 0;
    }
}