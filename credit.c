#include <cs50.h>
#include <stdio.h>

int main(void)

{
    long card_num;
    long slash = 1;
    long i;
    long j;
    long k = 10;
    long l = 1;
    long last_digit = 0;
    long digit = 0;
    long p = 0;
    long np = 0;
    long sum1 = 0;
    long sum2 = 0;
    long sum3 = 0;
    long digit2;
    long digit3;
    long digit4;
    long digit5;
    long mastercard1;
    long mastercard2;
    long amex1;
    long amex2;
    long visa1;
    long visa2;
    long visa3;
    long valid = 0;

    //get card number
    card_num = get_long("Number: ");
    printf("%li \n", card_num);

    //find last digit
    last_digit = card_num % k;
    printf("%li\n", last_digit);

    for (i = 1; i < 16; i++)
    {
        //find all digits
        k = k * 10;
        l = l * 10;
        digit = (card_num % k - last_digit) / l;
        printf("%li\n", digit);

        //check if digits stand for VISA, MASTERCARD OR AMEX number cards
        if (i == 13)
        {
            if (digit == 4 || digit == 7)
            {
                amex1 = 1;
                printf("amex1\n");
            }
        }

        if (i == 14)
        {

            if (digit == 1 || digit == 2 || digit == 3 || digit == 4 || digit == 5)
            {
                mastercard1 = 1;
                printf("mastercard1\n");
            }

            if (digit == 3)
            {
                amex2 = 1;
                printf("amex2\n");
            }

            else
            {
                visa1 = 1;
                printf("visa1\n");
            }

        }

        if (i == 12)
        {
            if (digit == 4)
            {
                visa3 = 1;
                printf("visa3\n");
            }
        }

        if (i == 15)
        {
            if (digit == 5)
            {
                mastercard2 = 1;
                printf("mastercard2\n");
            }
            else if (digit == 4)
            {
                visa2 = 1;
                printf("visa2\n");
            }
        }

        //add and multiply digits to check if adding digits makes number with 0 at the end
        if (i % 2 != 0)
        {
            if (digit <= 4)
            {
                digit4 = digit * 2;
            }

            if (digit >= 5)
            {
                digit5 = digit * 2;
                digit2 = digit5 / 10;
                digit3 = digit5 % 10;
            }
            sum1 = sum1 + digit4 + digit2 + digit3;
            //       printf("%li \n %li \n %li \n", digit4, digit2, digit3);
            digit2 = 0;
            digit3 = 0;
            digit4 = 0;

        }

        if (i % 2 == 0)
        {
            sum2 = sum2 + digit;
        }


    }
    sum3 = sum1 + sum2 + last_digit;
    printf("%li\n %li\n %li\n %li\n", sum1, sum2, last_digit, sum3);

    //check if added digits makes number with 0 at the end
    if (sum3 % 10 == 0)
    {
        valid = 1;
        printf("Działa\n");
    }

    //final check with all conditions checked
    //printing result
    if (valid == 1)
    {
        if (mastercard1 + mastercard2 == 2)
        {
            printf("MASTERCARD\n");
        }

        else if (amex1 + amex2 == 2)
        {
            printf("AMEX\n");
        }

        else if (visa1 + visa2 + visa3 == 2)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

}