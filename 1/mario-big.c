#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n;
    int i;
    int j;
    int k;
    int l;
    int m;
    int o;
    int p;

    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (i = 0; i < n; i++)
    {
        for (j = n - i; j > 1; j--)
        {
            printf(" ");

        }

        for (k = n - 1; k < n; k++)
        {
            printf("#");

            for (l = n - i; l < n; l++)
            {
                printf("#");
            }
        }

        for (m = n - n; m == 0; m++)
        {
            printf("  ");
        }

        for (o = n - 1; o < n; o++)
        {
            printf("#");

            for (p = n - i; p < n; p++)
            {
                printf("#");
            }

        }

        printf("\n");

    }

}


