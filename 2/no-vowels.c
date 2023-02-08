// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

//function declaration
string replace(string argv[1]);

//main
int main(int argc, string argv[])
{
    //checking if there is one command-line argument
    if (argc != 2)
    {
        printf("Błąd \n");
        return 1;
    }

    //print the result by calling the function
    printf("%s \n", replace(argv));
}

//function definition
string replace(string argv[1])
{
    string w = argv[1];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (w[i] == 'a' || w[i] == 'A')
        {
            w[i] = '6';
        }
        else if (w[i] == 'e' || w[i] == 'E')
        {
            w[i] = '3';
        }
        else if (w[i] == 'i' || w[i] == 'I')
        {
            w[i] = '1';
        }
        else if (w[i] == 'o' || w[i] == 'O')
        {
            w[i] = '0';
        }
        else
        {
            w[i] = w[i];
        }

    }
    return w;
}
