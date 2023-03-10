// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    //set an initial counter
    int max = array[0];

    for (int i = 0; i < n; i++)
    {
        //compare initial counter number with other numbers
        //if other number is bigger than counter number
        //assign it to a counter --> new counter
        //if there is no bigger number than counter number
        //counter is the biggest number
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;


    return 0;
}
//Sławek


