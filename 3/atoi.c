#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int index = 0;

    if (input[index] == '\0')
    {
        return 0;
    }

    index = strlen(input) - 1;
    int num = input[index] - '0';
    input[index] = '\0';

    return num + 10 * convert(input);

}
//Sławek