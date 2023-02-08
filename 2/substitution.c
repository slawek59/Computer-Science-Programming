#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check if argc == 2
    if (argc != 2)
    {
        printf("usage: ./substitution argv\n");
        return 1;
    }

    //check if argv (key) has 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("usage: ./substitution argv!!!\n");
        return 1;
    }

    //prepare arrays with uppercase and lowercase
    int y = 0;
    char upper[26];

    for (int x = 65; x < 91; x++)
    {
        upper[y] = x;
        y++;
    }

    y = 0;
    char lower[26];

    for (int x = 97; x < 123; x++)
    {
        lower[y] = x;
        y++;
    }

    //check if key has every letter from the alphabet

    int key26count = 0;
    int count = 0;

    for (int x = 0; x < 26; x++)
    {
        for (int z = 0; z < 26; z++)
        {

            if (upper[x] == argv[1][z] || lower[x] == argv[1][z])
            {
                count++;
            }
        }

        if (count == 1)
        {
            key26count++;
        }
        count = 0;
    }

    if (key26count != 26)
    {
        return 1;
    }

    //debug / check below
    //printf("%i \n", key26count);
    //printf("%c \n", argv[1][0]);

    //get plaintext

    string plaintext = get_string("plaintext: ");

    char arglow[strlen(argv[1])];
    char argup[strlen(argv[1])];

    //prepare arrays with keys; it will allow to pick lower or upper case letters

    for (int x = 0; x < strlen(argv[1]); x++)
    {
        argup[x] = toupper(argv[1][x]);

        arglow[x] = tolower(argv[1][x]);
    }

    //substitution

    char symbol_counter[(strlen(plaintext))];
    int x = 0;
    y = 0;

    for (x = 0; x < strlen(plaintext); x++)
    {
        int control = 0;
        y = 0;

        while (control == 0 && y < 26)
        {
            if (plaintext[x] == upper[y])
            {
                symbol_counter[x] = argup[y];
                control = 1;
            }
            else if (plaintext[x] == lower[y])
            {
                symbol_counter[x] = arglow[y];
                control = 1;
            }
            y++;

            if (control == 1)
            {
                y = 0;
            }
        }

        if (y == 26)
        {
            symbol_counter[x] = plaintext[x];
        }

    }

    //print the result
    printf("ciphertext: ");

    for (x = 0; x < strlen(plaintext); x++)
    {
        printf("%c", symbol_counter[x]);
    }

    printf("\n");
}
//Sławek