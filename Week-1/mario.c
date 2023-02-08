#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    int i;
    int j;
    int k;
    do
    {
        //ask for height
        n = get_int("Height: ");
    }   //ask long enough to get number bigger then 0 and smaller then 9
    while (n < 1 || n > 8);

    for (i = 0; i < n; i++)
    {

        for (k = n - i; k > 1; k--)

        {
            printf(" ");
        }   //j cannot be bigger then i
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("#");
        printf("\n");

    }
}