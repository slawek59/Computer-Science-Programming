// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    //add tax value to the bill = with_tax
    float with_tax = bill + bill * (tax / 100);

    //add tip value to with_tax
    float with_tip = with_tax + with_tax * (tip * 0.01);

    //divide by two clients
    float sum = with_tip / 2;

    //return sum
    return sum;
}

//Sławek
