#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    //ask for a message
    string message = get_string("Message: ");

    for (int i = 0; i < strlen(message); i++)
    {
        int x = message[i];
        //printf("%i\n", x);

        int a;

        //call an array and set its value
        int binary[8]  = {};

        for (int j = 0; j < 8; j++)
        {
            //check for remainder from dividing by 2 and pass 0 or 1 to the array
            if (x % 2 == 0)
            {
                binary[j] = 0;
            }
            else
            {
                binary[j] = 1;
            }
            x = x / 2;
            //printf("%i\n", x);
            //printf("%c", binary[j]);
        }

        //print elements from the array backwards and as a graphic representations
        for (int j = 7; j >= 0; j--)
        {
            //printf("%i", binary[j]);
            print_bulb(binary[j]);
        }
        printf("\n");
    }
}


void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
//Sławek