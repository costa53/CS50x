#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Greet user
    string name = get_string("What's your name? \n");
    printf("Hello, %s \n", name);
}
