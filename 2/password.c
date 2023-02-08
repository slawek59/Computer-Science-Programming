// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    //set checkpoints to false
    bool uppercase = false;
    bool lowercase = false;
    bool digit = false;
    bool punct = false;

    //iterate through the string
    for (int j = 0; j < strlen(password); j++)
    {
        //search for numbers, upper- and lowercase letters and puncts.
        if (isupper(password[j]))
        {
            uppercase = true;
        }
        if (islower(password[j]))
        {
            lowercase = true;
        }
        if (isdigit(password[j]))
        {
            digit = true;
        }
        if (ispunct(password[j]))
        {
            punct = true;
        }
    }

    //check if all conditions are met
    if (uppercase == 1 && lowercase == 1 && digit == 1 && punct == 1)
    {
        return true;
    }

    return false;
}
//Sławek