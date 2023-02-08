#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//check-if-digit funct. prototypa
bool only_digits(string argv);

//rotate funct prototype
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //check if argc == 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) != true)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    //printf("%i\n", key);

    //get plaintext
    string plaintext = get_string("plaintext:  ");

    char ciphertext[strlen(plaintext)];

    printf("ciphertext: ");

    //call rotate func for every char
    for (int i = 0; i < strlen(plaintext); i++)
    {
        ciphertext[i] = rotate(plaintext[i], key);
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}

bool only_digits(string argv)
{
    int j = 0;
    for (int i = 0; i < strlen(argv); i++)
    {
        if (argv[i] >= 48 && argv[i] <=  57)
        {
            j++;
        }
        else
        {
            j = 0;
        }
    }

    if (j == strlen(argv))
    {
        return true;
    }
    else
    {
        return false;
    }
}

char rotate(char plaintext, int key)
{
    char cipher_char = '0';
    int y = 0;

    //check if upper-case letter
    if (plaintext >= 65 && plaintext <= 90)
    {
        //transpose ASCII into an array
        char upper_case_letters[26];

        for (int x = 65; x < 91; x++)
        {
            upper_case_letters[y] = x;
            y++;
        }


        //find upper_case_letter index for char plaintext
        int plaintext_index = 0;
        while (plaintext != upper_case_letters[plaintext_index])
        {
            plaintext_index++;
        }

        //rotate

        int value = (plaintext_index + key) % 26;
        cipher_char = upper_case_letters[value];

    }  //check if lower-case letter
    else if (plaintext >= 97 && plaintext <= 122)
    {
        //transpose ASCII into an array
        char lower_case_letters[26];

        for (int x = 97; x < 123; x++)
        {
            lower_case_letters[y] = x;
            y++;
        }

        //find lower_case_letter index for char plaintext
        int plaintext_index = 0;
        while (plaintext != lower_case_letters[plaintext_index])
        {
            plaintext_index++;
        }

        //rotate

        int value = (plaintext_index + key) % 26;
        cipher_char = lower_case_letters[value];
    }
    else
    {
        cipher_char = plaintext;
    }

    return cipher_char;
}
//Sławek