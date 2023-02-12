// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Add your code here

    int swap = 0;

    //check if there is no swap in a "bubble sort run"
    do
    {
        swap = 0;
        //number of checks (you can't compare with temps[10] - it's 0)
        for (int i = 0; i < NUM_CITIES; i++)
        {
            //check if a pair is sorted
            if (temps[NUM_CITIES - i].temp > temps[NUM_CITIES - (i + 1)].temp)
            {
                avg_temp t1 = temps[NUM_CITIES - i];
                avg_temp t2 = temps[NUM_CITIES - (i + 1)];

                //change places
                temps[NUM_CITIES - i] = t2;
                temps[NUM_CITIES - (i + 1)] = t1;

                //add swap counter
                swap++;
            }
        }

    }
    while (swap > 0);
}
//Sławek