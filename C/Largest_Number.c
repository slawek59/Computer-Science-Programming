#include <stdio.h>

int main(void)
{
	int a, b, c;
	printf("Enter three numbers: \n");
	scanf("%i%i%i", &a, &b, &c);
	
	if (a < b)
	{
		if (b < c)
		{
			printf("Largest number is %i .\n", c);
		}
		else if (b > c)
		{
			printf("Largest number is %i .\n", b);
		}
	}
	else
	{
		printf("Largest number is %i .\n", a);
	}
	
	return 0;
}
//Sławek